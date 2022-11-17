#ifndef _HOST_H_
#define _HOST_H_

#include "MM32_UART.h"
#include "P18_CTRL.h"

#define HOST_RXSIZE (10)
#define HOST_UART (UART2)

void HOST_uartReadCallBack(void);

#endif