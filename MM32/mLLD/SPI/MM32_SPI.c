/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 19:06:47
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 12:20:27
 * @FilePath: \CODE\MM32\mLLD\SPI\MM32_SPI.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_SPI.h"

void MM32SPI_moudleInit(MM32SPI_Pin_SCLK* sclk, MM32SPI_Pin_MOSI* mosi, MM32SPI_Pin_MISO* miso, MM32SPI_Pin_CS* cs,
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
    //使能SPI
    moudle->GCTL.B.SPIEN = 1;

    //使能TX功能
    moudle->GCTL.B.TXEN = 1;
    //使能RX功能
    moudle->GCTL.B.RXEN = 1;
}

uint8_t MM32SPI_exchange8(MM32SPI_Moudle moudle, uint8_t* pdata)
{
    MM32_SPI* m = (MM32_SPI*)moudle;
    m->TXREG.B.TXREG = *pdata;
    return m->RXREG.B.RXREG;
}

void MM32SPI_exchangeBlocking(MM32SPI_Moudle moudle, void* txdata, void* rxdata, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        *((uint8_t*)rxdata + i) = MM32SPI_exchange8(moudle, ((uint8_t*)txdata + i));
    }
}