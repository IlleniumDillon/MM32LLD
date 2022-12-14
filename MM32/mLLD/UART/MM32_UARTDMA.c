/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-13 13:39:55
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 16:02:34
 * @FilePath: \CODE\MM32\mLLD\UART\MM32_UARTDMA.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_UARTDMA.h"

void _MM32UARTDMA_UARTInit(MM32UART_TXPin* txpin, MM32UART_RXPin* rxpin, MM32UART_CTSPin* ctspin, MM32UART_RTSPin* rtspin, uint32_t baud)
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

    //使能DMA
    moudle->GCR.B.DMAMODE = 1;
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

void MM32UARTDMA_moudleInit(MM32UART_TXPin* txpin, MM32UART_RXPin* rxpin, MM32UART_CTSPin* ctspin, MM32UART_RTSPin* rtspin, uint32_t baud)
{
    switch (txpin->moudle)
    {
    case UART1:
    {
        //配置TX DMA
        MM32RCC_enableDMA1();
        //使能自动重装载
        DMA1_DMA_CCR4->B.ARE = 1;
        //设置高优先级
        DMA1_DMA_CCR4->B.PL = 2;
        //存储器数据宽度8bit
        DMA1_DMA_CCR4->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA1_DMA_CCR4->B.PSIZE = 2;
        //存储器地址递增
        DMA1_DMA_CCR4->B.MINC = 1;
        //从存储区读
        DMA1_DMA_CCR4->B.DIR = 1;
        //使能传输完成中断
        //DMA1_DMA_CCR4->B.TCIE = 1;

        //配置RX DMA
        //使能自动重装载
        DMA1_DMA_CCR5->B.ARE = 1;
        //设置高优先级
        DMA1_DMA_CCR5->B.PL = 2;
        //存储器数据宽度8bit
        DMA1_DMA_CCR5->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA1_DMA_CCR5->B.PSIZE = 2;
        //存储器地址递增
        DMA1_DMA_CCR5->B.MINC = 1;
        //从外设读
        DMA1_DMA_CCR5->B.DIR = 0;
        //使能传输完成中断
        //DMA1_DMA_CCR5->B.TCIE = 1;
        break;
    }
    case UART2:
    {
        //配置TX DMA
        MM32RCC_enableDMA1();
        //使能自动重装载
        DMA1_DMA_CCR7->B.ARE = 1;
        //设置高优先级
        DMA1_DMA_CCR7->B.PL = 2;
        //存储器数据宽度8bit
        DMA1_DMA_CCR7->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA1_DMA_CCR7->B.PSIZE = 2;
        //存储器地址递增
        DMA1_DMA_CCR7->B.MINC = 1;
        //从存储区读
        DMA1_DMA_CCR7->B.DIR = 1;
        //使能传输完成中断
        //DMA1_DMA_CCR7->B.TCIE = 1;

        //配置RX DMA
        //使能自动重装载
        DMA1_DMA_CCR6->B.ARE = 1;
        //设置高优先级
        DMA1_DMA_CCR6->B.PL = 2;
        //存储器数据宽度8bit
        DMA1_DMA_CCR6->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA1_DMA_CCR6->B.PSIZE = 2;
        //存储器地址递增
        DMA1_DMA_CCR6->B.MINC = 1;
        //从外设读
        DMA1_DMA_CCR6->B.DIR = 0;
        //使能传输完成中断
        //DMA1_DMA_CCR6->B.TCIE = 1;
        break;
    }
    case UART3:
    {
        //配置TX DMA
        MM32RCC_enableDMA1();
        //使能自动重装载
        DMA1_DMA_CCR2->B.ARE = 1;
        //设置高优先级
        DMA1_DMA_CCR2->B.PL = 2;
        //存储器数据宽度8bit
        DMA1_DMA_CCR2->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA1_DMA_CCR2->B.PSIZE = 2;
        //存储器地址递增
        DMA1_DMA_CCR2->B.MINC = 1;
        //从存储区读
        DMA1_DMA_CCR2->B.DIR = 1;
        //使能传输完成中断
        //DMA1_DMA_CCR2->B.TCIE = 1;

        //配置RX DMA
        //使能自动重装载
        DMA1_DMA_CCR3->B.ARE = 1;
        //设置高优先级
        DMA1_DMA_CCR3->B.PL = 2;
        //存储器数据宽度8bit
        DMA1_DMA_CCR3->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA1_DMA_CCR3->B.PSIZE = 2;
        //存储器地址递增
        DMA1_DMA_CCR3->B.MINC = 1;
        //从外设读
        DMA1_DMA_CCR3->B.DIR = 0;
        //使能传输完成中断
        //DMA1_DMA_CCR3->B.TCIE = 1;
        break;
    }
    case UART4:
    {
        //配置TX DMA
        MM32RCC_enableDMA2();
        //使能自动重装载
        DMA2_DMA_CCR5->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR5->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR5->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR5->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR5->B.MINC = 1;
        //从存储区读
        DMA2_DMA_CCR5->B.DIR = 1;
        //使能传输完成中断
        //DMA2_DMA_CCR5->B.TCIE = 1;

        //配置RX DMA
        //使能自动重装载
        DMA2_DMA_CCR3->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR3->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR3->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR3->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR3->B.MINC = 1;
        //从外设读
        DMA2_DMA_CCR3->B.DIR = 0;
        //使能传输完成中断
        //DMA2_DMA_CCR3->B.TCIE = 1;
        break;
    }
    case UART5:
    {
        //配置TX DMA
        MM32RCC_enableDMA2();
        //使能自动重装载
        DMA2_DMA_CCR2->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR2->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR2->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR2->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR2->B.MINC = 1;
        //从存储区读
        DMA2_DMA_CCR2->B.DIR = 1;
        //使能传输完成中断
        //DMA2_DMA_CCR2->B.TCIE = 1;

        //配置RX DMA
        //使能自动重装载
        DMA2_DMA_CCR1->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR1->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR1->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR1->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR1->B.MINC = 1;
        //从外设读
        DMA2_DMA_CCR1->B.DIR = 0;
        //使能传输完成中断
        //DMA2_DMA_CCR1->B.TCIE = 1;
        break;
    }
    case UART6:
    {
        //配置TX DMA
        MM32RCC_enableDMA2();
        //使能自动重装载
        DMA2_DMA_CCR4->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR4->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR4->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR4->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR4->B.MINC = 1;
        //从存储区读
        DMA2_DMA_CCR4->B.DIR = 1;
        //使能传输完成中断
        //DMA2_DMA_CCR4->B.TCIE = 1;

        //配置RX DMA
        MM32RCC_enableDMA1();
        //使能自动重装载
        DMA1_DMA_CCR1->B.ARE = 1;
        //设置高优先级
        DMA1_DMA_CCR1->B.PL = 2;
        //存储器数据宽度8bit
        DMA1_DMA_CCR1->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA1_DMA_CCR1->B.PSIZE = 2;
        //存储器地址递增
        DMA1_DMA_CCR1->B.MINC = 1;
        //从外设读
        DMA1_DMA_CCR1->B.DIR = 0;
        //使能传输完成中断
        //DMA1_DMA_CCR1->B.TCIE = 1;
        break;
    }
    case UART7:
    {
        //配置TX DMA
        MM32RCC_enableDMA2();
        //使能自动重装载
        DMA2_DMA_CCR2->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR2->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR2->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR2->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR2->B.MINC = 1;
        //从存储区读
        DMA2_DMA_CCR2->B.DIR = 1;
        //使能传输完成中断
        //DMA2_DMA_CCR2->B.TCIE = 1;

        //配置RX DMA
        //使能自动重装载
        DMA2_DMA_CCR1->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR1->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR1->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR1->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR1->B.MINC = 1;
        //从外设读
        DMA2_DMA_CCR1->B.DIR = 0;
        //使能传输完成中断
        //DMA2_DMA_CCR1->B.TCIE = 1;
        break;
    }
    case UART8:
    {
        //配置TX DMA
        MM32RCC_enableDMA2();
        //使能自动重装载
        DMA2_DMA_CCR5->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR5->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR5->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR5->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR5->B.MINC = 1;
        //从存储区读
        DMA2_DMA_CCR5->B.DIR = 1;
        //使能传输完成中断
        //DMA2_DMA_CCR5->B.TCIE = 1;

        //配置RX DMA
        //使能自动重装载
        DMA2_DMA_CCR3->B.ARE = 1;
        //设置高优先级
        DMA2_DMA_CCR3->B.PL = 2;
        //存储器数据宽度8bit
        DMA2_DMA_CCR3->B.MSIZE = 0;
        //外设数据宽度32bit
        DMA2_DMA_CCR3->B.PSIZE = 2;
        //存储器地址递增
        DMA2_DMA_CCR3->B.MINC = 1;
        //从外设读
        DMA2_DMA_CCR3->B.DIR = 0;
        //使能传输完成中断
        //DMA2_DMA_CCR3->B.TCIE = 1;
        break;
    }
    default:        break;
    }
    //初始化UART模块
    _MM32UARTDMA_UARTInit(txpin,rxpin,ctspin,rtspin,baud);
}

