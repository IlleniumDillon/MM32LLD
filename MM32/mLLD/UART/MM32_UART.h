/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 12:32:45
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:06:45
 * @FilePath: \CODE\MM32\mLLD\UART\MM32_UART.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_UART_H_
#define _MM32_UART_H_

#include "MM32_UARTReg.h"

#include "MM32_GPIO.h"
#include "MM32_RCC.h"

#include "MM32_UARTPinMap.h"

typedef enum _MM32UART_Moudle
{
    UART1 = UART1_BASE,
    UART2 = UART2_BASE,
    UART3 = UART3_BASE,
    UART4 = UART4_BASE,
    UART5 = UART5_BASE,
    UART6 = UART6_BASE,
    UART7 = UART7_BASE,
    UART8 = UART8_BASE,
}MM32UART_Moudle;

typedef struct _MM32UART_TXPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_TXPin;

typedef struct _MM32UART_RXPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_RXPin;

typedef struct _MM32UART_CTSPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_CTSPin;

typedef struct _MM32UART_RTSPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_RTSPin;

void MM32UART_moudleInit(MM32UART_TXPin* txpin, MM32UART_RXPin* rxpin, MM32UART_CTSPin* ctspin, MM32UART_RTSPin* rtspin, uint32_t baud);

void MM32UART_write8(MM32UART_Moudle moudle, uint8_t* pdata);

void MM32UART_read8(MM32UART_Moudle moudle, uint8_t* pdata);

void MM32UART_writeBlocking(MM32UART_Moudle moudle, void* pdata, size_t size);

void MM32UART_readBlocking(MM32UART_Moudle moudle, void* pdata, size_t size);

#endif