/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-15 15:04:43
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-15 15:15:59
 * @FilePath: \CODE\MM32\mLLD\FLASH\MM32_FLASH.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_FLASH_H_
#define _MM32_FLASH_H_

#include "MM32_FLASHReg.h"
#include <string.h>

#define DFLASH_START (0x0807F000)
#define DFLASH_SIZE (0x1000)
#define DFLASH_PAGE_SIZE (0x400)
#define DFLASH_PAGE_NUM (DFLASH_SIZE/DFLASH_PAGE_SIZE)

#define FLASH_KEY1               ((uint32_t)0x45670123)
#define FLASH_KEY2               ((uint32_t)0xCDEF89AB)

void MM32FLASH_erasePage(uint8_t pageNum);
void MM32FLASH_readPage(uint8_t pageNum, void* buf);
void MM32FLASH_writePage(uint8_t pageNum, void* buf);

#endif