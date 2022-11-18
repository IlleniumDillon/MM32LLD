/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 21:33:38
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-18 10:29:59
 * @FilePath: \CODE\Peripheral\P18\P18_CTRL.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "P18_CTRL.h"

PIDCFG_T P18_X = {0};
PIDCFG_T P18_Y = {0};
PIDCFG_T P18_Z = {0};

float target_X = 20;
float target_Y = 0;
float target_Z = 0;

void P18_ctrlStateUpdate(void)
{
  P18_X.target = target_X;
  P18_Y.target = target_Y;
  P18_Z.target = target_Z;
  P18_X.current = P18_device.shift[0];
  P18_Y.current = P18_device.shift[1];
  P18_Z.current = P18_device.shift[2];
}

float P18_ctrlCtrlUpdate(PIDCFG_T* pid,uint8_t ch)
{
  pid->kp = P18_device.P[ch];
  pid->ki = P18_device.I[ch];
  pid->kd = P18_device.D[ch];
  pid->T = 1;
  pid->error = pid->target - pid->current;
  pid->output = pid->kp * pid->error + pid->kd * ((pid->error - pid->error_1) / pid->T);
  pid->error_2 = pid->error_1;
  pid->error_1 = pid->error;
  
  if(pid->output < 0) pid->output = 0;
  if(pid->output > 250)pid->output = 250;
  
  return pid->output / 200 * 90;
}

void P18_devCheck(void)
{
  while(P18_device.addr==0)
  {
    P18_readAddress();
  }
}

void P18_devInit(void)
{
  //读各个通道电压和位移限制
  for(int i = 0; i < 100000; i++);
  P18_readChannelShiftLimH(CHANNEL0);
  for(int i = 0; i < 100000; i++);
  P18_readChannelShiftLimH(CHANNEL1);
  for(int i = 0; i < 100000; i++);
  P18_readChannelShiftLimH(CHANNEL2);
  for(int i = 0; i < 100000; i++);
  P18_readSysVoltageLimL();
  P18_readSysVoltageLimH();
  P18_readSysShiftLimL();
  //设置各个通道开环
  P18_setChannelLoopStatus(CHANNEL0,OPENLOOP);
  P18_setChannelLoopStatus(CHANNEL1,OPENLOOP);
  P18_setChannelLoopStatus(CHANNEL2,OPENLOOP);
  //设置各个通道数字控制
  P18_setChannelADStatus(CHANNEL0,DIGITAL);
  P18_setChannelADStatus(CHANNEL1,DIGITAL);
  P18_setChannelADStatus(CHANNEL2,DIGITAL);
}

void P18_ctrlCallBack(void)
{
  //systick_start();
  //uint32 time = systick_getval_ns();
  P18_ctrlStateUpdate();
  P18_setAllChannelVoltage(
                           /*50,*/P18_ctrlCtrlUpdate(&P18_X,0),
                           50,//P18_ctrlCtrlUpdate(&P18_Y,1),
                           0//P18_ctrlCtrlUpdate(&P18_Z)
                             );
  float var[2] = {P18_X.current,P18_Y.current};
  UART_floatVarUpload(UART2,var,2);
  //uint32 time = systick_getval_ns();
}

void P18_ctrlAnalogCallBack(void)
{
  P18_X.current = P18_getShiftFromADC(CHANNEL0);
  P18_Y.current = P18_getShiftFromADC(CHANNEL1);
  P18_X.target = target_X;
  P18_Y.target = target_Y;

  float voltage1 = P18_ctrlCtrlUpdate(&P18_X, CHANNEL0);
  float voltage2 = P18_ctrlCtrlUpdate(&P18_Y, CHANNEL1);

  P18_setVoltageToDAC(voltage1, voltage2);
}