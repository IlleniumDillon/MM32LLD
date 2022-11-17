#include "P18_CMD.h"

const uint8_t packSizeList[77] = {11,11,18,18,6,7,7,8,8,7,7,6,20,20,6,20,20,7,
                          8,7,8,7,8,7,11,7,11,7,11,7,10,6,10,6,10,6,8,19,7,
                           0,0,0,0,0,0,0,0,6,
                          8,7,8,6,6,6,7,8,7,7,10,6,6,8,6,7,7,6,
                          24,24,7,6,0,11,8,12,11,9,7};//TODO:补齐整包长度列表

uint8_t pack[256] = {0};

static void _packpack(P18_uartCmd_t cmd, uint8_t* payload)
{
  pack[0] = 0XAA;
  pack[1] = P18_device.addr;
  pack[2] = packSizeList[cmd];
  pack[3] = cmd;
  pack[4] = 0;
  for(uint8_t i = 5; i < packSizeList[cmd]-1; i++)
  {
    pack[i] = payload[i-5];
  }
  pack[packSizeList[cmd]-1] = pack[0];
  for(uint8_t i = 1; i < packSizeList[cmd]-1; i++)
  {
    pack[packSizeList[cmd]-1] = pack[packSizeList[cmd]-1]^pack[i];
  }
}

static void _cvtFloat2Fix(uint8_t* dst, float data)
{
  int fix = 0;
  if(data<0)
  {
    data = -data;
    fix = (int)data;
    dst[0] = fix/256+0x80;
    dst[1] = fix%256;
    fix = (int)((data-fix)*10000);
    dst[2] = fix/256;
    dst[3] = fix%256;
  }
  else
  {
    fix = (int)data;
    dst[0] = fix/256;
    dst[1] = fix%256;
    fix = (int)((data-fix+0.000001)*10000);
    dst[2] = fix/256;
    dst[3] = fix%256;
  }
}

void P18_setChannelVoltage(P18_channel_t channel,
                          P18_voltage_t voltage)
{
  uint8_t payload[5];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  //memcpy(payload+1,&voltage,sizeof(int));
  _cvtFloat2Fix(payload+1,voltage);
  _packpack(SET_CH_VOLT,payload);
  P18_uartWrite(pack,packSizeList[SET_CH_VOLT]);
}

void P18_setChannelShift(P18_channel_t channel,
                         P18_shitf_t shift)
{
  uint8_t payload[5];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  //memcpy(payload+1,&shift,sizeof(int));
  _cvtFloat2Fix(payload+1,shift);
  _packpack(SET_CH_SHIFT,payload);
  P18_uartWrite(pack,packSizeList[SET_CH_SHIFT]);
}

void P18_setAllChannelVoltage(P18_voltage_t voltage_ch0,
                              P18_voltage_t voltage_ch1,
                              P18_voltage_t voltage_ch2)
{
  uint8_t payload[12];
  //memcpy(payload,&voltage_ch0,sizeof(int));
  _cvtFloat2Fix(payload,voltage_ch0);
  //memcpy(payload+4,&voltage_ch1,sizeof(int));
  _cvtFloat2Fix(payload+4,voltage_ch1);
  //memcpy(payload+8,&voltage_ch2,sizeof(int));
  _cvtFloat2Fix(payload+8,voltage_ch2);
  _packpack(SET_ALL_VOLT,payload);
  P18_uartWrite(pack,packSizeList[SET_ALL_VOLT]);
}

void P18_setAllChannelShift(P18_shitf_t shift_ch0,
                            P18_shitf_t shift_ch1,
                            P18_shitf_t shift_ch2)
{
  uint8_t payload[12];
  //memcpy(payload,&shift_ch0,sizeof(int));
  _cvtFloat2Fix(payload,shift_ch0);
  //memcpy(payload+4,&shift_ch1,sizeof(int));
  _cvtFloat2Fix(payload+4,shift_ch1);
  //memcpy(payload+8,&shift_ch2,sizeof(int));
  _cvtFloat2Fix(payload+8,shift_ch2);
  _packpack(SET_ALL_SHIFT,payload);
  P18_uartWrite(pack,packSizeList[SET_ALL_SHIFT]);
}

void P18_setAllChannelSetZero(void)
{
  _packpack(SET_ALL_ZERO,NULL);
  P18_uartWrite(pack,packSizeList[SET_ALL_ZERO]);
}

void P18_readChannelVoltage(P18_channel_t channel)
{
  _packpack(READ_CH_VOLT,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[READ_CH_VOLT]);
}

void P18_readChannelShift(P18_channel_t channel)
{
  _packpack(READ_CH_SHIFT,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[READ_CH_SHIFT]);
}

