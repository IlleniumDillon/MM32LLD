/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:29:44
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-13 16:10:49
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

#include "MM32_SPIDMA.h"
#include "MM32_UARTDMA.h"

int main()
{
  MM32SPI_Pin_CS CS = {.port = GPIOD, .pin = P15, .conf = AF_PUSHPULL, .af = AF6, .moudle = SPI3};
  MM32SPI_Pin_SCLK SCLK = {.port = GPIOD, .pin = P12, .conf = AF_PUSHPULL, .af = AF6, .moudle = SPI3};
  MM32SPI_Pin_MOSI MOSI = {.port = GPIOD, .pin = P14, .conf = AF_PUSHPULL, .af = AF6, .moudle = SPI3};
  MM32SPI_Pin_MISO MISO = {.port = GPIOD, .pin = P13, .conf = INPUT_FLOATING, .af = AF6, .moudle = SPI3};

  MM32UART_TXPin txpin = {.port = GPIOD, .pin = P05, .conf = AF_PUSHPULL, .af = AF7, .moudle = UART2};
  MM32UART_RXPin rxpin = {.port = GPIOD, .pin = P06, .conf = INPUT_FLOATING, .af = AF7, .moudle = UART2};

  //MM32SPI_moudleInit(&SCLK,&MOSI,&MISO,&CS,1000000,MODE2);
  //MM32SPIDMA_moudleInit(&SCLK,&MOSI,&MISO,&CS,1000000,MODE2);

  MM32UARTDMA_moudleInit(&txpin,&rxpin,NULL,NULL,115200);
  uint8_t tdata[10] = {0x5a,0xa5,0xaa,0x55,0x12,0x5a,0xa5,0xaa,0x55,0x12};
  int i = 10000;
  while(1)
  {
    /*uint8_t tdata = 0x5a;
    uint8_t rdata = MM32SPI_exchange8(SPI3,&tdata);
    if(rdata == tdata)
    {
      i = 1;
    }*/
    //MM32SPIDMA_startDMA(SPI3,tdata,NULL,10,0);
    MM32UARTDMA_startTXDMA(UART2,tdata,10);
    i = 100000;
    while(i--);
  }
  return 0;
}
