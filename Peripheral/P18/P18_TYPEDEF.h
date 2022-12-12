#ifndef _P18_TYPEDEF_H_
#define _P18_TYPEDEF_H_

#include "MM32_UART.h"
#include "UART_Upload.h"

/*发送数据包的最大容量*/
#define MAXPACKSIZE (255)

/*帧头*/
#define STARTBYTE   ((uint8_t)0XAA)

/**
 * @brief P18平台UART指令枚举
 */
typedef enum _uartcmd
{
  SET_CH_VOLT = (uint8_t)0,     //设定一个通道的电压
  SET_CH_SHIFT = 1,             //设定一个通道的位移
  SET_ALL_VOLT = 2,             //设定所有通道的电压
  SET_ALL_SHIFT = 3,            //设定所有通道的位移
  SET_ALL_ZERO = 4,             //多路清零
  
  READ_CH_VOLT = 5,             //读单路电压
  READ_CH_SHIFT = 6,            //读单路位移
  RTREAD_CH_VOLT = 7,           //实时读单路电压
  RTREAD_CH_SHIFT = 8,          //实时读单路位移
  RTREAD_ALL_VOLT = 9,          //实时读多路电压
  RTREAD_ALL_SHIFT = 10,        //实时读多路位移
  RTREAD_STOP = 11,             //停止实时读数据
  
  FWAVE_CH_VOLT = 12,           //发单路高速电压波形
  FWAVE_CH_SHIFT = 13,          //发单路高速位移波形
  FWAVE_CH_STOP = 14,           //停单路高速波形
  
  SWAVE_CH_VOLT = 15,           //发单路并发电压波形
  SWAVE_CH_SHIFT = 16,          //发单路并发位移波形
  SWAVE_CH_STOP = 17,           //停单路并发波形
  
  CTRL_SET_LOOP = 18,           //设置通道开闭环
  CTRL_READ_LOOP = 19,          //读通道开闭环设置
  CTRL_TOGGLE_AD = 20,          //设置通道模拟/数字控制
  CTRL_READ_AD = 21,            //读通道模拟/数字控制
  
  READ_CH_LOAD = 25,            //读通道负载
  READ_CH_SHIFTLIMH = 27,       //读通道位移高限
  READ_CH_POWER = 29,           //读通道功率
  READ_SYS_VOLTLIML = 31,       //读系统电压低限
  READ_SYS_VOLTLIMH = 33,       //读系统电压高限
  READ_SYS_SHIFTLIML = 35,      //读系统位移低限
  
  PID_STARTSTOP = 36,           //设置通道启停PID
  PID_SET_PID = 37,             //设置PID参数
  PID_READ_PID = 38,            //读PID参数
  
  READ_ADDRESS = 47,            //读驱动器地址
  
  RTREAD_DATA_M = 48,           //实时读数据（上位机指定内容）
  RTREAD_DATA_S = 49,           //实时读数据（下位机指定内容）
  
  READ_DATA_S = 51,             //读多路电压或位移
  
  PID_READ_STATUS = 60,         //读数字PID状态
  
  CONFIG_BAUD = 63,             //设置波特率
  
  /// @todo 补全指令
}P18_uartCmd_t;

/**
 * @brief P18平台通道枚举
 */
typedef enum _channel
{
  CHANNEL0 = (uint8_t)0,
  CHANNEL1 = 1,
  CHANNEL2 = 2,
}P18_channel_t;

/**
 * @brief 发送波形类型枚举
 */
typedef enum _wave
{
  SINWAVE = 'Z',                //正弦波
  SQUAREWAVE = 'F',             //方波
  TRANGLEWAVE = 'S',            //三角波
  SAWWAVE = 'J',                //锯齿波
}P18_wave_t;

/**
 * @brief 设置开闭环状态枚举
 */
typedef enum _loop
{
  OPENLOOP = 'O',               //开环
  CLOSELOOP = 'C',              //闭环
}P18_loop_t;

/**
 * @brief 设置数字/模拟状态枚举
 */
typedef enum _ADstatus
{
  ANALOG = 'A',                 //模拟输入
  DIGITAL = 'D',                //数字输入
}P18_ADstatus_t;

/**
 * @brief 生效状态枚举
 */
typedef enum _effect
{
  EFFECT = 'Y',                 //有效
  INEFFECT = 'N',               //无效
}P18_effect_t;

/**
 * @brief 支持的波特率枚举
 */
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

/**
 * @brief PID启停状态枚举
 */
typedef enum _pidstatus
{
  RUN = 'R',                    //启用PID
  STOP = 'H',                   //停止PID
}P18_PIDstatus_t;

/**
 * @brief 电压/位移选择枚举
 */
typedef enum _select
{
  VOLTAGE = (uint8_t)0,         //选择电压
  SHITF = 1,                    //选择位移
}P18_select_t;

/*通道电压数据类型*/
typedef float P18_voltage_t ;

/*通道位移数据类型*/
typedef float P18_shitf_t ;

/*通道负载数据类型*/
typedef float P18_load_t ;

/*通道功率数据类型*/
typedef float P18_power_t ;

/**
 * @brief P18设备结构体定义
 */
typedef struct _p18dev
{
  uint8_t addr;                   //设备地址
  
  P18_loop_t loopStatus[3];       //三个通道的开闭环状态
  P18_ADstatus_t ADStatus[3];     //三个通道的数模状态
  
  P18_voltage_t voltage[3];       //三个通道读电压数据
  P18_voltage_t voltage_limh[3];  //三个通道的电压高限
  P18_voltage_t voltage_liml[3];  //三个通道的电压低限
  
  P18_shitf_t shift[3];           //三个通道读位移数据
  P18_shitf_t shift_limh[3];      //三个通道位移高限
  P18_shitf_t shift_liml[3];      //三个通道位移低限
  
  P18_load_t load[3];             //三个通道的负载
  P18_power_t power[3];           //三个通道的功率
  
  float P[3];                     //三个通道的PID参数
  float I[3];
  float D[3];

  uint8_t fbTime;                 //实时读数周期（ms）
  int baud;                       //波特率
}P18_device_t;

/**
 * @brief P18配置参数保存结构体
 */
typedef struct _p18save
{
    float P[3];                   //三个通道的PID参数
    float I[3];
    float D[3];

    uint8_t fbTime;               //实时读数周期（ms）
    int baud;                     //波特率
}P18_save_t;

/*P18设备结构体*/
extern P18_device_t P18_device;

#endif