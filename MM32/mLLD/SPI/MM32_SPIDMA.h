/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-12 21:33:58
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 15:36:27
 * @FilePath: \CODE\MM32\mLLD\SPI\MM32_SPIDMA.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_SPIDMA_H_
#define _MM32_SPIDMA_H_

#include "MM32_SPI.h"
#include "MM32_DMAReg.h"
#include "common.h"

#define SPIDMA_BUFFERSIZE (128)

/**
 * @description: 初始化SPI DMA模块
 * @param {MM32SPI_Pin_SCLK*} sclk  sclk引脚配置结构体指针
 * @param {MM32SPI_Pin_MOSI*} mosi  mosi引脚配置结构体指针
 * @param {MM32SPI_Pin_MISO*} miso  miso引脚配置结构体指针
 * @param {MM32SPI_Pin_CS*} cs  cs引脚配置结构体指针
 * @param {uint32_t} baud   时钟频率
 * @param {MM32SPI_Mode} mode   工作模式
 * @return {*}
 * @example
 * \code
 *      MM32SPIDMA_moudleInit(&SCLK,&MOSI,NULL,&CS,1000000,MODE2);
 * \endcode
 */
void MM32SPIDMA_moudleInit(MM32SPI_Pin_SCLK* sclk, MM32SPI_Pin_MOSI* mosi, MM32SPI_Pin_MISO* miso, MM32SPI_Pin_CS* cs,
                        uint32_t baud, MM32SPI_Mode mode);

/**
 * @description: 开始SPI DMA传输
 * @param {MM32SPI_Moudle} moudle  SPI模块
 * @param {void*} txBuffer  发送存储区地址
 * @param {void*} rxBuffer  接收存储区地址
 * @param {uint16_t} txSize  发送字节数
 * @param {uint16_t} rxSize   接收字节数
 * @return {*}
 * @todo 如果指针传入NULL，使用默认的Buffer
 * @todo 要检查传输完毕才能退出函数，避免访问释放掉的内存空间
 * @example
 * \code
 *      MM32SPIDMA_startDMA(SPI1,txBuffer,NULL,10,0);
 * \endcode
 */
void MM32SPIDMA_startDMA(MM32SPI_Moudle moudle, void* txBuffer, void* rxBuffer, uint16_t txSize, uint16_t rxSize);

#endif