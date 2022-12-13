/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-12 21:34:09
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 12:15:13
 * @FilePath: \CODE\MM32\mLLD\SPI\MM32_SPIDMA.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_SPIDMA.h"

uint8_t SPIDMA_SPI1TX_Buffer[SPIDMA_BUFFERSIZE] = {0};
uint8_t SPIDMA_SPI1RX_Buffer[SPIDMA_BUFFERSIZE] = {0};

uint8_t SPIDMA_SPI2TX_Buffer[SPIDMA_BUFFERSIZE] = {0};
uint8_t SPIDMA_SPI2RX_Buffer[SPIDMA_BUFFERSIZE] = {0};

uint8_t SPIDMA_SPI3TX_Buffer[SPIDMA_BUFFERSIZE] = {0};
uint8_t SPIDMA_SPI3RX_Buffer[SPIDMA_BUFFERSIZE] = {0};

void _MM32SPIDMA_SPIInit(MM32SPI_Pin_SCLK* sclk, MM32SPI_Pin_MOSI* mosi, MM32SPI_Pin_MISO* miso, MM32SPI_Pin_CS* cs,
                        uint32_t baud, MM32SPI_Mode mode)
{
    //SPI模块指针
    MM32_SPI* moudle = (MM32_SPI*)sclk->moudle;
    //使能对应的SPI模块
    switch (sclk->moudle)
    {
        case SPI1:        MM32RCC_enableSPI1();        break;
        case SPI2:        MM32RCC_enableSPI2();        break;
        case SPI3:        MM32RCC_enableSPI3();        break;
        default:        return;
    }

    //配置引脚
    if(sclk!=NULL)
    {
        MM32GPIO_setAFPinConfig(sclk->port,sclk->pin,sclk->conf,sclk->af);
    }
    if(mosi!=NULL)
    {
        MM32GPIO_setAFPinConfig(mosi->port,mosi->pin,mosi->conf,mosi->af);
    }
    if(miso!=NULL)
    {
        MM32GPIO_setAFPinConfig(miso->port,miso->pin,miso->conf,miso->af);
    }
    if(cs!=NULL)
    {
        MM32GPIO_setAFPinConfig(cs->port,cs->pin,cs->conf,cs->af);
    }

    extern unsigned int SystemCoreClock;
    //设置通信速率
    moudle->SPBRG.B.SPBRG = (uint16_t)(SystemCoreClock/baud);
    //配置工作模式
    moudle->CCTL.B.CPHA = mode % 2;
    moudle->CCTL.B.CPOL = mode / 2;

    moudle->CCTL.B.SPILEN = 1;
    moudle->CCTL.B.LSBFE = 0;

    //moudle->CCTL.B.RXEDGE = 1;
    //moudle->CCTL.B.TXEDGE = 1;
    //设置为主机
    moudle->GCTL.B.MODE = 1;
    //硬件片选
    moudle->GCTL.B.NSS = 1;
    //使能DMA
    moudle->GCTL.B.DMAMODE = 1;
    //使能SPI
    moudle->GCTL.B.SPIEN = 1;

    //使能TX功能
    moudle->GCTL.B.TXEN = 1;
    //使能RX功能
    moudle->GCTL.B.RXEN = 1;
}

void MM32SPIDMA_moudleInit(MM32SPI_Pin_SCLK* sclk, MM32SPI_Pin_MOSI* mosi, MM32SPI_Pin_MISO* miso, MM32SPI_Pin_CS* cs,
                        uint32_t baud, MM32SPI_Mode mode)
{
    //根据SPI通道配置DMA通道（和完成中断）
    switch (sclk->moudle)
    {
    case SPI1:
    {        
        MM32RCC_enableDMA1();
        //配置RX DMA
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
        //从外设读
        DMA1_DMA_CCR2->B.DIR = 0;
        //使能传输完成中断
        //DMA1_DMA_CCR2->B.TCIE = 1;

        //配置TX DMA
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
        //从存储区读
        DMA1_DMA_CCR3->B.DIR = 1;
        //使能传输完成中断
        //DMA1_DMA_CCR3->B.TCIE = 1;
        break;
    }
    case SPI2:
    {       
        MM32RCC_enableDMA1();
        //配置RX DMA
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
        //从外设读
        DMA1_DMA_CCR4->B.DIR = 0;
        //使能传输完成中断
        //DMA1_DMA_CCR4->B.TCIE = 1;

        //配置TX DMA
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
        //从存储区读
        DMA1_DMA_CCR5->B.DIR = 1;
        //使能传输完成中断
        //DMA1_DMA_CCR5->B.TCIE = 1;
        break;
    }
    case SPI3:
    {        
        MM32RCC_enableDMA2();
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

        //配置TX DMA
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
        break;
    }
    default:        return;
    }
    //初始化SPI模块
    _MM32SPIDMA_SPIInit(sclk,mosi,miso,cs,baud,mode);
}

void MM32SPIDMA_startDMA(MM32SPI_Moudle moudle, void* txBuffer, void* rxBuffer, uint16_t txSize, uint16_t rxSize)
{
    switch (moudle)
    {
    case SPI1:
    {
        DMA1_DMA_CCR2->B.EN = 0;
        DMA1_DMA_CNDTR2->B.NDT = rxSize;
        DMA1_DMA_CPAR2->B.PA = (uint32_t)SPI1_RXREG;
        DMA1_DMA_CMAR2->B.MA = (uint32_t)rxBuffer;

        DMA1_DMA_CCR3->B.EN = 0;
        DMA1_DMA_CNDTR3->B.NDT = txSize;
        DMA1_DMA_CPAR3->B.PA = (uint32_t)SPI1_TXREG;
        DMA1_DMA_CMAR3->B.MA = (uint32_t)txBuffer;

        DMA1_DMA_CCR2->B.EN = 1;
        DMA1_DMA_CCR3->B.EN = 1;
        break;
    }
    case SPI2:
    {
        DMA1_DMA_CCR4->B.EN = 0;
        DMA1_DMA_CNDTR4->B.NDT = rxSize;
        DMA1_DMA_CPAR4->B.PA = (uint32_t)SPI2_RXREG;
        DMA1_DMA_CMAR4->B.MA = (uint32_t)rxBuffer;

        DMA1_DMA_CCR5->B.EN = 0;
        DMA1_DMA_CNDTR5->B.NDT = txSize;
        DMA1_DMA_CPAR5->B.PA = (uint32_t)SPI2_TXREG;
        DMA1_DMA_CMAR5->B.MA = (uint32_t)txBuffer;

        DMA1_DMA_CCR4->B.EN = 1;
        DMA1_DMA_CCR5->B.EN = 1;
        break;
    }
    case SPI3:
    {
        DMA2_DMA_CCR1->B.EN = 0;
        DMA2_DMA_CNDTR1->B.NDT = rxSize;
        DMA2_DMA_CPAR1->B.PA = (uint32_t)SPI3_RXREG;
        DMA2_DMA_CMAR1->B.MA = (uint32_t)rxBuffer;

        DMA2_DMA_CCR2->B.EN = 0;
        DMA2_DMA_CNDTR2->B.NDT = txSize;
        DMA2_DMA_CPAR2->B.PA = (uint32_t)SPI3_TXREG;
        DMA2_DMA_CMAR2->B.MA = (uint32_t)txBuffer;

        DMA2_DMA_CCR1->B.EN = 1;
        DMA2_DMA_CCR2->B.EN = 1;
        break;
    }
    default:        break;
    }
}