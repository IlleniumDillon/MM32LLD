/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:29:44
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-22 09:17:53
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

#include "tf.h"

int main()
{
  MM32DAC_pinInit(DAC1);
  MM32DAC_pinInit(DAC2);
  tf_function_t tf;
  float num[3] = {1,-1.515,0.8057};
  float den[3] = {1,-1.078,0.3679};
  tf_initZFunction_ND(&tf,num,3,den,3,1,0.0005);
  float output = 0;
  systick_start();
  uint32_t time = 0;
  float time_s = 0;
  while(1)
  {
    time = systick_getval();
    output = tf_update(&tf,1);
    MM32DAC_set2ChannelData12((uint16_t)output/2*1095,(uint16_t)output/2*1095);
    time = systick_getval() - time;
    time_s = (float)time/(float)120000000;
    if(output||time_s)
    {
      output = 0;
      time_s = 0;
    }
  }
  return 0;
}
