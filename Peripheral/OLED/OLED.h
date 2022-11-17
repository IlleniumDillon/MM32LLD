/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 20:39:51
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-07 10:09:00
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

extern uint8_t oled_refresh;

void OLED_init(void);

void OLED_WrtCmd(uint8_t cmd);

void OLED_WrtData(uint8_t data);

void OLED_Fill(uint8_t data);

void OLED_SetPos(uint8_t x, uint8_t y);

void OLED_PutPix(uint8_t x, uint8_t y, uint8_t data);

void OLED_ClrPix(uint8_t x, uint8_t y);


void OLED_P6x8Str(uint8_t x, uint8_t y, const char* ch);

void OLED_P6x8Reverse(uint8_t x, uint8_t y,const char* ch);

void OLED_P8x16Str(uint8_t x, uint8_t y, const char* ch);

void OLED_Printf6x8(uint8_t x, uint8_t y, const char* ftm, ...);

void OLED_Printf8x16(uint8_t x,uint8_t y, const char* ftm, ...);

void OLED_Buffer_Upload(const uint8_t *buffer);



void OLED_printfCharToBuf(uint8_t* x, uint8_t* y, char ch, uint8_t* buf);

void OLED_printfStrToBuf(uint8_t x, uint8_t y, const char* format);

void OLED_printf(uint8_t x, uint8_t y, const char* format, ...);

void OLED_printBufToBuf(const uint8_t *buffer);

void OLED_clearBuf(void);

void OLED_printBuf(void);

#endif