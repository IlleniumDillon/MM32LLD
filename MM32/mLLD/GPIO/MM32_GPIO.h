/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 15:15:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-05 19:47:44
 * @FilePath: \CODE\MM32\mLLD\GPIO\MM32_GPIO.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_GPIO_H_
#define _MM32_GPIO_H_

#include "MM32_GPIOReg.h"
#include "MM32_RCC.h"

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

typedef enum _MM32GPIO_Pin_Config
{
  /*
    0 | DCR | CNF | MODE  | ODR
  */
  INPUT_FLOATING = 8,
  INPUT_PULLUP = 17,
  INPUT_PULLDOWN = 16,
  INPUT_ANALOG = 0,

  OUTPUT_OPENDRAIN_FLOATING = 14,
  OUTPUT_OPENDRAIN_PULLUP = 110,
  OUTPUT_OPENDRAIN_PULLDOWN = 46,

  OUTPUT_PUSHPULL = 6,

  AF_OPENDRAIN_FLOATING = 30,
  AF_OPENDRAIN_PULLUP = 126,
  AF_OPENDRAIN_PULLDOWN = 62,

  AF_PUSHPULL = 22,
}MM32GPIO_Pin_Config;

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

typedef struct _MM32GPIO_GPIO_Pin
{
  MM32GPIO_Port port;
  MM32GPIO_Pin pin;
  MM32GPIO_Pin_Config conf;
}MM32GPIO_GPIO_Pin;

void MM32GPIO_setPinConfig(MM32GPIO_Port port, MM32GPIO_Pin pin, MM32GPIO_Pin_Config config);

void MM32GPIO_setAFPinConfig(MM32GPIO_Port port, MM32GPIO_Pin pin, MM32GPIO_Pin_Config config, MM32GPIO_Pin_AF af);

void MM32GPIO_setPinHigh(MM32GPIO_Port port, MM32GPIO_Pin pin);

void MM32GPIO_setPinLow(MM32GPIO_Port port, MM32GPIO_Pin pin);

void MM32GPIO_setPinToggle(MM32GPIO_Port port, MM32GPIO_Pin pin);

uint8_t MM32GPIO_getPinState(MM32GPIO_Port port, MM32GPIO_Pin pin);

#endif