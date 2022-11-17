/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 15:21:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-01 15:25:00
 * @FilePath: \CODE\MM32\mLLD\SDIO\MM32_SDCard.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_SDCARD_H_
#define _MM32_SDCARD_H_

#include "MM32_SDIO.h"

typedef enum _MM32_SDCardType
{
    SDSC,
    SDHC,
    SDXC,
}MM32_SDCardType;

typedef struct _MM32_SDCard
{
    MM32_SDCardType cardtype;
    uint32_t block_cnt;
    uint32_t block_len;
    uint32_t rca;
}MM32_SDCard;

uint8_t MM32SD_init(MM32_SDCard* card);

#endif