/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-31 19:06:40
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-12 21:41:42
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

/**
 * @brief SPI模块枚举
 */
typedef enum _MM32SPI_Moudle
{
    SPI1 = SPI1_BASE,
    SPI2 = SPI2_BASE,
    SPI3 = SPI3_BASE,
}MM32SPI_Moudle;

/**
 * @brief SPI模式枚举
 */
typedef enum _MM32SPI_Mode
{
    MODE0 = 0,
    MODE1 = 1,
    MODE2 = 2,
    MODE3 = 3,
}MM32SPI_Mode;

/**
 * @brief SPI SCLK引脚结构体
 */
typedef struct _MM32SPI_Pin_SCLK
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_SCLK;

/**
 * @brief SPI MOSI引脚结构体
 */
typedef struct _MM32SPI_Pin_MOSI
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_MOSI;

/**
 * @brief SPI MISO引脚结构体
 */
typedef struct _MM32SPI_Pin_MISO
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_MISO;

/**
 * @brief SPI CS引脚结构体
 */
typedef struct _MM32SPI_Pin_CS
{
    MM32GPIO_Port port;
    MM32GPIO_Pin pin;
    MM32GPIO_Pin_Config conf;
    MM32GPIO_Pin_AF af;
    MM32SPI_Moudle moudle;
}MM32SPI_Pin_CS;

/**
 * @description: 初始化SPI模块
 * @param {MM32SPI_Pin_SCLK*} sclk  sclk引脚配置结构体指针
 * @param {MM32SPI_Pin_MOSI*} mosi  mosi引脚配置结构体指针
 * @param {MM32SPI_Pin_MISO*} miso  miso引脚配置结构体指针
 * @param {MM32SPI_Pin_CS*} cs  cs引脚配置结构体指针
 * @param {uint32_t} baud   时钟频率
 * @param {MM32SPI_Mode} mode   工作模式
 * @return {*}
 * @example
 * \code
 *      MM32SPI_moudleInit(&SCLK,&MOSI,NULL,&CS,1000000,MODE2);
 * \endcode
 */
void MM32SPI_moudleInit(MM32SPI_Pin_SCLK* sclk, MM32SPI_Pin_MOSI* mosi, MM32SPI_Pin_MISO* miso, MM32SPI_Pin_CS* cs,
                        uint32_t baud, MM32SPI_Mode mode);

/**
 * @description: SPI传输一个字节
 * @param {MM32SPI_Moudle} moudle   SPI模块
 * @param {uint8_t*} pdata  发送的数据
 * @return {uint8_t} 接收的数据
 * @example
 * \code
 *      uint8_t tdata = 0xff;
 *      uint8_t rdata = MM32SPI_exchange8(SPI1,&tdata);
 * \endcode
 */
uint8_t MM32SPI_exchange8(MM32SPI_Moudle moudle, uint8_t* pdata);

/**
 * @description: SPI交换块数据
 * @param {MM32SPI_Moudle} moudle   SPI模块
 * @param {void*} txdata    发送数据指针
 * @param {void*} rxdata    接收数据指针
 * @param {size_t} size 数据字节数
 * @return {*}
 * @example
 * \code
 *      uint8_t tdata[1024] = 0;
 *      uint8_t rdata[1024] = 0;
 *      MM32SPI_exchangeBlocking(SPI1,tdata,rdata,1024);
 * \endcode
 */
void MM32SPI_exchangeBlocking(MM32SPI_Moudle moudle, void* txdata, void* rxdata, size_t size);

#endif