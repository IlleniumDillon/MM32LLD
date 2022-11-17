/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 19:06:40
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-10-31 20:05:57
 * @FilePath: \CODE\MM32\mLLD\SPI\MM32_SPI.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_SPI_H_
#define _MM32_SPI_H_

#include "MM32_SPIReg.h"
#include "MM32_DMAReg.h"

#include "MM32_GPIO.h"
#include "MM32_RCC.h"

#include "MM32_SPIPinMap.h"

typedef enum _MM32SPI_Moudle
{
    SPI1 = SPI1_BASE,
    SPI2 = SPI2_BASE,
    SPI3 = SPI3_BASE,
}MM32SPI_Moudle;

typedef enum _MM32SPI_Mode
{
    MODE0 = 0,
    MODE1 = 1,
    MODE2 = 2,
    MODE3 = 3,
}MM32SPI_Mode;

typedef struct _MM32SPI_Pin_SCLK
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_SCLK;

typedef struct _MM32SPI_Pin_MOSI
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_MOSI;

typedef struct _MM32SPI_Pin_MISO
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_MISO;

typedef struct _MM32SPI_Pin_CS
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_CS;

void MM32SPI_moudleInit(MM32SPI_Pin_SCLK* sclk, MM32SPI_Pin_MOSI* mosi, MM32SPI_Pin_MISO* miso, MM32SPI_Pin_CS* cs,
                        uint32_t baud, MM32SPI_Mode mode);

uint8_t MM32SPI_exchange8(MM32SPI_Moudle moudle, uint8_t* pdata);

void MM32SPI_exchangeBlocking(MM32SPI_Moudle moudle, void* txdata, void* rxdata, size_t size);

#endif