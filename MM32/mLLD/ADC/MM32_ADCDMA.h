/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 19:55:57
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 20:54:58
 * @FilePath: \CODE\MM32\mLLD\ADC\MM32_ADCDMA.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_ADCDMA_H_
#define _MM32_ADCDMA_H_

#include "MM32_ADC.h"
#include "MM32_DMAReg.h"
#include "common.h"

extern uint8_t ADC1_DMADone;
extern uint8_t ADC2_DMADone;
extern uint8_t ADC3_DMADone;

void MM32ADCDMA_pinInit(MM32ADC_Pin pin, void* dataPtr, uint32_t size);

void MM32ADCDMA_startADCDMA(MM32ADC_Pin pin);

void MM32ADCDMA_stopADCDMA(MM32ADC_Pin pin);

#endif