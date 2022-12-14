/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-13 13:39:45
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 16:08:21
 * @FilePath: \CODE\MM32\mLLD\UART\MM32_UARTDMA.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_UARTDMA_H_
#define _MM32_UARTDMA_H_

#include "MM32_UART.h"
#include "MM32_DMAReg.h"
#include "common.h"

/**
 * @description: 初始化UART DMA模块
 * @param {MM32UART_TXPin*} txpin  tx引脚配置结构体指针
 * @param {MM32UART_RXPin*} rxpin  rx引脚配置结构体指针
 * @param {MM32UART_CTSPin*} ctspin  cts引脚配置结构体指针
 * @param {MM32UART_RTSPin*} rtspin  rts引脚配置结构体指针
 * @param {uint32_t} baud   波特率
 * @return {*}
 * @example
 * \code
 *      MM32UARTDMA_moudleInit(&Tx,&Rx,NULL,NULL,115200);
 * \endcode
 */
void MM32UARTDMA_moudleInit(MM32UART_TXPin* txpin, MM32UART_RXPin* rxpin, MM32UART_CTSPin* ctspin, MM32UART_RTSPin* rtspin, uint32_t baud);

/**
 * @description: 开始TX DMA传输
 * @param {MM32UART_Moudle} moudle  UART模块
 * @param {void*} txBuffer  发送缓冲区
 * @param {uint16_t} txSize  传输字节数
 * @return {*}
 * @example
 * \code
 *      MM32UARTDMA_startTXDMA(UART1,txBuffer,txSize);
 * \endcode
 */
void MM32UARTDMA_startTXDMA(MM32UART_Moudle moudle, void* txBuffer, uint16_t txSize);

/**
 * @description: 开始RX DMA传输
 * @param {MM32UART_Moudle} moudle  UART模块
 * @param {void*} rxBuffer  接收缓冲区
 * @param {uint16_t} rxSize  接收字节数
 * @return {*}
 * @example
 * \code
 *      MM32UARTDMA_startRXDMA(UART1,rxBuffer,rxSize);
 * \endcode
 */
void MM32UARTDMA_startRXDMA(MM32UART_Moudle moudle, void* rxBuffer, uint16_t rxSize);

#endif