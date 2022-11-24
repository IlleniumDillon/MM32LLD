/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-15 18:05:08
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 21:22:35
 * @FilePath: \CODE\Peripheral\HOST\HOST.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "HOST.h"

//上位机串口接收回调
uint8_t HOST_rxBuffer[HOST_RXSIZE] = {0};
//串口接收计数
uint8_t rxNum = 0;

/// @brief 上位机串口尝试接收
/// @param moudle 串口模块
/// @param dat 接收数据指针
/// @return 是否成功接收数据
uint8_t host_query(MM32UART_Moudle moudle, uint8_t *dat)
{
    MM32_UART* m = (MM32_UART*)moudle;

	if(m->CSR.B.RXAVL==1)
	{
		*dat = (uint8_t)m->RDR.B.RXREG;
		return 1;
	}
	return 0;
}

/// @brief 解释上位机指令
void HOST_uartDecode(void)
{
    float data[2] = {0};
    memcpy(data,&HOST_rxBuffer[1],2*sizeof(float));
    target_X = data[0];
    target_Y = data[1];
}

void HOST_uartReadCallBack(void)
{
    //确保已有可读数据，将数据推入缓冲
    while(!host_query(HOST_UART,&HOST_rxBuffer[rxNum]));
    rxNum++;
    //判断帧头
    if (rxNum == 1)
    {
        if(HOST_rxBuffer[rxNum-1]!=0X5A)
        {
            rxNum = 0;
            memset(HOST_rxBuffer,0,HOST_RXSIZE);
        }
    }
    //判断帧尾
    else if(rxNum == 10)
    {
        if(HOST_rxBuffer[rxNum-1]!=0X5A)
        {
            HOST_uartDecode();
        }
        rxNum = 0;
        memset(HOST_rxBuffer,0,HOST_RXSIZE);
    }
    
}