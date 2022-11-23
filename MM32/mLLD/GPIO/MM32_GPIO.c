/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 15:15:38
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 15:30:19
 * @FilePath: \CODE\MM32\mLLD\GPIO\MM32_GPIO.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_GPIO.h"

void MM32GPIO_setPinConfig(MM32GPIO_Port port, MM32GPIO_Pin pin, MM32GPIO_Pin_Config config)
{
    //GPIO模块指针
    MM32_GPIO* moudle = (MM32_GPIO*)port;
    //使能对应模块的时钟
    switch (port)
    {
        case GPIOA:        MM32RCC_enableGPIOA();        break;
        case GPIOB:        MM32RCC_enableGPIOB();        break;
        case GPIOC:        MM32RCC_enableGPIOC();        break;
        case GPIOD:        MM32RCC_enableGPIOD();        break;
        case GPIOE:        MM32RCC_enableGPIOE();        break;
        case GPIOF:        MM32RCC_enableGPIOF();        break;
        case GPIOG:        MM32RCC_enableGPIOG();        break;
        case GPIOH:        MM32RCC_enableGPIOH();        break;
        default:        return;
    }

    //解释配置枚举为寄存器值
    uint32_t mask;
    uint8_t dcr = config >> 5;
    uint8_t cnf = (config >> 3) & 0x03;
    uint8_t mode = (config >> 1) & 0x03;
    uint8_t odr = config & 0x01;

    //设置引脚配置
    if(pin < 8)
    {
        mask = ~(0x3 << (4 * pin));
        mask &= moudle->CRL.U;
        moudle->CRL.U = mask | (mode << (4 * pin));

        mask = ~(0x3 << (4 * pin + 2));
        mask &= moudle->CRL.U;
        moudle->CRL.U = mask | (cnf << (4 * pin + 2));
    }
    else
    {
        pin = pin % 8;

        mask = ~(0x3 << (4 * pin));
        mask &= moudle->CRH.U;
        moudle->CRH.U = mask | (mode << (4 * pin));

        mask = ~(0x3 << (4 * pin + 2));
        mask &= moudle->CRH.U;
        moudle->CRH.U = mask | (cnf << (4 * pin + 2));
    }
    mask = ~(0x3 << (2 * pin));
    mask &= moudle->DCR.U;
    moudle->DCR.U = mask | (dcr << (2 * pin));

    mask = ~(0x1 << (pin));
    mask &= moudle->ODR.B.ODRY;
    moudle->ODR.B.ODRY = mask | (odr << (pin));
}

void MM32GPIO_setAFPinConfig(MM32GPIO_Port port, MM32GPIO_Pin pin, MM32GPIO_Pin_Config config, MM32GPIO_Pin_AF af)
{
    //初始化引脚
    MM32GPIO_setPinConfig(port,pin,config);

    MM32_GPIO* moudle = (MM32_GPIO*)port;
    uint32_t mask;
    //配置复用功能
    if(pin < 8)
    {
        mask = ~(0xF << (4 * pin));
        mask &= moudle->AFRL.U;
        moudle->AFRL.U = mask | (af << (4 * pin));
    }
    else
    {
        pin = pin % 8;

        mask = ~(0xF << (4 * pin));
        mask &= moudle->AFRH.U;
        moudle->AFRH.U = mask | (af << (4 * pin));
    }
}

void MM32GPIO_setPinHigh(MM32GPIO_Port port, MM32GPIO_Pin pin)
{
    MM32_GPIO* moudle = (MM32_GPIO*)port;

    moudle->BSRR.B.BSY = 0x1 << pin;
}

void MM32GPIO_setPinLow(MM32GPIO_Port port, MM32GPIO_Pin pin)
{
    MM32_GPIO* moudle = (MM32_GPIO*)port;

    moudle->BSRR.B.BRY = 0x1 << pin;
}

void MM32GPIO_setPinToggle(MM32GPIO_Port port, MM32GPIO_Pin pin)
{
    MM32_GPIO* moudle = (MM32_GPIO*)port;
    //读取当前引脚电平，然后翻转输出
    if((moudle->ODR.B.ODRY >> pin) & 0x1)
    {
        moudle->BSRR.B.BRY = 0x1 << pin;
    }
    else
    {
        moudle->BSRR.B.BSY = 0x1 << pin;
    }
}

uint8_t MM32GPIO_getPinState(MM32GPIO_Port port, MM32GPIO_Pin pin)
{
    MM32_GPIO* moudle = (MM32_GPIO*)port;

    return (moudle->IDR.B.IDRY >> pin) & 0x1;
}