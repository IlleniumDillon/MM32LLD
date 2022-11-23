/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-15 15:04:43
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 14:51:27
 * @FilePath: \CODE\MM32\mLLD\FLASH\MM32_FLASH.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_FLASH_H_
#define _MM32_FLASH_H_

#include "MM32_FLASHReg.h"
#include <string.h>

/*数据FLASH起始地址*/
#define DFLASH_START (0x0807F000)
/*数据FLASH空间*/
#define DFLASH_SIZE (0x1000)
/*数据FLASH页的大小*/
#define DFLASH_PAGE_SIZE (0x400)
/*数据FLASH页数*/
#define DFLASH_PAGE_NUM (DFLASH_SIZE/DFLASH_PAGE_SIZE)

/*FLASH解锁口令*/
#define FLASH_KEY1               ((uint32_t)0x45670123)
#define FLASH_KEY2               ((uint32_t)0xCDEF89AB)

/**
 * @description: 擦除DFLASH的一页
 * @param {uint8_t} pageNum 要擦除的页号
 * @return {*}
 * @example
 * \code
 *      //擦除0页
 *      MM32FLASH_erasePage(0);
 * \endcode
 */
void MM32FLASH_erasePage(uint8_t pageNum);

/**
 * @description: 读DFLASH整页数据
 * @param {uint8_t} pageNum 页号
 * @param {void*} buf   内存空间指针
 * @return {*}
 * @example
 * \code
 *      //从0页中读取1024字节
 *      uint8_t data[1024];
 *      MM32FLASH_readPage(0,data);
 * \endcode
 */
void MM32FLASH_readPage(uint8_t pageNum, void* buf);

/**
 * @description: 写入DFLASH整页数据
 * @param {uint8_t} pageNum 页号
 * @param {void*} buf   内存空间指针
 * @return {*}
 * @note 在写入之前一定要先擦除对应页
 * @example
 * \code
 *      //向0页中写入1024字节
 *      uint8_t data[1024] = 0;
 *      MM32FLASH_erasePage(0);
 *      MM32FLASH_writePage(0,data);
 * \endcode
 */
void MM32FLASH_writePage(uint8_t pageNum, void* buf);

#endif