/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-17 20:48:05
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 14:08:07
 * @FilePath: \CODE\MM32\mLLD\ADC\MM32_ADC.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_ADC.h"

void MM32ADC_pinInit(MM32ADC_Pin pin)
{
    //ADC模块指针
    MM32_ADC* moudle = (MM32_ADC*)pin.moudle;

    //使能对应的ADC模块
    switch (pin.moudle)
    {
    case ADC1:        MM32RCC_enableADC1();        break;
    case ADC2:        MM32RCC_enableADC2();        break;
    case ADC3:        MM32RCC_enableADC3();        break;
    default:        return;
    }

    //配置引脚属性
    MM32GPIO_setPinConfig(pin.port,pin.pin,pin.conf);

    //配置ADC模块时钟频率
    moudle->ADCFG.B.ADCPREH = 4;
    moudle->ADCFG.B.ADCPREL = 0;

    //使能对应通道
    moudle->ADCHS.U |= 0x1 << pin.ch;
    //ADC转换使能
    moudle->ADCFG.B.ADEN = 1;
}

uint16_t MM32ADC_getData(MM32ADC_Pin pin)
{
    //ADC模块指针
    MM32_ADC* moudle = (MM32_ADC*)pin.moudle;
    //ADC转换数据寄存器指针
    MM32_ADC_ADDR0* DR = (MM32_ADC_ADDR0*)((uint32_t)&(moudle->ADDR0)+0x04*pin.ch);
    //软件开始一次转换
    moudle->ADCR.B.ADST = 1;
    //等待数据有效
    while(DR->B.VAILD!=1);

    return DR->B.DATA;
}