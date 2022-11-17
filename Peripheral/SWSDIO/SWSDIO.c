/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 15:05:18
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 19:15:25
 * @FilePath: \CODE\Peripheral\SWSDIO\SWSDIO.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "SWSDIO.h"

swspi_dev dev;

uint8_t SDIO_CMD[6] = {0};

void SWSDIO_init(void)
{
    MM32GPIO_GPIO_Pin mosi = {.port = GPIOD, .pin = P02};
    MM32GPIO_GPIO_Pin miso = {.port = GPIOC, .pin = P08};
    MM32GPIO_GPIO_Pin sclk = {.port = GPIOC, .pin = P12};
    MM32GPIO_GPIO_Pin cs = {.port = GPIOC, .pin = P11};
    dev = SWSPIInit(miso,mosi,sclk,cs,4000000,3);
    
    
    int time = 0;
    
    //MM32GPIO_setPinConfig(cs.port,cs.pin,INPUT_PULLUP);

    SWSPI_start(&dev);
    for(uint8_t i = 0; i < 74; i++)
    {
        SWSPIexchange_byte(&dev,0xff);
    }
    SWSPI_stop(&dev);

    //MM32GPIO_setPinConfig(cs.port,cs.pin,OUTPUT_PUSHPULL);


    SDIO_CMD[0] = 0x40;
    SDIO_CMD[5] = 0x95;

    SWSPI_start(&dev);
    do
    {
      time = 0;
      for(uint8_t i = 0; i < 6; i++)
      {
          SWSPIexchange_byte(&dev,SDIO_CMD[i]);
      }
      while(1)
      {
        if(SWSPIexchange_byte(&dev,0xff) == 0x01)
        {
          time = -1;
          break;
        }
        else
        {
          time++;
        }
        if(time>64) break;
      }
    }while(time!=-1);
    SWSPI_stop(&dev);
    SWSPI_start(&dev);
    MM32GPIO_setPinHigh(cs.port,cs.pin);
    SWSPIexchange_byte(&dev,0xff);
    SWSPI_stop(&dev);


    SDIO_CMD[0] = 0x40 | 8;
    SDIO_CMD[3] = 0x01;
    SDIO_CMD[4] = 0xaa;
    SDIO_CMD[5] = 0x87;
    SWSPI_start(&dev);
    for(uint8_t i = 0; i < 6; i++)
    {
        SWSPIexchange_byte(&dev,SDIO_CMD[i]);
    }
    uint8_t r1 = SWSPIexchange_byte(&dev,0xff);
    while(r1==0xff)
    {
      r1 = SWSPIexchange_byte(&dev,0xff);
    }
    if(r1 == 0x01)
    {
        SWSPIexchange_byte(&dev,0xff);SWSPIexchange_byte(&dev,0xff);SWSPIexchange_byte(&dev,0xff);SWSPIexchange_byte(&dev,0xff);
        SWSPI_stop(&dev);
        SWSPI_start(&dev);
        MM32GPIO_setPinHigh(cs.port,cs.pin);
        SWSPIexchange_byte(&dev,0xff);
        SWSPI_stop(&dev);
        do
        {
          time = 0;
          SDIO_CMD[0] = 0x40 | 55;
          SDIO_CMD[3] = 0x0;
          SDIO_CMD[4] = 0x0;
          SDIO_CMD[5] = 0xff;
          SWSPI_start(&dev);
          for(uint8_t i = 0; i < 6; i++)
          {
              SWSPIexchange_byte(&dev,SDIO_CMD[i]);
          }
          r1 = SWSPIexchange_byte(&dev,0xff);
          while(r1==0xff&&time<=64)
          {
            r1 = SWSPIexchange_byte(&dev,0xff);
            time++;
          }
          SWSPI_stop(&dev);
          if(r1!=0x01) 
          {
            r1 = 0x01;
            continue;
          }
          
          
          time = 0;
          SDIO_CMD[0] = 0x40 | 41;
          SDIO_CMD[1] = 0x00;
          SDIO_CMD[2] = 0x00;
          SDIO_CMD[5] = 0xff;
          SWSPI_start(&dev);
          for(uint8_t i = 0; i < 6; i++)
          {
              SWSPIexchange_byte(&dev,SDIO_CMD[i]);
          }
          r1 = SWSPIexchange_byte(&dev,0xff);
          while(r1==0xff&&time<=200)
          {
            r1 = SWSPIexchange_byte(&dev,0xff);
            time++;
          }
          SWSPI_stop(&dev);
          if(r1==0) break;
        }while(1);
    }

    /*SDIO_CMD[0] = 0x40 | 55;
    SDIO_CMD[5] = 0xff;

    SWSPI_start(&dev);
    for(uint8_t i = 0; i < 6; i++)
    {
        SWSPIexchange_byte(&dev,SDIO_CMD[i]);
    }
    SWSPI_stop(&dev);

    SDIO_CMD[0] = 0x40 | 41;
    SDIO_CMD[5] = 0x5f;

    SWSPI_start(&dev);
    do
    {
      time = 0;
      for(uint8_t i = 0; i < 6; i++)
      {
          SWSPIexchange_byte(&dev,SDIO_CMD[i]);
      }
      while(1)
      {
        if(SWSPIexchange_byte(&dev,0xff) == 0x00)
        {
          time = -1;
          break;
        }
        else
        {
          time++;
        }
        if(time>64) break;
      }
    }while(time!=-1);
    SWSPI_stop(&dev);
    SWSPI_start(&dev);
    MM32GPIO_setPinHigh(cs.port,cs.pin);
    SWSPIexchange_byte(&dev,0xff);
    SWSPI_stop(&dev);*/
}