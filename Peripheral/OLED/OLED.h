/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 20:39:51
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-24 10:58:41
 * @FilePath: \CODE\Peripheral\OLED\OLED.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _OLED_H_
#define _OLED_H_

#include <stdarg.h>
#include <string.h>

#include "MM32_SPI.h"
#include "MM32_GPIO.h"
#include "OLED_Font.h"
#include "MM32_PIT.h"
#include "SWSPI.h"

//需要更新标志
extern uint8_t oled_refresh;

/**
 * @description: 初始化OLED
 * @return {*}
 */
void OLED_init(void);

/**
 * @description: 发送指令
 * @param {uint8_t} cmd 指令
 * @return {*}
 */
void OLED_WrtCmd(uint8_t cmd);

/**
 * @description: 发送数据
 * @param {uint8_t} data    数据
 * @return {*}
 */
void OLED_WrtData(uint8_t data);

/**
 * @description: 清屏
 * @param {uint8_t} data 0x00全灭、0xff全亮
 * @return {*}
 */
void OLED_Fill(uint8_t data);

/**
 * @description: 移动光标
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @return {*}
 */
void OLED_SetPos(uint8_t x, uint8_t y);

/**
 * @description: 设置一组8像素的数据
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {uint8_t} data    数据
 * @return {*}
 */
void OLED_PutPix(uint8_t x, uint8_t y, uint8_t data);

/**
 * @description: 清空一组8像素数据
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @return {*}
 */
void OLED_ClrPix(uint8_t x, uint8_t y);

/********************************************************************************************/
/*****************************************直接显示*******************************************/
/********************************************************************************************/

/**
 * @description: 打印6x8字符大小的字符串
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {char*} ch    字符串
 * @return {*}
 */
void OLED_P6x8Str(uint8_t x, uint8_t y, const char* ch);

/**
 * @description: 反转打印6x8字符大小的字符串
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {char*} ch    字符串
 * @return {*}
 */
void OLED_P6x8Reverse(uint8_t x, uint8_t y,const char* ch);

/**
 * @description: 打印8x16字符大小的字符串
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {char*} ch    字符串
 * @return {*}
 */
void OLED_P8x16Str(uint8_t x, uint8_t y, const char* ch);

/**
 * @description: printf 打印6x8
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {char*} ftm   格式字符串
 * @return {*}
 */
void OLED_Printf6x8(uint8_t x, uint8_t y, const char* ftm, ...);

/**
 * @description: printf 打印8x16
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {char*} ftm   格式字符串
 * @return {*}
 */
void OLED_Printf8x16(uint8_t x,uint8_t y, const char* ftm, ...);

/**
 * @description: 打印图片
 * @param {uint8_t} *buffer 图片数组
 * @return {*}
 */
void OLED_Buffer_Upload(const uint8_t *buffer);


/********************************************************************************************/
/*****************************************直接显示*******************************************/
/********************************************************************************************/

/**
 * @description: 打印字符到显存
 * @param {uint8_t*} x  坐标（像素）
 * @param {uint8_t*} y  坐标（块）
 * @param {char} ch 字符
 * @param {uint8_t*} buf    显存数组指针
 * @return {*}
 */
void OLED_printfCharToBuf(uint8_t* x, uint8_t* y, char ch, uint8_t* buf);

/**
 * @description: 打印字符串到显存
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {char*} format    字符串
 * @return {*}
 */
void OLED_printfStrToBuf(uint8_t x, uint8_t y, const char* format);

/**
 * @description: printf打印到显存
 * @param {uint8_t} x   坐标（像素）
 * @param {uint8_t} y   坐标（块）
 * @param {char*} format    格式字符串
 * @return {*}
 */
void OLED_printf(uint8_t x, uint8_t y, const char* format, ...);

/**
 * @description: 打印图片到显存
 * @param {uint8_t} *buffer 图片数组
 * @return {*}
 */
void OLED_printBufToBuf(const uint8_t *buffer);

/**
 * @description: 清空当前缓存
 * @return {*}
 */
void OLED_clearBuf(void);

/**
 * @description: 显示当前缓存
 * @return {*}
 */
void OLED_printBuf(void);

#endif