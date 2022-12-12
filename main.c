/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:29:44
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-12 14:09:51
 * @FilePath: \CODE\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "MM32_GPIO.h"
#include "MM32_UART.h"
#include "MM32_SPI.h"
#include "MM32_SDCard.h"
#include "MM32_FLASH.h"
#include "OLED.h"
#include "UART_Upload.h"
#include "P18_CTRL.h"

#include "SWSDIO.h"
#include <math.h>
#include "MM32_PIT.h"
#include "menu.h"

#include "MM32_DAC.h"
#include "MM32_ADC.h"
#include "MM32_ADCDMA.h"

int main()
{
  uint16_t data1[10] = {0};
  uint16_t data2[10] = {0};
  uint16_t data3[10] = {0};
  MM32ADC_Pin ADCPin1 = {.port = GPIOA, .pin = P00, .conf = INPUT_FLOATING, .moudle = ADC1, .ch = 0};
  MM32ADC_Pin ADCPin2 = {.port = GPIOA, .pin = P01, .conf = INPUT_FLOATING, .moudle = ADC2, .ch = 1};
  MM32ADC_Pin ADCPin3 = {.port = GPIOA, .pin = P02, .conf = INPUT_FLOATING, .moudle = ADC3, .ch = 2};
  MM32ADCDMA_pinInit(ADCPin1,data1,10);
  MM32ADCDMA_pinInit(ADCPin2,data2,10);
  MM32ADCDMA_pinInit(ADCPin3,data3,10);
  while(1)
  {
    MM32ADCDMA_startADCDMA(ADCPin1);
    MM32ADCDMA_startADCDMA(ADCPin2);
    MM32ADCDMA_startADCDMA(ADCPin3);
    while(ADC1_DMADone != 1);
    while(ADC2_DMADone != 1);
    while(ADC3_DMADone != 1);
    ADC1_DMADone = 0;
    ADC2_DMADone = 0;
    ADC3_DMADone = 0;
  }
  return 0;
}
