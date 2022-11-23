/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 15:15:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 15:25:43
 * @FilePath: \CODE\MM32\mLLD\GPIO\MM32_GPIO.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_GPIO_H_
#define _MM32_GPIO_H_

#include "MM32_GPIOReg.h"
#include "MM32_RCC.h"

/**
 * @brief GPIO端口枚举
 */
typedef enum _MM32GPIO_Port
{
  GPIOA = GPIOA_BASE,
  GPIOB = GPIOB_BASE,
  GPIOC = GPIOC_BASE,
  GPIOD = GPIOD_BASE,
  GPIOE = GPIOE_BASE,
  GPIOF = GPIOF_BASE,
  GPIOG = GPIOG_BASE,
  GPIOH = GPIOH_BASE,
}MM32GPIO_Port;

/**
 * @brief GPIO引脚号枚举
 */
typedef enum _MM32GPIO_Pin
{
  P00 = 0,
  P01 = 1,
  P02 = 2,
  P03 = 3,
  P04 = 4,
  P05 = 5,
  P06 = 6,
  P07 = 7,
  P08 = 8,
  P09 = 9,
  P10 = 10,
  P11 = 11,
  P12 = 12,
  P13 = 13,
  P14 = 14,
  P15 = 15,
}MM32GPIO_Pin;

/**
 * @brief GPIO引脚配置枚举
 */
typedef enum _MM32GPIO_Pin_Config
{
  /*
    0 | DCR | CNF | MODE  | ODR
  */
  INPUT_FLOATING = 8,             //浮空输入
  INPUT_PULLUP = 17,              //上拉输入
  INPUT_PULLDOWN = 16,            //下拉输入
  INPUT_ANALOG = 0,               //模拟输入

  OUTPUT_OPENDRAIN_FLOATING = 14, //浮空开漏输出
  OUTPUT_OPENDRAIN_PULLUP = 110,  //上拉开漏输出
  OUTPUT_OPENDRAIN_PULLDOWN = 46, //下拉开漏输出

  OUTPUT_PUSHPULL = 6,            //推挽输出

  AF_OPENDRAIN_FLOATING = 30,     //复用功能引脚浮空开漏输出
  AF_OPENDRAIN_PULLUP = 126,      //复用功能引脚上拉开漏输出
  AF_OPENDRAIN_PULLDOWN = 62,     //复用功能引脚下拉开漏输出

  AF_PUSHPULL = 22,               //复用功能引脚推挽输出
}MM32GPIO_Pin_Config;

/**
 * @brief 引脚复用功能编号枚举
 */
typedef enum _MM32GPIO_Pin_AF
{
  AF0 = 0,
  AF1 = 1,
  AF2 = 2,
  AF3 = 3,
  AF4 = 4,
  AF5 = 5,
  AF6 = 6,
  AF7 = 7,
  AF8 = 8,
  AF9 = 9,
  AF10 = 10,
  AF11 = 11,
  AF12 = 12,
  AF13 = 13,
  AF14 = 14,
  AF15 = 15,
}MM32GPIO_Pin_AF;

/**
 * @brief GPIO引脚属性结构体
 */
typedef struct _MM32GPIO_GPIO_Pin
{
  MM32GPIO_Port port;       //GPIO端口
  MM32GPIO_Pin pin;         //GPIO引脚号
  MM32GPIO_Pin_Config conf; //GPIO引脚配置
}MM32GPIO_GPIO_Pin;

/**
 * @description: 设置引脚配置
 * @param {MM32GPIO_Port} port  GPIO端口
 * @param {MM32GPIO_Pin} pin    GPIO引脚号
 * @param {MM32GPIO_Pin_Config} config  GPIO引脚配置
 * @return {*}
 * @example
 * \code
 *    //配置PA00引脚推挽输出
 *    MM32GPIO_setPinConfig(GPIOA,P00,OUTPUT_PUSHPULL);
 * \endcode
 */
void MM32GPIO_setPinConfig(MM32GPIO_Port port, MM32GPIO_Pin pin, MM32GPIO_Pin_Config config);

/**
 * @description: 设置复用功能引脚配置
 * @param {MM32GPIO_Port} port  GPIO端口
 * @param {MM32GPIO_Pin} pin  GPIO引脚号
 * @param {MM32GPIO_Pin_Config} config  GPIO引脚配置
 * @param {MM32GPIO_Pin_AF} af  复用功能选择
 * @return {*}
 * @note 复用功能选择需要对照用户手册
 * \code
 *    //配置PA00引脚0号复用推挽输出
 *    MM32GPIO_setAFPinConfig(GPIOA,P00,AF_PUSHPULL,AF0);
 * \endcode
 */
void MM32GPIO_setAFPinConfig(MM32GPIO_Port port, MM32GPIO_Pin pin, MM32GPIO_Pin_Config config, MM32GPIO_Pin_AF af);

/**
 * @description: 设置引脚输出高电平
 * @param {MM32GPIO_Port} port  GPIO端口
 * @param {MM32GPIO_Pin} pin  GPIO引脚号
 * @return {*}
 * @example
 * \code
 *    //设置PA00引脚为高
 *    MM32GPIO_setPinHigh(GPIOA,P00);
 * \endcode
 */
void MM32GPIO_setPinHigh(MM32GPIO_Port port, MM32GPIO_Pin pin);

/**
 * @description: 设置引脚输出低电平
 * @param {MM32GPIO_Port} port  GPIO端口
 * @param {MM32GPIO_Pin} pin  GPIO引脚号
 * @return {*}
 * @example
 * \code
 *    //设置PA00引脚为低
 *    MM32GPIO_setPinLow(GPIOA,P00);
 * \endcode
 */
void MM32GPIO_setPinLow(MM32GPIO_Port port, MM32GPIO_Pin pin);

/**
 * @description: 翻转引脚电平
 * @param {MM32GPIO_Port} port  GPIO端口
 * @param {MM32GPIO_Pin} pin  GPIO引脚号
 * @return {*}
 * @example
 * \code
 *    //翻转PA00引脚电平
 *    MM32GPIO_setPinToggle(GPIOA,P00);
 * \endcode
 */
void MM32GPIO_setPinToggle(MM32GPIO_Port port, MM32GPIO_Pin pin);

/**
 * @description: 读引脚电平
 * @param {MM32GPIO_Port} port  GPIO端口
 * @param {MM32GPIO_Pin} pin  GPIO引脚号
 * @return {uint8_t} 引脚电平，0为低，1为高
 * @note 输出引脚也可以读引脚电平
 * @example
 * \code
 *    //读PA00引脚电平
 *    uint8_t data = MM32GPIO_getPinState(GPIOA,P00);
 * \endcode
 */
uint8_t MM32GPIO_getPinState(MM32GPIO_Port port, MM32GPIO_Pin pin);

#endif