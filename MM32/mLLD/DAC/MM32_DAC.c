/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-17 18:25:44
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 14:23:26
 * @FilePath: \CODE\MM32\mLLD\DAC\MM32_DAC.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_DAC.h"

void MM32DAC_pinInit(MM32DAC_Moudle moudle)
{
    //使能DAC时钟
    MM32RCC_enableDAC();
    //设定DAC模块转换时钟
    DAC_SWTRIGR->B.DAC_PRE = 5;

    //配置对应模块的引脚和模块属性
    switch (moudle)
    {
    case DAC1:
        {
            //配置引脚
            MM32GPIO_setPinConfig(GPIOA,P04,INPUT_FLOATING);
            //输出缓存使能
            DAC_CR->B.BOFF1 = 1;
            //自动数据传输
            DAC_CR->B.TEN1 = 0;
            //禁止波形生成功能
            DAC_CR->B.WAVE1 = 0;
            //禁用DMA
            DAC_CR->B.DMA_EN1 = 0;
            //模块使能
            DAC_CR->B.EN1 = 1;
            break;
        }    
    case DAC2:
        {
            //配置引脚
            MM32GPIO_setPinConfig(GPIOA,P05,INPUT_FLOATING);
            //输出缓存使能
            DAC_CR->B.BOFF2 = 1;
            //自动数据传输
            DAC_CR->B.TEN2 = 0;
            //禁止波形生成功能
            DAC_CR->B.WAVE2 = 0;
            //禁用DMA
            DAC_CR->B.DMA_EN2 = 0;
            //模块使能
            DAC_CR->B.EN2 = 1;
            break;
        }    
    default:
        break;
    }
}

void MM32DAC_setData12(MM32DAC_Moudle moudle, uint16_t data)
{
    switch (moudle)
    {
    case DAC1:
        {
            //设置通道一的转换值
            DAC_DHR12RD->B.DACC1DHR = data & 0x0FFF;
            break;
        }    
    case DAC2:
        {
            //设置通道二的转换值
            DAC_DHR12RD->B.DACC2DHR = data & 0x0FFF;
            break;
        }    
    default:
        break;
    }
}

void MM32DAC_set2ChannelData12(uint16_t dataCh1, uint16_t dataCh2)
{
    //对数据寄存器整体赋值
    uint32_t data = ((dataCh2&0x0FFF) << 16) | (dataCh1&0x0FFF);
    DAC_DHR12RD->U = data;
}