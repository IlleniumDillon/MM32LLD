/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 12:20:29
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-01 15:13:58
 * @FilePath: \CODE\MM32\mLLD\SDIO\MM32_SDIO.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_SDIO_H_
#define _MM32_SDIO_H_

#include "MM32_SDIOReg.h"
#include "MM32_DMAReg.h"

#include "MM32_GPIO.h"
#include "MM32_RCC.h"

typedef enum _MM32SDIO_Resp
{
    SDIO_RespType_R1, /*!< 32 bit + 8 bit CRC. */
    SDIO_RespType_R2, /*!< 128 bit + 8 bit CRC, for CID and CSD. */
    SDIO_RespType_R3, /*!< 32 bit + 8 bit CRC, for OCR. */
    SDIO_RespType_R6, /*!< 32 bit + 8 bit CRC, for RCA. */
    SDIO_RespType_R7, /*!< 32 bit + 8 bit CRC, for card interface condition. */
}MM32SDIO_Resp;

typedef enum _MM32SDIO_DataBusWidth
{
    SDIO_DataWidth_1B,
    SDIO_DataWidth_4B,
}MM32SDIO_DataBusWidth;

typedef enum _MM32SDIO_ClkSrc
{
    SDIO_ClkSrc_1MHz,
    SDIO_ClkSrc_BusClk,
}MM32SDIO_ClkSrc;

typedef enum _MM32SDIO_ClkDiv
{
    SDIO_ClkDiv2,
    SDIO_ClkDiv4,
    SDIO_ClkDiv6,
    SDIO_ClkDiv8,
    SDIO_ClkDiv10,
    SDIO_ClkDiv12,
    SDIO_ClkDiv14,
    SDIO_ClkDiv16,
}MM32SDIO_ClkDiv;

typedef enum _MM32SDIO_Status
{
    SDIO_STATUS_CMD_DONE = (1u << 0u),
    SDIO_STATUS_DAT_DONE = (1u << 1u),
    SDIO_STATUS_DAT_CRC_ERR = (1u << 2u),
    SDIO_STATUS_CMD_CRC_ERR = (1u << 3u),
    SDIO_STATUS_DAT_MULTI_BLOCKS_DONE = (1u << 4u),
    SDIO_STATUS_DAT_MULTI_BLOCKS_TIMEOUT = (1u << 5u),
    SDIO_STATUS_CMD_NCR_TIMEOUT = (1u << 6u),
    SDIO_STATUS_CRC_CRC_ERR = (1u << 7u),
    SDIO_STATUS_DAT0_BUSY = (1u << 8u),
    SDIO_STATUS_DAT_BUF_FULL = (1u << 9u),
    SDIO_STATUS_DAT_BUF_EMPTY = (1u << 10u),
}MM32SDIO_Status;

typedef enum _MM32SDIO_Int
{
    SDIO_INT_CMD_DONE = (1u << 0u),
    SDIO_INT_DAT_DONE = (1u << 1u),
    SDIO_INT_DAT_CRC_ERR = (1u << 2u),
    SDIO_INT_CMD_CRC_ERR = (1u << 3u),
    SDIO_INT_DAT_MULTI_BLOCKS_DONE = (1u << 4u),
    SDIO_INT_DAT_MULTI_BLOCKS_TIMEOUT = (1u << 5u),
    SDIO_INT_CMD_NCR_TIMEOUT = (1u << 6u),
    SDIO_INT_CRC_CRC_ERR = (1u << 7u),
    SDIO_INT_DAT0_BUSY = (1u << 8u),
}MM32SDIO_Int;

typedef enum _MM32SDIO_CmdFlag
{
    SDIO_CMD_FLAG_READ_BLOCK = (1u << 0u),
    SDIO_CMD_FLAG_WRITE_BLOCK = (1u << 1u),
    SDIO_CMD_FLAG_READ_CID_CSD = (1u << 2u),
    SDIO_CMD_FLAG_WRITE_BLOCKS = (1u << 5u),
    SDIO_CMD_FLAG_READ_BLOCKS = (1u << 6u),
    SDIO_CMD_FLAG_ENABLE_DATA_XFER = (1u << 7u),
}MM32SDIO_CmdFlag;

void MM32SDIO_init(void);

MM32SDIO_Status MM32SDIO_getStatus(void);

void MM32SDIO_clearStatus(MM32SDIO_Status status);

void MM32SDIO_executeCmd(uint8_t cmd, uint32_t param, MM32SDIO_CmdFlag flag);

void MM32SDIO_requestResp(MM32SDIO_Resp type, uint32_t* resp);

void MM32SDIO_PutFifoData(uint32_t dat);

uint32_t MM32SDIO_GetFifoData(void);

void MM32SDIO_ClearFifoData(void);

void MM32SDIO_SwitchFifoWrite(uint8_t write);

void MM32SDIO_SetFifoWatermark(uint32_t word_cnt);

void MM32SDIO_SetMultiBlockCount(uint32_t blk_cnt);

void MM32SDIO_EnableFifoReadWait(uint8_t enable);

void MM32SDIO_EnableFifoDMA(uint8_t enable);

#endif