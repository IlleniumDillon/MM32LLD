/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 15:03:11
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 17:14:25
 * @FilePath: \CODE\Peripheral\SWSPI\SWSPI.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "SWSPI.H"

static void _delay(uint32_t time);

static void _set_high(MM32GPIO_GPIO_Pin pin);
static void _set_low(MM32GPIO_GPIO_Pin pin);
static void _set_input(MM32GPIO_GPIO_Pin pin);
static void _set_output(MM32GPIO_GPIO_Pin pin);
static uint8_t _get_input(MM32GPIO_GPIO_Pin pin);

static void _sclk_leading(MM32GPIO_GPIO_Pin pin, uint32_t time);
static void _sclk_trailing(MM32GPIO_GPIO_Pin pin, uint32_t time);





swspi_dev SWSPIInit(MM32GPIO_GPIO_Pin miso, MM32GPIO_GPIO_Pin mosi, MM32GPIO_GPIO_Pin sclk, MM32GPIO_GPIO_Pin cs,
        uint32_t baudrate,uint8_t mode)
{
    extern unsigned int SystemCoreClock;

    swspi_dev dev;
    dev.cs = cs;
    dev.miso = miso;
    dev.mosi = mosi;
    dev.sclk = sclk;
    dev.delaytime = SystemCoreClock/(baudrate*4);
    _set_output(dev.cs);
    _set_output(dev.sclk);
    _set_output(dev.mosi);
    _set_input(dev.miso);
    if(mode==0)
    {
        dev.sclk_active = &_set_high;
        dev.sclk_idle = &_set_low;
        dev.sclk_effectiveedge = &_sclk_leading;
        dev.sclk_ineffectiveedge = &_sclk_trailing;
    }
    else if(mode==1)
    {
        dev.sclk_active = &_set_high;
        dev.sclk_idle = &_set_low;
        dev.sclk_effectiveedge = &_sclk_trailing;
        dev.sclk_ineffectiveedge = &_sclk_leading;
    }
    else if(mode==2)
    {
        dev.sclk_active = &_set_low;
        dev.sclk_idle = &_set_high;
        dev.sclk_effectiveedge = &_sclk_trailing;
        dev.sclk_ineffectiveedge = &_sclk_leading;
    }
    else if(mode==3)
    {
        dev.sclk_active = &_set_low;
        dev.sclk_idle = &_set_high;
        dev.sclk_effectiveedge = &_sclk_leading;
        dev.sclk_ineffectiveedge = &_sclk_trailing;
    }
    dev.sclk_idle(dev.sclk);
    _set_high(dev.mosi);
    _set_high(dev.cs);
    return dev;
}

void SWSPIExchange(swspi_dev* dev, uint8_t* ptxdata, uint8_t* prxdata, size_t count)
{
    SWSPI_start(dev);
    for(size_t i = 0; i < count ; i++)
    {
        prxdata[i] = SWSPIexchange_byte(dev,ptxdata[i]);
    }
    SWSPI_stop(dev);
}

static void _delay(uint32_t time)
{
    while(time--);
}

static void _set_high(MM32GPIO_GPIO_Pin pin)
{
    MM32GPIO_setPinHigh(pin.port, pin.pin);
}

static void _set_low(MM32GPIO_GPIO_Pin pin)
{
    MM32GPIO_setPinLow(pin.port, pin.pin);
}

static void _set_input(MM32GPIO_GPIO_Pin pin)
{
    MM32GPIO_setPinConfig(pin.port, pin.pin,INPUT_PULLUP);
}

static void _set_output(MM32GPIO_GPIO_Pin pin)
{
    MM32GPIO_setPinConfig(pin.port, pin.pin,OUTPUT_PUSHPULL);
}

static uint8_t _get_input(MM32GPIO_GPIO_Pin pin)
{
    return MM32GPIO_getPinState(pin.port,pin.pin);
}

static void _sclk_leading(MM32GPIO_GPIO_Pin pin, uint32_t time)
{
    _delay(time);
    _set_high(pin);
    _delay(time);
}

static void _sclk_trailing(MM32GPIO_GPIO_Pin pin, uint32_t time)
{
    _delay(time);
    _set_low(pin);
    _delay(time);
}

void SWSPI_start(swspi_dev* dev)
{
    _delay(dev->delaytime);
    _set_low(dev->cs);
    _delay(dev->delaytime);
}

void SWSPI_stop(swspi_dev* dev)
{
    _delay(dev->delaytime);
    dev->sclk_idle(dev->sclk);
    _delay(dev->delaytime);
    _set_high(dev->mosi);
    _delay(dev->delaytime);
    _set_high(dev->cs);
    _delay(dev->delaytime);
}

uint8_t SWSPIexchange_byte(swspi_dev* dev, uint8_t byte)
{
    uint8_t rx = 0;
    for(uint8_t i = 0 ; i < 8 ; i++)
    {
        rx<<=1;
        dev->sclk_ineffectiveedge(dev->sclk,dev->delaytime);
        if(byte & 0x80) _set_high(dev->mosi);
        else _set_low(dev->mosi);
        byte<<=1;
        dev->sclk_effectiveedge(dev->sclk,dev->delaytime);
        if(_get_input(dev->miso)) rx += 1;
    }
    return rx;
}