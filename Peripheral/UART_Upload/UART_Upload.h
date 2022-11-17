/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 21:19:04
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-01 21:21:31
 * @FilePath: \CODE\Peripheral\UART_Upload\UART_Upload.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _UART_UPLOAD_H_
#define _UART_UPLOAD_H_

#include "MM32_UART.h"

void UART_floatVarUpload(MM32UART_Moudle moudle, float* var, uint8_t num);

#endif