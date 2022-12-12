/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 20:39:57
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 21:24:59
 * @FilePath: \CODE\Peripheral\OLED\OLED.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "OLED.h"

/*MM32SPI_Pin_CS CS = {.port = GPIOD, .pin = P15, .conf = AF_PUSHPULL, .af = AF6, .moudle = SPI3};
MM32SPI_Pin_SCLK SCLK = {.port = GPIOD, .pin = P12, .conf = AF_PUSHPULL, .af = AF6, .moudle = SPI3};
MM32SPI_Pin_MOSI MOSI = {.port = GPIOD, .pin = P14, .conf = AF_PUSHPULL, .af = AF6, .moudle = SPI3};
MM32SPI_Pin_MOSI MISO = {.port = GPIOD, .pin = P13, .conf = INPUT_FLOATING, .af = AF6, .moudle = SPI3};*/

//OLED引脚定义
MM32GPIO_GPIO_Pin RES = {.port = GPIOD, .pin = P10, .conf = OUTPUT_PUSHPULL};
MM32GPIO_GPIO_Pin DC = {.port = GPIOD, .pin = P11, .conf = OUTPUT_PUSHPULL};

MM32GPIO_GPIO_Pin CS = {.port = GPIOD, .pin = P15, .conf = OUTPUT_PUSHPULL};
MM32GPIO_GPIO_Pin SCLK = {.port = GPIOD, .pin = P12, .conf = OUTPUT_PUSHPULL};
MM32GPIO_GPIO_Pin MOSI = {.port = GPIOD, .pin = P14, .conf = OUTPUT_PUSHPULL};
MM32GPIO_GPIO_Pin MISO = {.port = GPIOD, .pin = P13, .conf = INPUT_FLOATING};

//软件SPI设备
swspi_dev oled;

//显存脏数组
uint8_t oled_buffer[2][1024] = {0};
//当前生效显存
uint8_t oled_bufferIndx = 0;
//需要更新标记
uint8_t oled_refresh = 0;

void OLED_init(void)
{
    //初始化引脚
    MM32GPIO_setPinConfig(RES.port,RES.pin,RES.conf);
    MM32GPIO_setPinConfig(DC.port,DC.pin,DC.conf);
    //MM32SPI_moudleInit(&SCLK,&MOSI,NULL,&CS,1000000,MODE2);
    oled = SWSPIInit(MISO,MOSI,SCLK,CS,10000000,2);
    //配置刷新任务
    MM32PIT_timerTaskInit(PIT2,50,20);

    //OLED初始化
    MM32GPIO_setPinHigh(RES.port,RES.pin);
    uint8_t i = 50;while(i--);
    MM32GPIO_setPinLow(RES.port,RES.pin);
    i = 50;while(i--);
    MM32GPIO_setPinHigh(RES.port,RES.pin);
    OLED_WrtCmd(0xae); //--turn off oled panel
    OLED_WrtCmd(0x00); //---set low column address
    OLED_WrtCmd(0x10); //---set high column address
    OLED_WrtCmd(0x40); //--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
    OLED_WrtCmd(0x81); //--set contrast control register
    OLED_WrtCmd(0xff); // Set SEG Output Current OLED_SSD1306_Brightness
    OLED_WrtCmd(0xa1);
    OLED_WrtCmd(0xc8);

    OLED_WrtCmd(0xa6); //--set normal display
    OLED_WrtCmd(0xa8); //--set multiplex ratio(1 to 64)
    OLED_WrtCmd(0x3f); //--1/64 duty
    OLED_WrtCmd(0xd3); //-set display offset  Shift Mapping RAM Counter (0x00~0x3F)
    OLED_WrtCmd(0x00); //-not offset
    OLED_WrtCmd(0xd5); //--set display clock divide ratio/oscillator frequency
    OLED_WrtCmd(0x80); //--set divide ratio, Set Clock as 100 Frames/Sec
    OLED_WrtCmd(0xd9); //--set pre-charge period
    OLED_WrtCmd(0xf1); //Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    OLED_WrtCmd(0xda); //--set com pins hardware configuration
    OLED_WrtCmd(0x12);
    OLED_WrtCmd(0xdb); //--set vcomh
    OLED_WrtCmd(0x40); //Set VCOM Deselect Level
    OLED_WrtCmd(0x20); //-Set Page Addressing Mode (0x00/0x01/0x02)
    OLED_WrtCmd(0x02); //
    //OLED_WRTCMD(0x00);//@ C.M. change to page address mode. enable frame buffer.
    OLED_WrtCmd(0x8d); //--set Charge Pump enable/disable
    OLED_WrtCmd(0x14); //--set(0x10) disable
    OLED_WrtCmd(0xa4); // Disable Entire Display On (0xa4/0xa5)
    OLED_WrtCmd(0xa6); // Disable Inverse Display On (0xa6/a7)
    OLED_WrtCmd(0xa0);
    OLED_WrtCmd(0xc0);
    OLED_WrtCmd(0xaf); //--turn on oled panel
    OLED_Fill(0x00);
    //SmartCar_OLED_Fill(0xff);
    OLED_SetPos(0,0);
}

