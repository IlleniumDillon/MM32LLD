/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:29:44
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-06 12:05:25
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
#include "P18_TFCTRL.h"

#include "SWSDIO.h"
#include <math.h>
#include "MM32_PIT.h"
#include "menu.h"

#include "MM32_DAC.h"
#include "MM32_ADC.h"

int main()
{
    /*P18_save_t save = {0};
    uint8_t data[1024] = {0};
    
    save.baud = 115200;
    save.fbTime = 5;
    save.P[0] = 0;
    save.P[1] = 0;
    save.P[2] = 0;
    save.I[0] = 0;
    save.I[1] = 0;
    save.I[2] = 0;
    save.D[0] = 0;
    save.D[1] = 0;
    save.D[2] = 0;

    memcpy(data,&save,sizeof(save));

    nvic_interrput_disable();
    MM32FLASH_erasePage(0);
    MM32FLASH_writePage(0,data);
    nvic_interrput_enable();*/

  //Menu_loadPara();

  systick_start();
  
  /*MM32UART_TXPin txpin = {.port = GPIOD, .pin = P05, .conf = AF_PUSHPULL, .af = AF7, .moudle = UART2};
  MM32UART_RXPin rxpin = {.port = GPIOD, .pin = P06, .conf = INPUT_FLOATING, .af = AF7, .moudle = UART2};
  MM32UART_moudleInit(&txpin,&rxpin,NULL,NULL,115200);
  MM32_UART* m = (MM32_UART*)UART2;
  m->IER.B.RX_IEN = 1;
  nvic_init(UART2_IRQn, 0x02, 0x00, 1);*/
  /*MM32UART_TXPin txpin2 = {.port = GPIOD, .pin = P00, .conf = AF_PUSHPULL, .af = AF8, .moudle = UART8};
  MM32UART_RXPin rxpin2 = {.port = GPIOD, .pin = P01, .conf = INPUT_FLOATING, .af = AF8, .moudle = UART8};
  MM32UART_moudleInit(&txpin2,&rxpin2,NULL,NULL,P18_device.baud);*/
  MM32GPIO_setPinConfig(GPIOF,P00,INPUT_FLOATING);
  HOST_uartUploadDmaInit();
  P18_tfInit();
  P18_analogPinInit();
  MM32PIT_timerTaskInit(PIT1,2000,1);
  MM32PIT_timerTaskInit(PIT2,1000,2);
  //Menu_init();
  //Menu_display();

  while(1)
  {
    if(MM32GPIO_getPinState(GPIOF,P00))
    {
        inputs[0] = 1;
        inputs[1] = 1;
        MM32PIT_Close(PIT1);
        MM32PIT_Close(PIT2);
        continue;
    }
    else
    {
        MM32PIT_Start(PIT1);
        MM32PIT_Start(PIT2);
    }
    
    //HOST_uartUploadStart();
    /*if(transeFlag)
    {
      float data[4] = {P18_X.output,P18_X.current,P18_Y.output,P18_Y.current};
      //UART_floatVarUpload(UART2,data,4);//通过USB-B传输
      UART_floatVarUpload(UART8,data,4);//通过RS232-USB传输
    }*/
  }
  return 0;
}
