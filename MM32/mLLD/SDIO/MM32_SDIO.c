/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 12:20:37
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-01 19:40:41
 * @FilePath: \CODE\MM32\mLLD\SDIO\MM32_SDIO.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_SDIO.h"

void MM32SDIO_init(void)
{
    MM32RCC_enableSDIO();
    MM32GPIO_setAFPinConfig(GPIOC,P08,AF_PUSHPULL,AF12);
    MM32GPIO_setAFPinConfig(GPIOC,P09,AF_PUSHPULL,AF12);
    MM32GPIO_setAFPinConfig(GPIOC,P10,AF_PUSHPULL,AF12);
    MM32GPIO_setAFPinConfig(GPIOC,P11,AF_PUSHPULL,AF12);
    MM32GPIO_setAFPinConfig(GPIOC,P12,AF_PUSHPULL,AF12);
    MM32GPIO_setAFPinConfig(GPIOD,P02,AF_PUSHPULL,AF12);

    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;

    moudle->CTRL.B.OPMSEL = 1;
    moudle->CTRL.B.SELSM = 1;
    moudle->CTRL.B.OUTM = 0;
    moudle->CTRL.B.CLKSP = 1;
    moudle->CTRL.B.SELPTSM = 0;//low speed
    moudle->CTRL.B.DATWT = 0;
    moudle->CTRL.B.MDEN = 0;
    moudle->CTRL.B.INTEN = 0;
    moudle->CTRL.B.RDWTEN = 0;

    moudle->CTRL.B.SELSM = 1;

    extern unsigned int SystemCoreClock;
    uint32_t div = SystemCoreClock / 1000000 / 2 - 1u;
    moudle->CARDSEL.B.TSCALE = div;

    moudle->INTEN.U = 0x1F;

    moudle->CTRL.B.DATWT = 1;

    /*moudle->CRCCTL.B.CMD_CRCEN = 1;
    moudle->CRCCTL.B.DAT_CRCEN = 1;*/
    
    moudle->CARDSEL.B.CTREN = 1;
    moudle->CARDSEL.B.ENPCLK = 1;
}

MM32SDIO_Status MM32SDIO_getStatus(void)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    MM32SDIO_Status flags = moudle->INTSTA.U;

    if(moudle->BUFCTL.B.DBF)
    {
        flags |= SDIO_STATUS_DAT_BUF_FULL;
    }
    if(moudle->BUFCTL.B.DBE)
    {
        flags |= SDIO_STATUS_DAT_BUF_EMPTY;
    }

    return flags;
}

void MM32SDIO_clearStatus(MM32SDIO_Status status)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    moudle->INTSTA.U = (SDIO_STATUS_DAT0_BUSY - 1u) & status;
}

void MM32SDIO_executeCmd(uint8_t cmd, uint32_t param, MM32SDIO_CmdFlag flag)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    moudle->CMDBUF4.B.DAT = 0x40 | cmd;
    moudle->CMDBUF3.B.DAT = ((param & 0xff000000) >> 24);
    moudle->CMDBUF2.B.DAT = ((param & 0x00ff0000) >> 16);
    moudle->CMDBUF1.B.DAT = ((param & 0x0000ff00) >> 8);
    moudle->CMDBUF0.B.DAT = ((param & 0x000000ff));

    moudle->IOMBCTL.U = 0;
    moudle->IO.U = 0;

    MM32_SDIO_IO io = {0};
    MM32_SDIO_IOMBCTL iombctl = moudle->IOMBCTL;
    io.B.AUTOTR = 1;
    iombctl.B.SPMBDTR = 0;
    iombctl.B.SMBDTD = 0;
    iombctl.B.PAUTOTR = 0;
    moudle->IO.B.AUTOTR = 1;

    if(flag & (SDIO_CMD_FLAG_READ_BLOCKS | SDIO_CMD_FLAG_WRITE_BLOCKS))
    {
        if(flag & SDIO_CMD_FLAG_READ_BLOCKS)
        {
            iombctl.B.SMBDTD = 1;
        }
        iombctl.B.SPMBDTR = 1;
        moudle->IO.U = 0;
        moudle->IOMBCTL= iombctl;
    }
    else
    {
        if(flag & SDIO_CMD_FLAG_READ_BLOCK)
        {
            io.B.TRANSFDIR = 1;
        }
        if(flag & SDIO_CMD_FLAG_READ_CID_CSD)
        {
            io.B.CID_CSDRD = 1;
        }
        if(flag & SDIO_CMD_FLAG_ENABLE_DATA_XFER)
        {
            io.B.AUTODATTR = 1;
        }
        moudle->IOMBCTL.U = iombctl.U;
        moudle->IO.U = io.U;
        //moudle->IO.B.AUTOTR = 1;
        
    }
    iombctl = moudle->IOMBCTL;
    io = moudle->IO;
    while(0==(SDIO_STATUS_CMD_DONE & MM32SDIO_getStatus()));
    MM32SDIO_clearStatus(SDIO_STATUS_CMD_DONE);
}