void OLED_WrtCmd(uint8_t cmd)
{
    MM32GPIO_setPinLow(DC.port,DC.pin);
    //MM32SPI_exchange8(CS.moudle,&cmd);
    SWSPI_start(&oled);
    SWSPIexchange_byte(&oled,cmd);
    SWSPI_stop(&oled);
}

void OLED_WrtData(uint8_t data)
{
    MM32GPIO_setPinHigh(DC.port,DC.pin);
    //MM32SPI_exchange8(CS.moudle,&data);
    SWSPI_start(&oled);
    SWSPIexchange_byte(&oled,data);
    SWSPI_stop(&oled);
}

void OLED_Fill(uint8_t data)
{
    uint8_t y, x;

    for (y = 0; y < 8; y++)
    {
        OLED_WrtCmd(0xb0 + y);
        OLED_WrtCmd(0x01);
        OLED_WrtCmd(0x10);
        for (x = 0; x < 128; x++)   OLED_WrtData(data);
    }
}

void OLED_SetPos(uint8_t x, uint8_t y)
{
    OLED_WrtCmd(0xb0+y);
    OLED_WrtCmd(((x & 0xf0)>>4)|0x10);
    OLED_WrtCmd((x & 0x0f)|0x00);
}

void OLED_PutPix(uint8_t x, uint8_t y, uint8_t data)
{
    OLED_SetPos(x, y);
    OLED_WrtCmd(0xb0 + y);
    OLED_WrtCmd(((x&0xf0) >> 4) | 0x10);
    OLED_WrtCmd((x&0x0f) | 0x00);
    OLED_WrtData(data);
}

void OLED_ClrPix(uint8_t x, uint8_t y)
{
    OLED_SetPos(x, y);
    OLED_WrtCmd(0xb0 + y);
    OLED_WrtCmd(((x&0xf0) >> 4) | 0x10);
    OLED_WrtCmd((x&0x0f) | 0x00);
    OLED_WrtData(0x00);
}


void OLED_P6x8Str(uint8_t x, uint8_t y, const char* ch)
{
    uint8_t c = 0;
    uint8_t i = 0;
    uint8_t j = 0;
    while(ch[j]!='\0')
    {
        c= ch[j] - 32;
        if(ch[j] == '\n')
        {
            y++;
            x = 0;
            continue;
        }
        if(x>126)
        {
            x = 0;
            y++;
        }
        if(y>7)
        {
            break;
        }
        OLED_SetPos(x, y);
        for(i = 0;i < 6;i++)
        {
            OLED_WrtData(font_6x8[c][i]);
        }
        x += 6;
        j++;
    }
}

void OLED_P6x8Reverse(uint8_t x, uint8_t y,const char* ch)
{
    uint8_t c = 0;
    uint8_t i = 0;
    uint8_t j = 0;
    while(ch[j]!='\0')
    {
        c= ch[j] - 32;
        if(ch[j] == '\n')
        {
            y++;
            x = 0;
            continue;
        }
        if(x>126)
        {
            x = 0;
            y++;
        }
        if(y>7)
        {
            break;
        }
        OLED_SetPos(x, y);
        for(i = 0;i < 6;i++)
        {
            OLED_WrtData(~font_6x8[c][i]);//��ɫ��ʾ
        }
        x += 6;
        j++;
    }
}