void P18_readChannelVoltageRealtime(P18_channel_t channel,
                                    uint8_t period_ms)
{
  uint8_t payload[2];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  memcpy(payload+1,&period_ms,sizeof(uint8_t));
  _packpack(RTREAD_CH_VOLT,payload);
  P18_uartWrite(pack,packSizeList[RTREAD_CH_VOLT]);
}

void P18_readChannelShiftRealtime(P18_channel_t channel,
                                  uint8_t period_ms)
{
  uint8_t payload[2];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  memcpy(payload+1,&period_ms,sizeof(uint8_t));
  _packpack(RTREAD_CH_SHIFT,payload);
  P18_uartWrite(pack,packSizeList[RTREAD_CH_SHIFT]);
}

void P18_readAllChannelVoltageRealtime(uint8_t period_ms)
{
  _packpack(RTREAD_ALL_VOLT,&period_ms);
  P18_uartWrite(pack,packSizeList[RTREAD_ALL_VOLT]);
}

void P18_readAllChannelShiftRealtime(uint8_t period_ms)
{
  _packpack(RTREAD_ALL_SHIFT,&period_ms);
  P18_uartWrite(pack,packSizeList[RTREAD_ALL_SHIFT]);
}

void P18_readRealtimeStop(void)
{
  _packpack(RTREAD_STOP,NULL);
  P18_uartWrite(pack,packSizeList[RTREAD_STOP]);
}

void P18_setChannelFastVoltageWave(P18_channel_t channel,
                                   P18_wave_t wavetype,
                                   float PPvalue,
                                   float freq,
                                   float offset)
{
  uint8_t payload[14];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  memcpy(payload+1,&wavetype,sizeof(P18_wave_t));
  //memcpy(payload+2,&PPvalue,sizeof(int));
  _cvtFloat2Fix(payload+2,PPvalue);
  //memcpy(payload+6,&freq,sizeof(int));
  _cvtFloat2Fix(payload+6,freq);
  //memcpy(payload+10,&offset,sizeof(int));
  _cvtFloat2Fix(payload+10,offset);
  _packpack(FWAVE_CH_VOLT,payload);
  P18_uartWrite(pack,packSizeList[FWAVE_CH_VOLT]);
}

void P18_setChannelFastShiftWave(P18_channel_t channel,
                                 P18_wave_t wavetype,
                                 float PPvalue,
                                 float freq,
                                 float offset)
{
  uint8_t payload[14];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  memcpy(payload+1,&wavetype,sizeof(P18_wave_t));
  //memcpy(payload+2,&PPvalue,sizeof(int));
  _cvtFloat2Fix(payload+2,PPvalue);
  //memcpy(payload+6,&freq,sizeof(int));
  _cvtFloat2Fix(payload+6,freq);
  //memcpy(payload+10,&offset,sizeof(int));
  _cvtFloat2Fix(payload+10,offset);
  _packpack(FWAVE_CH_SHIFT,payload);
  P18_uartWrite(pack,packSizeList[FWAVE_CH_SHIFT]);
}

void P18_setChannelFastWaveStop(void)
{
  _packpack(FWAVE_CH_STOP,NULL);
  P18_uartWrite(pack,packSizeList[FWAVE_CH_STOP]);
}

void P18_setMultChannelVoltageWave(P18_channel_t channel,
                                   P18_wave_t wavetype,
                                   float PPvalue,
                                   float freq,
                                   float offset)

{
  uint8_t payload[14];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  memcpy(payload+1,&wavetype,sizeof(P18_wave_t));
  //memcpy(payload+2,&PPvalue,sizeof(int));
  _cvtFloat2Fix(payload+2,PPvalue);
  //memcpy(payload+6,&freq,sizeof(int));
  _cvtFloat2Fix(payload+6,freq);
  //memcpy(payload+10,&offset,sizeof(int));
  _cvtFloat2Fix(payload+10,offset);
  _packpack(SWAVE_CH_VOLT,payload);
  P18_uartWrite(pack,packSizeList[SWAVE_CH_VOLT]);
}

void P18_setMultChannelShiftWave(P18_channel_t channel,
                                 P18_wave_t wavetype,
                                 float PPvalue,
                                 float freq,
                                 float offset)
{
  uint8_t payload[14];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  memcpy(payload+1,&wavetype,sizeof(P18_wave_t));
  //memcpy(payload+2,&PPvalue,sizeof(int));
  _cvtFloat2Fix(payload+2,PPvalue);
  //memcpy(payload+6,&freq,sizeof(int));
  _cvtFloat2Fix(payload+6,freq);
  //memcpy(payload+10,&offset,sizeof(int));
  _cvtFloat2Fix(payload+10,offset);
  _packpack(SWAVE_CH_SHIFT,payload);
  P18_uartWrite(pack,packSizeList[SWAVE_CH_SHIFT]);
}