void MM32SDIO_executeData(MM32SDIO_CmdFlag flag)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    MM32_SDIO_IO io = {0};
    MM32_SDIO_IOMBCTL iombctl = moudle->IOMBCTL;

    if(flag & SDIO_CMD_FLAG_WRITE_BLOCK)
    {
        io.B.AUTODATTR = 1;
    }
    if(flag & SDIO_CMD_FLAG_WRITE_BLOCK)
    {
        io.B.AUTODATTR = 1;
        io.B.TRANSFDIR = 1;
    }
    if(flag & SDIO_CMD_FLAG_WRITE_BLOCK)
    {
        iombctl.B.SPMBDTR = 1;
    }
    if(flag & SDIO_CMD_FLAG_WRITE_BLOCK)
    {
        iombctl.B.SPMBDTR = 1;
        iombctl.B.SMBDTD = 1;
    }
    moudle->IO = io;
    moudle->IOMBCTL= iombctl;
}

void MM32SDIO_requestResp(MM32SDIO_Resp type, uint32_t* resp)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    MM32_SDIO_IO io = {0};
    io.B.AUTOTR = 1;
    io.B.RESPCMDSEL = 1;

    if(type == SDIO_RespType_R2)
    {
        io.B.CID_CSDRD = 1;
    }
    moudle->IO = io;

    while(0==(SDIO_STATUS_CMD_DONE & MM32SDIO_getStatus()));
    MM32SDIO_clearStatus(SDIO_STATUS_CMD_DONE | SDIO_STATUS_CMD_CRC_ERR);

    *resp = (moudle->CMDBUF3.B.DAT << 24)
          | (moudle->CMDBUF2.B.DAT << 16)
          | (moudle->CMDBUF1.B.DAT << 8 )
          | (moudle->CMDBUF0.B.DAT);

    if (type == SDIO_RespType_R2)
    {
        resp++;
        *resp = (moudle->CMDBUF7.B.DAT << 24)
              | (moudle->CMDBUF6.B.DAT << 16)
              | (moudle->CMDBUF5.B.DAT << 8 )
              | (moudle->CMDBUF4.B.DAT);
        resp++;
        *resp = (moudle->CMDBUF11.B.DAT << 24)
              | (moudle->CMDBUF10.B.DAT << 16)
              | (moudle->CMDBUF9.B.DAT << 8 )
              | (moudle->CMDBUF8.B.DAT);
        resp++;
        *resp = (moudle->CMDBUF15.B.DAT << 24)
              | (moudle->CMDBUF14.B.DAT << 16)
              | (moudle->CMDBUF13.B.DAT << 8 )
              | (moudle->CMDBUF12.B.DAT);
    }
}

void MM32SDIO_PutFifoData(uint32_t dat)
{
    SDIO_DATABUF[0] = dat;
}

uint32_t MM32SDIO_GetFifoData(void)
{
    return SDIO_DATABUF[0];
}

void MM32SDIO_ClearFifoData(void)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    moudle->BUFCTL.B.DBFEN = 1;
}

void MM32SDIO_SwitchFifoWrite(uint8_t write)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    if (write)
    {
        moudle->BUFCTL.B.SBAD = 1;
    }
    else
    {
        moudle->BUFCTL.B.SBAD = 0;
    }
}

void MM32SDIO_SetFifoWatermark(uint32_t word_cnt)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    moudle->BUFCTL.B.DBML = 0;
    moudle->BUFCTL.B.DBML = word_cnt;
}

void MM32SDIO_SetMultiBlockCount(uint32_t blk_cnt)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    moudle->BLOCKCNT.B.BCNT = blk_cnt;
}

void MM32SDIO_EnableFifoReadWait(uint8_t enable)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    if (enable)
    {
        moudle->CTRL.B.RDWTEN = 1;
    }
    else
    {
        moudle->CTRL.B.RDWTEN = 0;
    }
}

void MM32SDIO_EnableFifoDMA(uint8_t enable)
{
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    MM32_SDIO_BUFCTL bufctl = moudle->BUFCTL;

    bufctl.B.DRM = 0;
    bufctl.B.DMAHEN = 0;

    if (enable)
    {
        bufctl.B.DMAHEN = 1;
    }
    else
    {
        bufctl.B.DRM = 1;
    }
    moudle->BUFCTL = bufctl;
}