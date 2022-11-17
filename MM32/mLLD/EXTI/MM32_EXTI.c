/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-05 19:44:22
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-05 20:57:44
 * @FilePath: \CODE\MM32\mLLD\EXTI\MM32_EXTI.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_EXTI.h"

void MM32EXTI_pinInit(MM32GPIO_GPIO_Pin pin, MM32EXTI_Trigger trigger, uint8_t pro)
{
    MM32RCC_enableSYSCFG();

    MM32GPIO_setPinConfig(pin.port,pin.pin,pin.conf);
    
    uint32_t mask;
    //配置触发方式
    if(trigger & RISING)
    {
        //配置上升沿触发
        mask = ~(0x1 << pin.pin); 
        mask &= EXTI_RTSR->U;
        EXTI_RTSR->U = mask | (0x1 << pin.pin);
    }
    else
    {
        //禁用上升沿触发
        mask = ~(0x1 << pin.pin); 
        EXTI_RTSR->U &= mask;
    }
    
    if(trigger & FALLING)
    {
        //配置下降沿触发
        mask = ~(0x1 << pin.pin); 
        mask &= EXTI_FTSR->U;
        EXTI_FTSR->U = mask | (0x1 << pin.pin);
    }
    else
    {
        //禁用下降沿触发
        mask = ~(0x1 << pin.pin); 
        EXTI_FTSR->U &= mask;
    }
    
    //选择 EXTI 外部中断的输入源
    if(pin.pin < 4)
    {
        mask = ~(0xF << ((pin.pin % 4) * 4));
        mask &= SYSCFG_EXTICR1->U;
        SYSCFG_EXTICR1->U = mask | (((uint32_t)pin.port - (uint32_t)GPIOA_BASE)/0x400) << ((pin.pin % 4) * 4);
    }
    else if(pin.pin < 8)
    {
        mask = ~(0xF << ((pin.pin % 4) * 4));
        mask &= SYSCFG_EXTICR2->U;
        SYSCFG_EXTICR2->U = mask | (((uint32_t)pin.port - (uint32_t)GPIOA_BASE)/0x400) << ((pin.pin % 4) * 4);
    }
    else if(pin.pin < 12)
    {
        mask = ~(0xF << ((pin.pin % 4) * 4));
        mask &= SYSCFG_EXTICR3->U;
        SYSCFG_EXTICR3->U = mask | (((uint32_t)pin.port - (uint32_t)GPIOA_BASE)/0x400) << ((pin.pin % 4) * 4);
    }
    else if(pin.pin < 16)
    {
        mask = ~(0xF << ((pin.pin % 4) * 4));
        mask &= SYSCFG_EXTICR4->U;
        SYSCFG_EXTICR4->U = mask | (((uint32_t)pin.port - (uint32_t)GPIOA_BASE)/0x400) << ((pin.pin % 4) * 4);
    }
    
    switch (pin.pin)
    {
    case P00:        nvic_init(EXTI0_IRQn,pro,0x00,1);        break;
    case P01:        nvic_init(EXTI1_IRQn,pro,0x00,1);        break;
    case P02:        nvic_init(EXTI2_IRQn,pro,0x00,1);        break;
    case P03:        nvic_init(EXTI3_IRQn,pro,0x00,1);        break;
    case P04:        nvic_init(EXTI4_IRQn,pro,0x00,1);        break;
    case P05:
    case P06:
    case P07:
    case P08:
    case P09:       nvic_init(EXTI9_5_IRQn,pro,0x00,1);        break;
    case P10:
    case P11:
    case P12:
    case P13:
    case P14:
    case P15:       nvic_init(EXTI15_10_IRQn,pro,0x00,1);        break;
    default:        break;
    }

    MM32EXTI_enable(pin);
}

void MM32EXTI_enable(MM32GPIO_GPIO_Pin pin)
{
    uint32_t mask = ~(0x1 << pin.pin); 
    mask &= EXTI_IMR->U;
    EXTI_IMR->U = mask | (0x1 << pin.pin);
}

void MM32EXTI_disable(MM32GPIO_GPIO_Pin pin)
{
    uint32_t mask = ~(0x1 << pin.pin); 
    EXTI_IMR->U &= mask;
}