void MM32UARTDMA_startTXDMA(MM32UART_Moudle moudle, void* txBuffer, uint16_t txSize)
{
    switch (moudle)
    {
    case UART1:
    {
        DMA1_DMA_CCR4->B.EN = 0;
        DMA1_DMA_CNDTR4->B.NDT = txSize;
        DMA1_DMA_CPAR4->B.PA = (uint32_t)UART1_TDR;
        DMA1_DMA_CMAR4->B.MA = (uint32_t)txBuffer;

        DMA1_DMA_CCR4->B.EN = 1;
        break;
    }
    case UART2:
    {
        DMA1_DMA_CCR7->B.EN = 0;
        DMA1_DMA_CNDTR7->B.NDT = txSize;
        DMA1_DMA_CPAR7->B.PA = (uint32_t)UART2_TDR;
        DMA1_DMA_CMAR7->B.MA = (uint32_t)txBuffer;

        DMA1_DMA_CCR7->B.EN = 1;
        break;
    }
    case UART3:
    {
        DMA1_DMA_CCR2->B.EN = 0;
        DMA1_DMA_CNDTR2->B.NDT = txSize;
        DMA1_DMA_CPAR2->B.PA = (uint32_t)UART3_TDR;
        DMA1_DMA_CMAR2->B.MA = (uint32_t)txBuffer;

        DMA1_DMA_CCR2->B.EN = 1;
        break;
    }
    case UART4:
    {
        DMA2_DMA_CCR5->B.EN = 0;
        DMA2_DMA_CNDTR5->B.NDT = txSize;
        DMA2_DMA_CPAR5->B.PA = (uint32_t)UART4_TDR;
        DMA2_DMA_CMAR5->B.MA = (uint32_t)txBuffer;

        DMA2_DMA_CCR5->B.EN = 1;
        break;
    }
    case UART5:
    {
        DMA2_DMA_CCR2->B.EN = 0;
        DMA2_DMA_CNDTR2->B.NDT = txSize;
        DMA2_DMA_CPAR2->B.PA = (uint32_t)UART5_TDR;
        DMA2_DMA_CMAR2->B.MA = (uint32_t)txBuffer;

        DMA2_DMA_CCR2->B.EN = 1;
        break;
    }
    case UART6:
    {
        DMA2_DMA_CCR4->B.EN = 0;
        DMA2_DMA_CNDTR4->B.NDT = txSize;
        DMA2_DMA_CPAR4->B.PA = (uint32_t)UART6_TDR;
        DMA2_DMA_CMAR4->B.MA = (uint32_t)txBuffer;

        DMA2_DMA_CCR4->B.EN = 1;
        break;
    }
    case UART7:
    {
        DMA2_DMA_CCR2->B.EN = 0;
        DMA2_DMA_CNDTR2->B.NDT = txSize;
        DMA2_DMA_CPAR2->B.PA = (uint32_t)UART7_TDR;
        DMA2_DMA_CMAR2->B.MA = (uint32_t)txBuffer;

        DMA2_DMA_CCR2->B.EN = 1;
        break;
    }
    case UART8:
    {
        DMA2_DMA_CCR5->B.EN = 0;
        DMA2_DMA_CNDTR5->B.NDT = txSize;
        DMA2_DMA_CPAR5->B.PA = (uint32_t)UART8_TDR;
        DMA2_DMA_CMAR5->B.MA = (uint32_t)txBuffer;

        DMA2_DMA_CCR5->B.EN = 1;
        break;
    }
    default:        break;
    }
}