void P18_setMultChannelWaveStop(P18_channel_t channel)
{
  _packpack(FWAVE_CH_STOP,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[FWAVE_CH_STOP]);
}

void P18_setChannelLoopStatus(P18_channel_t channel,
                              P18_loop_t loop)
{
  uint8_t payload[2] = {channel,loop};
  _packpack(CTRL_SET_LOOP,payload);
  P18_uartWrite(pack,packSizeList[CTRL_SET_LOOP]);
}

void P18_readChannelLoopStatus(P18_channel_t channel)
{
  _packpack(CTRL_READ_LOOP,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[CTRL_READ_LOOP]);
}

void P18_setChannelADStatus(P18_channel_t channel,
                            P18_ADstatus_t ADstatus)
{
  uint8_t payload[2] = {channel,ADstatus};
  _packpack(CTRL_TOGGLE_AD,payload);
  P18_uartWrite(pack,packSizeList[CTRL_TOGGLE_AD]);
}

void P18_readChannelADStatus(P18_channel_t channel)
{
  _packpack(CTRL_READ_AD,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[CTRL_READ_AD]);
}

void P18_readChannelLoad(P18_channel_t channel)
{
  _packpack(READ_CH_LOAD,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[READ_CH_LOAD]);
}

void P18_readChannelShiftLimH(P18_channel_t channel)
{
  _packpack(READ_CH_SHIFTLIMH,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[READ_CH_SHIFTLIMH]);
}

void P18_readChannelPower(P18_channel_t channel)
{
  _packpack(READ_CH_POWER,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[READ_CH_POWER]);
}

void P18_readSysVoltageLimL(void)
{
  _packpack(READ_SYS_VOLTLIML,NULL);
  P18_uartWrite(pack,packSizeList[READ_SYS_VOLTLIML]);
}

void P18_readSysVoltageLimH(void)
{
  _packpack(READ_SYS_VOLTLIMH,NULL);
  P18_uartWrite(pack,packSizeList[READ_SYS_VOLTLIMH]);
}

void P18_readSysShiftLimL(void)
{
  _packpack(READ_SYS_SHIFTLIML,NULL);
  P18_uartWrite(pack,packSizeList[READ_SYS_SHIFTLIML]);
}

void P18_setPIDStatus(P18_channel_t channel,
                      P18_PIDstatus_t status)
{
  uint8_t payload[2] = {channel,status};
  _packpack(PID_STARTSTOP,payload);
  P18_uartWrite(pack,packSizeList[PID_STARTSTOP]);
}

void P18_setPIDParamma(P18_channel_t channel,
                       float P,
                       float I,
                       float D)
{
  uint8_t payload[13];
  memcpy(payload,&channel,sizeof(P18_channel_t));
  //memcpy(payload+1,&P,sizeof(float));
  _cvtFloat2Fix(payload+1,P);
  //memcpy(payload+5,&I,sizeof(float));
  _cvtFloat2Fix(payload+5,I);
  //memcpy(payload+9,&D,sizeof(float));
  _cvtFloat2Fix(payload+9,D);
  _packpack(PID_SET_PID,payload);
  P18_uartWrite(pack,packSizeList[PID_SET_PID]);
}

void P18_readPIDParamma(P18_channel_t channel)
{
  _packpack(PID_READ_PID,(uint8_t*)&channel);
  P18_uartWrite(pack,packSizeList[PID_READ_PID]);
}

void P18_readAddress(void)
{
  _packpack(READ_ADDRESS,NULL);
  P18_uartWrite(pack,packSizeList[READ_ADDRESS]);
}

void P18_readSelectedDataRealtime(uint8_t period_ms,
                                  uint8_t flag)
{
  uint8_t payload[2] = {period_ms,flag};
  _packpack(RTREAD_DATA_M,payload);
  P18_uartWrite(pack,packSizeList[RTREAD_DATA_M]);
}

void P18_readDataRealtime(uint8_t period_ms)
{
  _packpack(RTREAD_DATA_S,&period_ms);
  P18_uartWrite(pack,packSizeList[RTREAD_DATA_S]);
}

void P18_readAllChannelData(void)
{
  _packpack(READ_DATA_S,NULL);
  P18_uartWrite(pack,packSizeList[READ_DATA_S]);
}

void P18_readPIDStatus(void)
{
  _packpack(PID_READ_STATUS,NULL);
  P18_uartWrite(pack,packSizeList[PID_READ_STATUS]);
}

void P18_setBaud(P18_baud_t baud)
{
  _packpack(CONFIG_BAUD,(uint8_t*)&baud);
  P18_uartWrite(pack,packSizeList[CONFIG_BAUD]);
}