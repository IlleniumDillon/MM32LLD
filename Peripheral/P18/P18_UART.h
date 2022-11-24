#ifndef _P18_UART_H_
#define _P18_UART_H_

#include "common.h"
#include "P18_TYPEDEF.h"
#include <string.h>

/**
 * @description: 开启串口接收功能
 * @return {*}
 */
void P18_uartInit(void);

/**
 * @description: 发送指令
 * @param {uint8_t*} pack   指令包指针
 * @param {uint8_t} size    指令包字节数
 * @return {*}
 */
void P18_uartWrite(uint8_t* pack, uint8_t size);

/**
 * @description: P18串口接收回调
 * @return {*}
 */
void P18_uartReadCallBack(void);

/**
 * @description: 接收数据解码
 * @return {*}
 */
void P18_decode(void);

#endif