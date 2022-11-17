/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:29:44
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-15 17:51:35
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

int main()
{

  while(1)
  {
    static uint8_t flag = 0;
    if(MM32GPIO_getPinState(GPIOA,P07))
    {
      MM32PIT_Close(PIT1);
      MM32PIT_Start(PIT2);
      Menu_loop();
    }
    else
    {
      MM32PIT_Close(PIT2);
      if(flag==0)
      {
        MM32PIT_timerTaskInit(PIT1,10,0);
        flag = 1;
      }
      else
      {
        MM32PIT_Start(PIT1);
      }
    }
    
  }
  return 0;
}