void OLED_P8x16Str(uint8_t x, uint8_t y, const char* ch)
{
    uint8_t c = 0;
    uint8_t i = 0;
    uint8_t j = 0;
    while(ch[j] != '\0')
    {
        c = ch[j] - 32;
        if(ch[j] == '\n')
        {
            y += 2;
            x = 0;
            continue;
        }
        if(x>120)
        {
            x = 0;
            y += 2;
        }
        if(y > 6)
        {
            break;
        }
        OLED_SetPos(x, y);
        for(i = 0;i<8;i++)
        {
            OLED_WrtData(font_8x16[c][i]);
        }
        OLED_SetPos(x, y+1);
        for(i = 0;i<8;i++)
        {
            OLED_WrtData(font_8x16[c][i+8]);
        }
        x += 8;
        j++;
    }
}

void OLED_Printf6x8(uint8_t x, uint8_t y, const char* ftm, ...)
{
    va_list args;
    va_start(args, ftm);
    char buf[64] = {0};
    vsnprintf(buf, 64, ftm, args);
    OLED_P6x8Str(x, y, buf);
}

void OLED_Printf8x16(uint8_t x,uint8_t y, const char* ftm, ...)
{
    va_list args;
    va_start(args, ftm);
    char buf[64] = {0};
    vsnprintf(buf, 64, ftm, args);
    OLED_P8x16Str(x, y, buf);
}

void OLED_Buffer_Upload(const uint8_t *buffer)
{
    const uint8_t *ptr = buffer;
    for (uint8_t y = 0; y < 8; ++y)
    {
        OLED_WrtCmd(0xb0 + y);
        OLED_WrtCmd(0x01);
        OLED_WrtCmd(0x10);

       for (uint8_t x = 0; x < 128; x++)
           OLED_WrtData(*(ptr++)); 

    }
}

void OLED_printfCharToBuf(uint8_t* x, uint8_t* y, char ch, uint8_t* buf)
{
    if(ch=='\n')
    {
        *x = 0;
        *y = *y + 1;
        return;
    }
    else
    {
        ch = ch - 32;
        if(*x > 127) {*x = 0; *y = *y + 8;}
        uint8_t* ptr = buf+128*(*y)+(*x);
        for(uint8_t i = 0;i < 6;i++)
        {
            ptr[i] = font_6x8[ch][i];
        }
        *x = *x + 6;
    }
}

void OLED_printfStrToBuf(uint8_t x, uint8_t y, const char* format)
{
    for(uint8_t i = 0; format[i]!='\0'&&i<64 ; i++)
    {
        OLED_printfCharToBuf(&x,&y,format[i],oled_buffer[oled_bufferIndx]);
    }
    //oled_dev.needDisp = TRUE;
    //oled_refresh = 1;
}

void OLED_printf(uint8_t x, uint8_t y, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char buf[64] = {0};
    vsnprintf(buf, 64, format, args);
    OLED_printfStrToBuf(x,y,buf);
    va_end(args);
}

void OLED_printBufToBuf(const uint8_t *buffer)
{
    memcpy(oled_buffer[oled_bufferIndx],buffer,1024);
    //oled_refresh = 1;
}

void OLED_clearBuf(void)
{
    memset(oled_buffer[oled_bufferIndx],0,1024);
    //oled_refresh = 1;
}

void OLED_printBuf(void)
{
    if(oled_refresh==0) return ;
    uint8_t* nowptr = oled_buffer[oled_bufferIndx];
    uint8_t* lastptr = oled_buffer[!oled_bufferIndx];
    for (uint8_t y = 0; y < 8; y++)
    {
        //oled_dev.interface.dc_write(oled_dev.interface.pin,(uint8)1);
        for (uint8_t x = 0; x < 128; x++)
        {
            if(nowptr[y*128+x]!=lastptr[y*128+x])
            {
                OLED_SetPos(x, y);
                OLED_WrtData(nowptr[y*128+x]);
            }
        }
    }
    oled_bufferIndx = !oled_bufferIndx ;
    oled_refresh = 0;
}