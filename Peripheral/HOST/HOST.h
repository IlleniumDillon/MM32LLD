/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-15 18:05:13
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 21:09:52
 * @FilePath: \CODE\Peripheral\HOST\HOST.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _HOST_H_
#define _HOST_H_

#include "MM32_UART.h"
#include "P18_CTRL.h"

/*上位机RX缓冲大小*/
#define HOST_RXSIZE (10)
/*上位机串口模块*/
#define HOST_UART (UART2)

/**
 * @description: 上位机串口接收回调
 * @return {*}
 */
void HOST_uartReadCallBack(void);

#endif