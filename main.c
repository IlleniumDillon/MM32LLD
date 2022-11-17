/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:29:44
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-17 19:25:19
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

int main()
{
  Menu_loadPara();

  systick_start();
  
  MM32UART_TXPin txpin = {.port = GPIOD, .pin = P05, .conf = AF_PUSHPULL, .af = AF7, .moudle = UART2};
  MM32UART_RXPin rxpin = {.port = GPIOD, .pin = P06, .conf = INPUT_FLOATING, .af = AF7, .moudle = UART2};
  MM32UART_moudleInit(&txpin,&rxpin,NULL,NULL,1152000);
  MM32_UART* m = (MM32_UART*)UART2;
  m->IER.B.RX_IEN = 1;
  nvic_init(UART2_IRQn, 0x02, 0x00, 1);
  MM32UART_TXPin txpin2 = {.port = GPIOA, .pin = P00, .conf = AF_PUSHPULL, .af = AF8, .moudle = UART4};
  MM32UART_RXPin rxpin2 = {.port = GPIOA, .pin = P01, .conf = INPUT_FLOATING, .af = AF8, .moudle = UART4};
  MM32UART_moudleInit(&txpin2,&rxpin2,NULL,NULL,P18_device.baud);
  
  Menu_init();
  Menu_display();

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
