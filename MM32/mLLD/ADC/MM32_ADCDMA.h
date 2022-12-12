/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 19:55:57
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-12 14:26:20
 * @FilePath: \CODE\MM32\mLLD\ADC\MM32_ADCDMA.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_ADCDMA_H_
#define _MM32_ADCDMA_H_

#include "MM32_ADC.h"
#include "MM32_DMAReg.h"
#include "common.h"

//各个ADC通道DMA传输完成标志
extern uint8_t ADC1_DMADone;
extern uint8_t ADC2_DMADone;
extern uint8_t ADC3_DMADone;

/**
 * @description: 初始化单通道的ADC DMA传输（12位分辨率）
 * @param {MM32ADC_Pin} pin ADC引脚
 * @param {void*} dataPtr 存储器空间的地址（16位）
 * @param {uint16_t} size 搬运数据量（16位）
 * @return {void}
 * @example
 * \code
 *      uint16_t data[10] = {0};
 *      MM32ADC_Pin ADCPin1 = {.port = GPIOA, .pin = P00, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 0};
 *      MM32ADCDMA_pinInit(ADCPin1,data,10);
 * \endcode
 */
void MM32ADCDMA_pinInit(MM32ADC_Pin pin, void* dataPtr, uint16_t size);

/**
 * @description: 开始一次DMA传输
 * @param {MM32ADC_Pin} pin ADC引脚
 * @return {void}
 * @example
 * \code
 *      MM32ADCDMA_startADCDMA(ADCPin1);
 * \endcode
 */
void MM32ADCDMA_startADCDMA(MM32ADC_Pin pin);

/**
 * @description: 停止DMA传输
 * @param {MM32ADC_Pin} pin ADC引脚
 * @return {void}
 * @example
 * \code
 *      MM32ADCDMA_stopADCDMA(ADCPin1);
 * \endcode
 */
void MM32ADCDMA_stopADCDMA(MM32ADC_Pin pin);

#endif