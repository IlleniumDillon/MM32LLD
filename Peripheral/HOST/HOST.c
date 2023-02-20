/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-15 18:05:08
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-20 15:44:14
 * @FilePath: \CODE\Peripheral\HOST\HOST.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "HOST.h"

//上位机串口接收回调
uint8_t HOST_rxBuffer[HOST_RXSIZE] = {0};
//串口接收计数
uint8_t rxNum = 0;
//示波器包结构，8个数据
uint8_t SCOPE_txBuffer[] = {
    0x55, 0xaa, 0x11,
    0x55, 0xaa, 0x11, 0x55, 0xaa, 0xff, 0x01,
    0x08,
    0x00, 0x00 ,0x00, 0x00,
    0x00, 0x00 ,0x00, 0x00,
    0x00, 0x00 ,0x00, 0x00,
    0x00, 0x00 ,0x00, 0x00,
    0x00, 0x00 ,0x00, 0x00,
    0x00, 0x00 ,0x00, 0x00,
    0x00, 0x00 ,0x00, 0x00,
    0x00, 0x00 ,0x00, 0x00,
    0x01
};
//示波器包数据段位置
uint8_t* SCOPE_dataPtr = &SCOPE_txBuffer[11];

float HOST_rxData[8] = {0};
uint8_t HOST_newDataFlag = 0;

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
    /*float data[2] = {0};
    memcpy(data,&HOST_rxBuffer[1],2*sizeof(float));
    target_X = data[0];
    target_Y = data[1];*/
    extern poly5d P18_PP_X;
    extern poly5d P18_PP_Y;
    memcpy(HOST_rxData,&HOST_rxBuffer[1],8*sizeof(float));
    PP_poly5dNewPos(&P18_PP_X, 
                    HOST_rxData[0],
                    HOST_rxData[1],
                    HOST_rxData[2],
                    HOST_rxData[3]);
    PP_poly5dNewPos(&P18_PP_Y, 
                    HOST_rxData[4],
                    HOST_rxData[5],
                    HOST_rxData[6],
                    HOST_rxData[7]);
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
    else if(rxNum == 34)
    {
        if(HOST_rxBuffer[rxNum-1]==0XA5)
        {
            HOST_uartDecode();
        }
        rxNum = 0;
        memset(HOST_rxBuffer,0,HOST_RXSIZE);
    }
    
}

void HOST_uartUploadDmaInit(void)
{
    /*MM32UART_TXPin txpin2 = {.port = GPIOD, .pin = P00, .conf = AF_PUSHPULL, .af = AF8, .moudle = UART8};
    MM32UART_RXPin rxpin2 = {.port = GPIOD, .pin = P01, .conf = INPUT_FLOATING, .af = AF8, .moudle = UART8};
    MM32UARTDMA_moudleInit(&txpin2,&rxpin2,NULL,NULL,115200);*/
    MM32UART_TXPin txpin = {.port = GPIOD, .pin = P05, .conf = AF_PUSHPULL, .af = AF7, .moudle = UART2};
    MM32UART_RXPin rxpin = {.port = GPIOD, .pin = P06, .conf = INPUT_FLOATING, .af = AF7, .moudle = UART2};
    MM32UARTDMA_moudleInit(&txpin,&rxpin,NULL,NULL,921600);
}

void HOST_uartUploadStart(void)
{
    //uint32_t time = systick_getval();
    
    MM32UARTDMA_startTXDMA(SCOPE_UART,SCOPE_txBuffer,44);
    //MM32UART_writeBlocking(SCOPE_UART,SCOPE_txBuffer,44);
    /*time = systick_getval()-time;
    float time_s = (float)time/120000000;
    if(time_s)
    {
      time_s = 0;
    }*/
}