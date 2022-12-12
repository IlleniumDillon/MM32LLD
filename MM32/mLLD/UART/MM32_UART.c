/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 12:32:55
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 20:57:58
 * @FilePath: \CODE\MM32\mLLD\UART\MM32_UART.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_UART.h"

void MM32UART_moudleInit(MM32UART_TXPin* txpin, MM32UART_RXPin* rxpin, MM32UART_CTSPin* ctspin, MM32UART_RTSPin* rtspin, uint32_t baud)
{
    //UART模块指针
    MM32_UART* moudle = (MM32_UART*)txpin->moudle;

    //使能对应模块
    switch (txpin->moudle)
    {
        case UART1:        MM32RCC_enableUART1();        break;
        case UART2:        MM32RCC_enableUART2();        break;
        case UART3:        MM32RCC_enableUART3();        break;
        case UART4:        MM32RCC_enableUART4();        break;
        case UART5:        MM32RCC_enableUART5();        break;
        case UART6:        MM32RCC_enableUART6();        break;
        case UART7:        MM32RCC_enableUART7();        break;
        case UART8:        MM32RCC_enableUART8();        break;
        default:        return;
    }

    //配置引脚
    if(txpin!=NULL)
    {
        MM32GPIO_setAFPinConfig(txpin->port,txpin->pin,txpin->conf,txpin->af);
    }
    if(rxpin!=NULL)
    {
        MM32GPIO_setAFPinConfig(rxpin->port,rxpin->pin,rxpin->conf,rxpin->af);
    }
    if(ctspin!=NULL)
    {
        MM32GPIO_setAFPinConfig(ctspin->port,ctspin->pin,ctspin->conf,ctspin->af);
    }
    if(rtspin!=NULL)
    {
        MM32GPIO_setAFPinConfig(rtspin->port,rtspin->pin,rtspin->conf,rtspin->af);
    }

    extern unsigned int SystemCoreClock;

    //使能UART
    moudle->GCR.B.UARTEN = 1;
    //8位传输
    moudle->CCR.B.CHAR = 3;
    
    //配置波特率
    moudle->BRR.B.DIV_Mantissa = (SystemCoreClock/baud)/16;
    moudle->FRA.B.DIV_Fraction = (SystemCoreClock/baud)%16;
    
    //使能RX、TX
    moudle->GCR.B.RXEN = 1;
    moudle->GCR.B.TXEN = 1;
}

void MM32UART_write8(MM32UART_Moudle moudle, uint8_t* pdata)
{
    MM32_UART* m = (MM32_UART*)moudle;
    //等待TX缓冲非满
    while(m->CSR.B.TXFULL);
    //写入数据
    m->TDR.B.TXREG = *pdata;
}

void MM32UART_read8(MM32UART_Moudle moudle, uint8_t* pdata)
{
    MM32_UART* m = (MM32_UART*)moudle;
    //等待有效数据
    while(m->CSR.B.RXAVL!=1);
    //接收数据
    *pdata = m->RDR.B.RXREG;
}

void MM32UART_writeBlocking(MM32UART_Moudle moudle, void* pdata, size_t size)
{
    for(size_t i = 0; i <size; i++)
    {
        MM32UART_write8(moudle,(uint8_t*)pdata+i);
    }
}

void MM32UART_readBlocking(MM32UART_Moudle moudle, void* pdata, size_t size)
{
    for(size_t i = 0; i <size; i++)
    {
        MM32UART_read8(moudle,(uint8_t*)pdata+i);
    }
}