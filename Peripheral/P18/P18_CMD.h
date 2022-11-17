#ifndef _P18_CMD_H_
#define _P18_CMD_H_

#include "P18_TYPEDEF.h"
#include "P18_UART.h"
#include <stdarg.h>
#include <string.h>

void P18_setChannelVoltage(P18_channel_t channel,
                          P18_voltage_t voltage);

void P18_setChannelShift(P18_channel_t channel,
                         P18_shitf_t shift);

void P18_setAllChannelVoltage(P18_voltage_t voltage_ch0,
                              P18_voltage_t voltage_ch1,
                              P18_voltage_t voltage_ch2);

void P18_setAllChannelShift(P18_shitf_t shift_ch0,
                            P18_shitf_t shift_ch1,
                            P18_shitf_t shift_ch2);

void P18_setAllChannelSetZero(void);

void P18_readChannelVoltage(P18_channel_t channel);

void P18_readChannelShift(P18_channel_t channel);

void P18_readChannelVoltageRealtime(P18_channel_t channel,
                                    uint8_t period_ms);

void P18_readChannelShiftRealtime(P18_channel_t channel,
                                  uint8_t period_ms);

void P18_readAllChannelVoltageRealtime(uint8_t period_ms);

void P18_readAllChannelShiftRealtime(uint8_t period_ms);

void P18_readRealtimeStop(void);

void P18_setChannelFastVoltageWave(P18_channel_t channel,
                                   P18_wave_t wavetype,
                                   float PPvalue,
                                   float freq,
                                   float offset);

void P18_setChannelFastShiftWave(P18_channel_t channel,
                                 P18_wave_t wavetype,
                                 float PPvalue,
                                 float freq,
                                 float offset);

void P18_setChannelFastWaveStop(void);

void P18_setMultChannelVoltageWave(P18_channel_t channel,
                                   P18_wave_t wavetype,
                                   float PPvalue,
                                   float freq,
                                   float offset);

void P18_setMultChannelShiftWave(P18_channel_t channel,
                                 P18_wave_t wavetype,
                                 float PPvalue,
                                 float freq,
                                 float offset);

void P18_setMultChannelWaveStop(P18_channel_t channel);

void P18_setChannelLoopStatus(P18_channel_t channel,
                              P18_loop_t loop);

void P18_readChannelLoopStatus(P18_channel_t channel);

void P18_setChannelADStatus(P18_channel_t channel,
                            P18_ADstatus_t ADstatus);

void P18_readChannelADStatus(P18_channel_t channel);

void P18_readChannelLoad(P18_channel_t channel);

void P18_readChannelShiftLimH(P18_channel_t channel);

void P18_readChannelPower(P18_channel_t channel);

void P18_readSysVoltageLimL(void);

void P18_readSysVoltageLimH(void);

void P18_readSysShiftLimL(void);

void P18_setPIDStatus(P18_channel_t channel,
                      P18_PIDstatus_t status);

void P18_setPIDParamma(P18_channel_t channel,
                       float P,
                       float I,
                       float D);

void P18_readPIDParamma(P18_channel_t channel);

void P18_readAddress(void);

void P18_readSelectedDataRealtime(uint8_t period_ms,
                                  uint8_t flag);

void P18_readDataRealtime(uint8_t period_ms);

void P18_readAllChannelData(void);

void P18_readPIDStatus(void);

void P18_setBaud(P18_baud_t baud);

#endif