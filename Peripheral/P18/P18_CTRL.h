#ifndef _P18_CTRL_H_
#define _P18_CTRL_H_

#include "P18_CMD.h"

typedef enum pid_type_t
{
    positional_pid = 0, //位置式
    increment_pid,      //增量式
}PID_TYPE_T;

typedef struct pidCfg_t
{
    PID_TYPE_T type;
    float output;
    float error;
    float error_1;
    float error_2;
    float target;
    float current;
    float kp;
    float ki;
    float kd;
    float T;     //控制周期
    float sum_e; //位置式用e的积分
    float s_max;
    float s_min;
} PIDCFG_T;

extern PIDCFG_T P18_X,P18_Y,P18_Z;

extern float target_X;
extern float target_Y;
extern float target_Z;

void P18_devCheck(void);

void P18_devInit(void);

void P18_ctrlCallBack(void);

#endif