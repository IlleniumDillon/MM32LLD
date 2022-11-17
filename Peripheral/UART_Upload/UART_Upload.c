/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-01 21:19:13
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-16 14:23:12
 * @FilePath: \CODE\Peripheral\UART_Upload\UART_Upload.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "UART_Upload.h"

void UART_floatVarUpload(MM32UART_Moudle moudle, float* var, uint8_t num)
{
    uint8_t cmdf[7] =
    { 0x55, 0xaa, 0x11, 0x55, 0xaa, 0xff, 0x01 };
    uint8_t cmdr = 0x01;
    uint8_t begin_cmd[3] =
    { 0x55, 0xaa, 0x11 };
    /*! 发送帧头 */
    MM32UART_writeBlocking(moudle, begin_cmd, sizeof(begin_cmd));
    /*! 发送数据个数 */
    MM32UART_writeBlocking(moudle, cmdf, sizeof(cmdf));
    MM32UART_writeBlocking(moudle, &num, 1);
    /*! 发送数据 */
    MM32UART_writeBlocking(moudle, (uint8_t*)(var), num * 4U);
    /*! 发送帧尾 */
    MM32UART_writeBlocking(moudle, &cmdr, 1);
    /*uint8_t head = 0x5a;
    uint8_t end = 0xa5;
    MM32UART_writeBlocking(moudle,&head,1);
    MM32UART_writeBlocking(moudle,&num,1);
    MM32UART_writeBlocking(moudle,(uint8_t*)(var), num * 4U);
    MM32UART_writeBlocking(moudle,&end,1);*/
}