/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-15 18:05:13
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-23 09:40:58
 * @FilePath: \CODE\Peripheral\HOST\HOST.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _HOST_H_
#define _HOST_H_

#include "MM32_UART.h"
#include "P18_CTRL.h"
#include "MM32_UARTDMA.h"

/*上位机RX缓冲大小*/
#define HOST_RXSIZE (10)
/*上位机串口模块*/
#define HOST_UART (UART2)
/*示波器串口模块*/
#define SCOPE_UART (UART2)

extern uint8_t SCOPE_txBuffer[44];
extern uint8_t* SCOPE_dataPtr;

/**
 * @description: 上位机串口接收回调
 * @return {*}
 */
void HOST_uartReadCallBack(void);

void HOST_uartUploadDmaInit(void);

void HOST_uartUploadStart(void);

#endif