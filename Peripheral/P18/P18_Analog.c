/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-18 09:49:03
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-18 10:24:53
 * @FilePath: \CODE\Peripheral\P18\P18_Analog.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "P18_Analog.h"

MM32ADC_Pin P18_ADCPin1 = {.port = GPIOA, .pin = P00, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 0};
MM32ADC_Pin P18_ADCPin2 = {.port = GPIOA, .pin = P01, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 1};
MM32ADC_Pin P18_ADCPin3 = {.port = GPIOA, .pin = P02, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 2};

MM32ADC_Pin P18_ADCPinCom = {.port = GPIOA, .pin = P03, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 3};

void P18_analogPinInit(void)
{
    MM32DAC_pinInit(DAC1);
    MM32DAC_pinInit(DAC2);

    MM32ADC_pinInit(P18_ADCPin1);
    MM32ADC_pinInit(P18_ADCPin2);
    MM32ADC_pinInit(P18_ADCPin3);
    MM32ADC_pinInit(P18_ADCPinCom);
}

float P18_getShiftFromADC(P18_channel_t channel)
{
    MM32ADC_Pin compin = P18_ADCPinCom;
    MM32ADC_Pin srcpin;
    switch (channel)
    {
    case CHANNEL0:        srcpin = P18_ADCPin1;        break;
    case CHANNEL1:        srcpin = P18_ADCPin2;        break;
    case CHANNEL2:        srcpin = P18_ADCPin3;        break;
    default:        return 0;
    }

    uint8_t samTime = 10;
    float sum = 0;
    float max = -10000;
    float min = 10000;

    for(uint8_t i = 0; i < samTime; i++)
    {
        float data = (float)MM32ADC_getData(srcpin) - (float)MM32ADC_getData(compin);
        if(data > max) max = data;
        if(data < min) min = data;
        sum += data;
    }
    sum = (sum - max - min) / (samTime - 2);
    sum = sum / 4096;
    return sum * 350;
}

void P18_setVoltageToDAC(float voltage1, float voltage2)
{
    uint16_t data1 = (uint16_t)(voltage1 / 120 * 10 * 4096);
    uint16_t data2 = (uint16_t)(voltage2 / 120 * 10 * 4096);

    MM32DAC_set2ChannelData12(data1,data2);
}