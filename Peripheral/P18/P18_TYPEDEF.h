#ifndef _P18_TYPEDEF_H_
#define _P18_TYPEDEF_H_

#include "MM32_UART.h"
#include "UART_Upload.h"

#define MAXPACKSIZE (255)

#define STARTBYTE   ((uint8_t)0XAA)

typedef enum _uartcmd
{
  SET_CH_VOLT = (uint8_t)0,
  SET_CH_SHIFT = 1,
  SET_ALL_VOLT = 2,
  SET_ALL_SHIFT = 3,
  SET_ALL_ZERO = 4,
  
  READ_CH_VOLT = 5,
  READ_CH_SHIFT = 6,
  RTREAD_CH_VOLT = 7,
  RTREAD_CH_SHIFT = 8,
  RTREAD_ALL_VOLT = 9,
  RTREAD_ALL_SHIFT = 10,
  RTREAD_STOP = 11,
  
  FWAVE_CH_VOLT = 12,
  FWAVE_CH_SHIFT = 13,
  FWAVE_CH_STOP = 14,
  
  SWAVE_CH_VOLT = 15,
  SWAVE_CH_SHIFT = 16,
  SWAVE_CH_STOP = 17,
  
  CTRL_SET_LOOP = 18,
  CTRL_READ_LOOP = 19,
  CTRL_TOGGLE_AD = 20,
  CTRL_READ_AD = 21,
  
  READ_CH_LOAD = 25,
  READ_CH_SHIFTLIMH = 27,
  READ_CH_POWER = 29,
  READ_SYS_VOLTLIML = 31,
  READ_SYS_VOLTLIMH = 33,
  READ_SYS_SHIFTLIML = 35,
  
  PID_STARTSTOP = 36,
  PID_SET_PID = 37,
  PID_READ_PID = 38,
  
  READ_ADDRESS = 47,
  
  RTREAD_DATA_M = 48,
  RTREAD_DATA_S = 49,
  
  READ_DATA_S = 51,
  
  PID_READ_STATUS = 60,
  
  CONFIG_BAUD = 63,
  
  //TODO:��·��λ�ɵ�����
}P18_uartCmd_t;

typedef enum _channel
{
  CHANNEL0 = (uint8_t)0,
  CHANNEL1 = 1,
  CHANNEL2 = 2,
}P18_channel_t;

typedef enum _wave
{
  SINWAVE = 'Z',
  SQUAREWAVE = 'F',
  TRANGLEWAVE = 'S',
  SAWWAVE = 'J',
}P18_wave_t;

typedef enum _loop
{
  OPENLOOP = 'O',
  CLOSELOOP = 'C',
}P18_loop_t;

typedef enum _ADstatus
{
  ANALOG = 'A',
  DIGITAL = 'D',
}P18_ADstatus_t;

typedef enum _effect
{
  EFFECT = 'Y',
  INEFFECT = 'N',
}P18_effect_t;

typedef enum _baud
{
  BAUD_9600 = 'A',
  BAUD_19200 = 'B',
  BAUD_38400 = 'C',
  BAUD_57600 = 'D',
  BAUD_76800 = 'E',
  BAUD_115200 = 'F',
  BAUD_128000 = 'G',
  BAUD_230400 = 'H',
  BAUD_256000 = 'I',
}P18_baud_t;

typedef enum _pidstatus
{
  RUN = 'R',
  STOP = 'H',
}P18_PIDstatus_t;

typedef enum _select
{
  VOLTAGE = (uint8_t)0,
  SHITF = 1,
}P18_select_t;

typedef float P18_voltage_t ;

typedef float P18_shitf_t ;

typedef float P18_load_t ;

typedef float P18_power_t ;

typedef struct _p18dev
{
  uint8_t addr;
  
  P18_loop_t loopStatus[3];
  P18_ADstatus_t ADStatus[3];
  
  P18_voltage_t voltage[3];
  P18_voltage_t voltage_limh[3];
  P18_voltage_t voltage_liml[3];
  
  P18_shitf_t shift[3];
  P18_shitf_t shift_limh[3];
  P18_shitf_t shift_liml[3];
  
  P18_load_t load[3];
  P18_power_t power[3];
  
  float P[3];
  float I[3];
  float D[3];

  uint8_t fbTime;
  int baud;
}P18_device_t;

typedef struct _p18save
{
    float P[3];
    float I[3];
    float D[3];

    uint8_t fbTime;
    int baud;
}P18_save_t;

extern P18_device_t P18_device;

#endif