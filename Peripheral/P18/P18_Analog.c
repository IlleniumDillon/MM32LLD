/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-18 09:49:03
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-24 11:12:12
 * @FilePath: \CODE\Peripheral\P18\P18_Analog.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "P18_Analog.h"

//ADC引脚定义
MM32ADC_Pin P18_ADCPin1 = {.port = GPIOA, .pin = P00, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 0};
MM32ADC_Pin P18_ADCPin2 = {.port = GPIOA, .pin = P01, .conf = INPUT_FLOATING, .moudle = ADC2, .ch = 1};
MM32ADC_Pin P18_ADCPin3 = {.port = GPIOA, .pin = P02, .conf = INPUT_FLOATING, .moudle = ADC3, .ch = 2};

MM32ADC_Pin P18_ADCPinCom = {.port = GPIOA, .pin = P03, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 3};

void P18_analogPinInit(void)
{
    //初始化DAC模块
    MM32DAC_pinInit(DAC1);
    MM32DAC_pinInit(DAC2);
    //初始化ADC引脚
    MM32ADC_pinInit(P18_ADCPin1);
    MM32ADC_pinInit(P18_ADCPin2);
    MM32ADC_pinInit(P18_ADCPin3);
    MM32ADC_pinInit(P18_ADCPinCom);
}

float P18_getVoltageFromADC(P18_channel_t channel)
{
    //参考引脚
    /// @todo 要先改正ADC转换卡死的BUG才能用参考引脚
    MM32ADC_Pin compin = P18_ADCPinCom;

    //根据通道选择引脚
    MM32ADC_Pin srcpin;
    switch (channel)
    {
    case CHANNEL0:        srcpin = P18_ADCPin1;        break;
    case CHANNEL1:        srcpin = P18_ADCPin2;        break;
    case CHANNEL2:        srcpin = P18_ADCPin3;        break;
    default:        return 0;
    }

    //连续采样10次，去掉极值后取平均作为采样值
    uint8_t samTime = 10;
    float sum = 0;
    float max = -10000;
    float min = 10000;

    for(uint8_t i = 0; i < samTime; i++)
    {
        float data = (float)MM32ADC_getData(srcpin);// - (float)MM32ADC_getData(compin);
        if(data > max) max = data;
        if(data < min) min = data;
        sum += data;
    }
    sum = (sum - max - min) / (samTime - 2);

    //将电压值转换到0-10的浮点数
    sum = sum / 4096;
    return sum * 10;
}

void P18_setVoltageToDAC(float voltage1, float voltage2)
{   
    //限幅
    if(voltage1 > 9.9)voltage1 = 9.9;
    if(voltage2 > 9.9)voltage2 = 9.9;

    //计算设定值
    uint16_t data1 = (uint16_t)(voltage1 / 10 * 4096);
    uint16_t data2 = (uint16_t)(voltage2 / 10 * 4096);

    //同时设定两个DAC通道的值
    MM32DAC_set2ChannelData12(data1,data2);
}