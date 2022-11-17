/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 19:06:47
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:05:54
 * @FilePath: \CODE\MM32\mLLD\SPI\MM32_SPI.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_SPI.h"

void MM32SPI_moudleInit(MM32SPI_Pin_SCLK* sclk, MM32SPI_Pin_MOSI* mosi, MM32SPI_Pin_MISO* miso, MM32SPI_Pin_CS* cs,
                        uint32_t baud, MM32SPI_Mode mode)
{
    MM32_SPI* moudle = (MM32_SPI*)sclk->moudle;

    switch (sclk->moudle)
    {
        case SPI1:        MM32RCC_enableSPI1();        break;
        case SPI2:        MM32RCC_enableSPI2();        break;
        case SPI3:        MM32RCC_enableSPI3();        break;
        default:        return;
    }

    if(sclk!=NULL)
    {
        MM32GPIO_setAFPinConfig(sclk->port,sclk->pin,sclk->conf,sclk->af);
    }
    if(mosi!=NULL)
    {
        MM32GPIO_setAFPinConfig(sclk->port,sclk->pin,sclk->conf,sclk->af);
    }
    if(miso!=NULL)
    {
        MM32GPIO_setAFPinConfig(sclk->port,sclk->pin,sclk->conf,sclk->af);
    }
    if(cs!=NULL)
    {
        MM32GPIO_setAFPinConfig(sclk->port,sclk->pin,sclk->conf,sclk->af);
    }

    extern unsigned int SystemCoreClock;

    moudle->SPBRG.B.SPBRG = (uint16_t)(SystemCoreClock/baud);

    moudle->CCTL.B.CPHA = mode % 2;
    moudle->CCTL.B.CPOL = mode / 2;

    moudle->CCTL.B.SPILEN = 1;
    moudle->CCTL.B.LSBFE = 0;

    moudle->CCTL.B.RXEDGE = 1;
    moudle->CCTL.B.TXEDGE = 1;

    moudle->GCTL.B.MODE = 1;
    moudle->GCTL.B.NSS = 1;
    moudle->GCTL.B.SPIEN = 1;

    moudle->GCTL.B.TXEN = 1;
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