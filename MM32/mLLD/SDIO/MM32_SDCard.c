/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 15:21:34
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-01 16:30:10
 * @FilePath: \CODE\MM32\mLLD\SDIO\MM32_SDCard.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_SDCard.h"

#define SDCARD_RESP_BUF_LEN 4u
static uint32_t sdcard_resp_buf[SDCARD_RESP_BUF_LEN];

uint8_t MM32SD_init(MM32_SDCard* card)
{
    MM32SDIO_init();

    for (uint32_t i = 0u; i < 74; i++)
    {
        MM32SDIO_executeCmd(0, 0, 0);
    }

    while (1)
    {
        MM32SDIO_executeCmd(8, 0x1AA, 0);
        MM32SDIO_requestResp(SDIO_RespType_R7, sdcard_resp_buf);

        if (sdcard_resp_buf[0] == 0x1AA)
        {
            break; /* init done. */
        }
    }

    /* cmd55 + acmd41. */
    while (1)
    {
        /* cmd55. */
        MM32SDIO_executeCmd(55, 0, 0);
        MM32SDIO_requestResp(SDIO_RespType_R1, sdcard_resp_buf);
        

        /* acmd41. */
        MM32SDIO_executeCmd(41, 0xC0100000, 0);
        MM32SDIO_requestResp(SDIO_RespType_R3, sdcard_resp_buf);

        if ( 0u != ( sdcard_resp_buf[0] & (1u << 30)) )
        {
            card->cardtype = SDHC;
        }
        else
        {
            card->cardtype = SDSC;
        }

        if ( 0u != ( sdcard_resp_buf[0] & (1u << 31)) )
        {
            break;
        }
    }

    /* cmd2. ALL_SEND_CID. Card Identification Number, card individual number for identification.*/
    MM32SDIO_executeCmd(2, 0, 0);
    MM32SDIO_requestResp(SDIO_RespType_R2, sdcard_resp_buf);

    /* cmd3. SEND_RELATIVE_ADDR. Ask the card to publish a new relative address (RCA). */
    MM32SDIO_executeCmd(3, 0, 0);
    MM32SDIO_requestResp(SDIO_RespType_R6, sdcard_resp_buf);

    card->rca = sdcard_resp_buf[0] >> 16u;

    /* cmd9 + RCA -> CSD. SEND_CSD. Addressed card sends its card-specific data (CSD) on the cmd line. */
    MM32SDIO_executeCmd(9, card->rca << 16u, 0);
    MM32SDIO_requestResp(SDIO_RespType_R2, sdcard_resp_buf);

    if (((sdcard_resp_buf[3] >> 22) & 0x3) == 0x1) /* CSD in version 2.0 */
    {
        uint32_t c_size = (sdcard_resp_buf[1] >> 8) & 0x3fffff; /* memory capacity = (C_SIZE+1) * 512K byte. */
        card->block_cnt = c_size << 10u; /* when the block size is 512. */
        card->block_len = (1u << 9u);
    }
    else if (((sdcard_resp_buf[3] >> 22) & 0x3) == 0x0) /* CSD in version 1.0 */
    {
        uint32_t c_size = (sdcard_resp_buf[1] >> 22) | ((sdcard_resp_buf[2] & 0x3) << 10);
        uint32_t c_size_mult = ((sdcard_resp_buf[1] >> 7) & 0x7);
        uint32_t block_len = (sdcard_resp_buf[2] >> 6) & 0xf;

        card->block_cnt = (c_size + 1) << (c_size_mult + 2);
        card->block_len = block_len;
    }

    /* cmd13 Send card status. check if the card is switched to stand-by status.  */
    while (1)
    {
        MM32SDIO_executeCmd(13, card->rca << 16u, 0);
        MM32SDIO_requestResp(SDIO_RespType_R1, sdcard_resp_buf);

        uint32_t current_status = (sdcard_resp_buf[0] >> 9)  & 0xf;
        uint32_t error_status   = (sdcard_resp_buf[0] >> 19) & 0x1;

        if ( (current_status == 3) || (error_status == 1) )
        {
            if (current_status == 3) /* stand-by status. */
            {
                //printf("standby.\r\n");
            }
            if (error_status == 1)
            {
                //printf("error.\r\n");
            }
            break;
        }
    }

    /* cmd4. setup the card freq. */


    /* cmd7. assert or deassert the card with RCA. */
    MM32SDIO_executeCmd(7, card->rca << 16u, 0);
    MM32SDIO_requestResp(SDIO_RespType_R1, sdcard_resp_buf);

    /* cmd13. send card status. check if the card is switched to tran mode. */
    while (1)
    {
        MM32SDIO_executeCmd(13, card->rca << 16u, 0);
        MM32SDIO_requestResp(SDIO_RespType_R1, sdcard_resp_buf);

        uint32_t current_status = (sdcard_resp_buf[0] >> 9)  & 0xf;
        uint32_t error_status   = (sdcard_resp_buf[0] >> 19) & 0x1;

        if ( (current_status == 4) || (error_status == 1) )
        {
            if (current_status == 4) /* tran mode. */
            {
                //printf("tran.\r\n");
            }
            if (error_status == 1)
            {
                //printf("error.\r\n");
            }
            break;
        }
    }

    /* cmd55 + acmd6. setup card data bus width. */
    MM32SDIO_executeCmd(55, card->rca << 16, 0);
    MM32SDIO_requestResp(SDIO_RespType_R1, sdcard_resp_buf);

    MM32SDIO_executeCmd(6, 0x2, 0); /* 4-bit. */
    MM32SDIO_requestResp(SDIO_RespType_R1, sdcard_resp_buf);

    //SDIO_SetDataBusWidth(card->iodev, SDIO_DataBusWidth_4b);
    MM32_SDIO* moudle = (MM32_SDIO*)SDIO_BASE;
    moudle->CTRL.B.DATWT = 1;
    return 1;
}