void MM32UARTDMA_startRXDMA(MM32UART_Moudle moudle, void* rxBuffer, uint16_t rxSize)
{
    switch (moudle)
    {
    case UART1:
    {
        DMA1_DMA_CCR5->B.EN = 0;
        DMA1_DMA_CNDTR5->B.NDT = rxSize;
        DMA1_DMA_CPAR5->B.PA = (uint32_t)UART1_RDR;
        DMA1_DMA_CMAR5->B.MA = (uint32_t)rxBuffer;

        DMA1_DMA_CCR5->B.EN = 1;
        break;
    }
    case UART2:
    {
        DMA1_DMA_CCR6->B.EN = 0;
        DMA1_DMA_CNDTR6->B.NDT = rxSize;
        DMA1_DMA_CPAR6->B.PA = (uint32_t)UART2_RDR;
        DMA1_DMA_CMAR6->B.MA = (uint32_t)rxBuffer;

        DMA1_DMA_CCR6->B.EN = 1;
        break;
    }
    case UART3:
    {
        DMA1_DMA_CCR3->B.EN = 0;
        DMA1_DMA_CNDTR3->B.NDT = rxSize;
        DMA1_DMA_CPAR3->B.PA = (uint32_t)UART3_RDR;
        DMA1_DMA_CMAR3->B.MA = (uint32_t)rxBuffer;

        DMA1_DMA_CCR3->B.EN = 1;
        break;
    }
    case UART4:
    {
        DMA2_DMA_CCR3->B.EN = 0;
        DMA2_DMA_CNDTR3->B.NDT = rxSize;
        DMA2_DMA_CPAR3->B.PA = (uint32_t)UART4_RDR;
        DMA2_DMA_CMAR3->B.MA = (uint32_t)rxBuffer;

        DMA2_DMA_CCR3->B.EN = 1;
        break;
    }
    case UART5:
    {
        DMA2_DMA_CCR1->B.EN = 0;
        DMA2_DMA_CNDTR1->B.NDT = rxSize;
        DMA2_DMA_CPAR1->B.PA = (uint32_t)UART5_RDR;
        DMA2_DMA_CMAR1->B.MA = (uint32_t)rxBuffer;

        DMA2_DMA_CCR1->B.EN = 1;
        break;
    }
    case UART6:
    {
        DMA1_DMA_CCR1->B.EN = 0;
        DMA1_DMA_CNDTR1->B.NDT = rxSize;
        DMA1_DMA_CPAR1->B.PA = (uint32_t)UART6_RDR;
        DMA1_DMA_CMAR1->B.MA = (uint32_t)rxBuffer;

        DMA1_DMA_CCR1->B.EN = 1;
        break;
    }
    case UART7:
    {
        DMA2_DMA_CCR1->B.EN = 0;
        DMA2_DMA_CNDTR1->B.NDT = rxSize;
        DMA2_DMA_CPAR1->B.PA = (uint32_t)UART7_RDR;
        DMA2_DMA_CMAR1->B.MA = (uint32_t)rxBuffer;

        DMA2_DMA_CCR1->B.EN = 1;
        break;
    }
    case UART8:
    {
        DMA2_DMA_CCR3->B.EN = 0;
        DMA2_DMA_CNDTR3->B.NDT = rxSize;
        DMA2_DMA_CPAR3->B.PA = (uint32_t)UART8_RDR;
        DMA2_DMA_CMAR3->B.MA = (uint32_t)rxBuffer;

        DMA2_DMA_CCR3->B.EN = 1;
        break;
    }
    default:        break;
    }
}