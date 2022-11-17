/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-15 15:04:53
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-15 15:31:00
 * @FilePath: \CODE\MM32\mLLD\FLASH\MM32_FLASH.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_FLASH.h"

void MM32FLASH_erasePage(uint8_t pageNum)
{
    //等待上一次FLASH操作完成
    while(FLASH_SR->B.BSY == 1);
    
    //FLASH解锁
    FLASH_KEYR->U = FLASH_KEY1;
    FLASH_KEYR->U = FLASH_KEY2;
    
    //FLASH页擦除动作使能
    FLASH_CR->B.PER |= 1;
    //指定擦除位置
    FLASH_AR->U = (uint32_t)(DFLASH_START + DFLASH_PAGE_SIZE * pageNum);
    //FLASH开始擦除
    FLASH_CR->B.STRT |= 1;
    
    //等待FLASH操作完成
    while(FLASH_SR->B.BSY == 1);
    
    //FLASH页擦除动作禁用
    FLASH_CR->B.PER &= 0;
    
    //FLASH锁
    FLASH_CR->B.LOCK |= 1;
}

void MM32FLASH_readPage(uint8_t pageNum, void* buf)
{
    //等待上一次FLASH操作完成
    while(FLASH_SR->B.BSY == 1);
    //复制FLASH内容到内存
    memcpy(buf,(void*)(DFLASH_START + DFLASH_PAGE_SIZE * pageNum),1024);  
}

void MM32FLASH_writePage(uint8_t pageNum, void* buf)
{
    uint16_t* ptr = (uint16_t*)buf;
    uint16_t* flashptr = (uint16_t*)(DFLASH_START + DFLASH_PAGE_SIZE * pageNum);
    //等待上一次FLASH操作完成
    while(FLASH_SR->B.BSY == 1);
    
    //FLASH解锁
    FLASH_KEYR->U = FLASH_KEY1;
    FLASH_KEYR->U = FLASH_KEY2;
    
    for(size_t i = 0; i < 512; i++)
    {
        //FLASH编程动作使能
        FLASH_CR->B.PG |= 1;
        //向指定地址写入
        *flashptr = ptr[i];
        flashptr++;
        //等待FLASH操作完成
        while(FLASH_SR->B.BSY == 1);
    }

    //FLASH编程动作禁止
    FLASH_CR->B.PG &= 0;
    
    //FLASH锁
    FLASH_CR->B.LOCK |= 1;
}