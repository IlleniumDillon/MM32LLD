#ifndef _P18_UART_H_
#define _P18_UART_H_

#include "common.h"
#include "P18_TYPEDEF.h"
#include <string.h>

void P18_uartInit(void);

void P18_uartWrite(uint8_t* pack, uint8_t size);

void P18_uartReadCallBack(void);

void P18_decode(void);

#endif