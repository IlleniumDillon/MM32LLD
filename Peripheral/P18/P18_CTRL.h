/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 21:33:38
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-22 13:54:29
 * @FilePath: \CODE\Peripheral\P18\P18_CTRL.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _P18_CTRL_H_
#define _P18_CTRL_H_

#include "P18_CMD.h"
#include "P18_Analog.h"
#include "tf.h"

/**
 * @brief PID形式枚举
 */
typedef enum pid_type_t
{
    positional_pid = 0, //位置式
    increment_pid,      //增量式
}PID_TYPE_T;

/**
 * @brief PID数据结构体
 */
typedef struct pidCfg_t
{
    PID_TYPE_T type;    //PID形式
    float output;       //输出   
    float error;        //偏差
    float error_1;      //上一时刻偏差
    float error_2;      //上上时刻偏差
    float target;       //目标值
    float current;      //当前值
    float kp;           //
    float ki;           //
    float kd;           //
    float T;            //控制周期
    float sum_e;        //位置式用e的积分
    float s_max;        //积分限幅
    float s_min;
} PIDCFG_T;

/*PID结构体*/
extern PIDCFG_T P18_X,P18_Y,P18_Z;
/*X通道目标*/
extern float target_X;
/*Y通道目标*/
extern float target_Y;
/*Z通道目标*/
extern float target_Z;
/*反馈数据更新标记*/
extern uint8_t transeFlag;

/**
 * @description: 检测P18设备是否正确连接
 * @return {*}
 */
void P18_devCheck(void);

/**
 * @description: 通信接口初始化
 * @return {*}
 */
void P18_devInit(void);

/**
 * @description: 数字控制回调函数
 * @return {*}
 */
void P18_ctrlCallBack(void);

/**
 * @description: 模拟控制回调函数
 * @return {*}
 */
void P18_ctrlAnalogCallBack(void);

#endif