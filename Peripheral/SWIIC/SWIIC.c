/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-02 15:03:25
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-02 17:14:41
 * @FilePath: \CODE\Peripheral\SWIIC\SWIIC.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "SWIIC.h"

static void _delay(uint32_t time);

static void _set_high(MM32GPIO_GPIO_Pin pin);
static void _set_low(MM32GPIO_GPIO_Pin pin);
static void _set_input(MM32GPIO_GPIO_Pin pin);
static void _set_output(MM32GPIO_GPIO_Pin pin);
static uint8_t _get_input(MM32GPIO_GPIO_Pin pin);

static void _start(swiic_dev* dev);
static void _stop(swiic_dev* dev);
static void _send_ack(swiic_dev* dev, swiic_ack ack);
static swiic_ack _get_ack(swiic_dev* dev);

static swiic_ack _send_byte(swiic_dev* dev, uint8_t byte);
static uint8_t _read_byte(swiic_dev* dev, swiic_ack ack);

static swiic_ack _IIC_write(swiic_dev* dev, uint8_t* pdata, size_t size);
static swiic_ack _IIC_read(swiic_dev* dev, uint8_t* pdata, size_t size);

swiic_dev SWIICInit(MM32GPIO_GPIO_Pin scl, MM32GPIO_GPIO_Pin sda, uint32_t baudrate)
{
    extern unsigned int SystemCoreClock;

    swiic_dev dev;
    dev.delaytime = SystemCoreClock/(baudrate*2);
    dev.scl = scl;
    dev.sda = sda;
    dev.slaveaddr = 0xfe;
    _set_output(dev.scl);
    _set_output(dev.sda);
    _set_high(dev.scl);
    _set_high(dev.sda);
    return dev;
}

void SWIICWrite(swiic_dev* dev, uint8_t slaveaddr, uint8_t* pdata, size_t size)
{
    dev->slaveaddr = slaveaddr;
    _IIC_write(dev,pdata,size);
}

void SWIICRead(swiic_dev* dev, uint8_t slaveaddr, uint8_t* pdata, size_t size)
{
    dev->slaveaddr = slaveaddr;
    _IIC_read(dev,pdata,size);
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


static void _start(swiic_dev* dev)
{
    _set_high(dev->scl);
    _set_high(dev->sda);
    _delay(dev->delaytime);
    _set_low(dev->sda);
    _delay(dev->delaytime);
    _set_low(dev->scl);
    _delay(dev->delaytime);
}

static void _stop(swiic_dev* dev)
{
    _set_low(dev->scl);
    _set_low(dev->sda);
    _delay(dev->delaytime);
    _set_high(dev->scl);
    _delay(dev->delaytime);
    _set_high(dev->sda);
}

static void _send_ack(swiic_dev* dev, swiic_ack ack)
{
    _set_low(dev->scl);
    _delay(dev->delaytime);
    if(ack==ACK)_set_low(dev->sda);
    else _set_high(dev->sda);
    _set_high(dev->scl);
    _delay(dev->delaytime);
    _set_low(dev->scl);
    _delay(dev->delaytime);
}

static swiic_ack _get_ack(swiic_dev* dev)
{
    //_set_low(dev->scl);
    _set_input(dev->sda);
    //_delay(dev->delaytime);
    _set_high(dev->scl);
    _delay(dev->delaytime);
    if(_get_input(dev->sda))
    {
        _set_output(dev->sda);
        _set_low(dev->scl);
        _delay(dev->delaytime);
        return NACK;
    }
    else
    {
        _set_output(dev->sda);
        _set_low(dev->scl);
        _delay(dev->delaytime);
        return ACK;
    }
}

static swiic_ack _send_byte(swiic_dev* dev, uint8_t byte)
{
    for(uint8_t i = 0; i < 8 ; i++)
    {
        if(byte & 0x80) _set_high(dev->sda);
        else _set_low(dev->sda);
        byte <<= 1;
        //_delay(dev->delaytime);
        _set_high(dev->scl);
        _delay(dev->delaytime);
        _set_low(dev->scl);
        _delay(dev->delaytime);
    }
    return _get_ack(dev);
}

static uint8_t _read_byte(swiic_dev* dev, swiic_ack ack)
{
    uint8_t byte = 0;
    //_set_high(dev->scl);
    _set_input(dev->sda);
    for(uint8_t i = 0; i < 8 ; i++)
    {
        byte<<=1;
        _set_high(dev->scl);
        _delay(dev->delaytime);
        if(_get_input(dev->sda))byte+=1;
        if(i==7)break;
        _set_low(dev->scl);
        _delay(dev->delaytime);
    }
    _set_output(dev->sda);
    _send_ack(dev,ack);
    return byte;
}

static swiic_ack _IIC_write(swiic_dev* dev, uint8_t* pdata, size_t size)
{
    _start(dev);
    if(_send_byte(dev,(dev->slaveaddr<<1)|0x00)==NACK)
    {
        _stop(dev);
        return NACK;
    }
    for(size_t i = 0; i < size ; i++)
    {
        _send_byte(dev,pdata[i]);
    }
    _stop(dev);
    return ACK;
}

static swiic_ack _IIC_read(swiic_dev* dev, uint8_t* pdata, size_t size)
{
    _start(dev);
    if(_send_byte(dev,(dev->slaveaddr<<1)|0x01)==NACK)
    {
        _stop(dev);
        return NACK;
    }
    for(size_t i = 0; i < size-1 ; i++)
    {
        pdata[i] = _read_byte(dev,ACK);
    }
    pdata[size-1] = _read_byte(dev,NACK);
    _stop(dev);
    return ACK;
}