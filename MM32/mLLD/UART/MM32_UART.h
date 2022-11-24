/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 12:32:45
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 20:49:53
 * @FilePath: \CODE\MM32\mLLD\UART\MM32_UART.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_UART_H_
#define _MM32_UART_H_

#include "MM32_UARTReg.h"

#include "MM32_GPIO.h"
#include "MM32_RCC.h"

#include "MM32_UARTPinMap.h"

/**
 * @brief UART模块枚举
 */
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

/**
 * @brief UART TX引脚
 */
typedef struct _MM32UART_TXPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_TXPin;

/**
 * @brief UART RX引脚
 */
typedef struct _MM32UART_RXPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_RXPin;

/**
 * @brief UART CTS引脚
 */
typedef struct _MM32UART_CTSPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_CTSPin;

/**
 * @brief UART RTS引脚
 */
typedef struct _MM32UART_RTSPin
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32UART_Moudle moudle;
}MM32UART_RTSPin;

/**
 * @description: 初始化UART模块
 * @param {MM32UART_TXPin*} txpin   TX引脚结构体指针
 * @param {MM32UART_RXPin*} rxpin   RX引脚结构体指针
 * @param {MM32UART_CTSPin*} ctspin CTS引脚结构体指针
 * @param {MM32UART_RTSPin*} rtspin RTS引脚结构体指针
 * @param {uint32_t} baud   波特率
 * @return {*}
 * @example
 * \code
 *      MM32UART_moudleInit(&txpin,&rxpin,NULL,NULL,115200);
 * \endcode
 */
void MM32UART_moudleInit(MM32UART_TXPin* txpin, MM32UART_RXPin* rxpin, MM32UART_CTSPin* ctspin, MM32UART_RTSPin* rtspin, uint32_t baud);

/**
 * @description: 传输一个字节
 * @param {MM32UART_Moudle} moudle  UART模块
 * @param {uint8_t*} pdata  传输的数据指针
 * @return {*}
 * @example
 * \code
 *      uint8_t data = 0x5a;
 *      MM32UART_write8(UART1,&data);
 * \endcode
 */
void MM32UART_write8(MM32UART_Moudle moudle, uint8_t* pdata);

/**
 * @description: 接收一个字节
 * @param {MM32UART_Moudle} moudle  UART模块
 * @param {uint8_t*} pdata  接收数据的指针
 * @return {*}
 * @example
 * \code
 *      uint8_t data;
 *      MM32UART_read8(UART1,&data);
 * \endcode
 */
void MM32UART_read8(MM32UART_Moudle moudle, uint8_t* pdata);

/**
 * @description: 传输数据块
 * @param {MM32UART_Moudle} moudle  UART模块
 * @param {void*} pdata 传输数据的指针
 * @param {size_t} size 数据的字节数
 * @return {*}
 * @example
 * \code
 *      uint8_t data[1024] = {0};
 *      MM32UART_writeBlocking(UART1,data,1024);
 * \endcode
 */
void MM32UART_writeBlocking(MM32UART_Moudle moudle, void* pdata, size_t size);

/**
 * @description: 接收数据块
 * @param {MM32UART_Moudle} moudle  UART模块
 * @param {void*} pdata 接收数据的指针
 * @param {size_t} size 数据的字节数
 * @return {*}
 * @example
 * \code
 *      uint8_t data[1024] = {0};
 *      MM32UART_readBlocking(UART1,data,1024);
 * \endcode
 */
void MM32UART_readBlocking(MM32UART_Moudle moudle, void* pdata, size_t size);

#endif