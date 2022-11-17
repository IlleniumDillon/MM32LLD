#include "P18_UART.h"


#define P18_UART_NUM    (UART4)
#define P18_UART_TX     (UART2_TX_A02)
#define P18_UART_RX     (UART2_RX_A03)
#define P18_BAUD    (9600)

uint8_t P18_txBuffer[MAXPACKSIZE] = {0};
uint8_t P18_rxBuffer[MAXPACKSIZE] = {0};

uint8_t txindx = 0;
uint8_t rxindx = 0;

uint8_t istxbusy = 0;
/*P18_uartPack_t txPack = {0xaa,0,0,0,0,0,0};
P18_uartPack_t rxPack = {0xaa,0,0,0,0,0,0};*/

//uint8_t i = txPack.startByte;

uint8_t uart_query(MM32UART_Moudle moudle, uint8_t *dat)
{
  MM32_UART* m = (MM32_UART*)moudle;

	if(m->CSR.B.RXAVL==1)
	{
		*dat = (uint8_t)m->RDR.B.RXREG;
		return 1;
	}
	return 0;
}

void P18_uartInit(void)
{
  MM32_UART* m = (MM32_UART*)P18_UART_NUM;
  m->IER.B.RX_IEN = 1;
  nvic_init(UART4_IRQn, 0x00, 0x00, 1);
}

void P18_uartWrite(uint8_t* pack, uint8_t size)
{
  MM32UART_writeBlocking(P18_UART_NUM,pack,size);
}

void P18_uartReadCallBack(void)
{
  while(!uart_query(P18_UART_NUM,&P18_rxBuffer[rxindx]));
  rxindx++;
  if(rxindx==1)
  {
    if(P18_rxBuffer[rxindx-1]!=0XAA)
    {
      rxindx = 0;
      memset(P18_rxBuffer,0,MAXPACKSIZE);
    }
  }
  else if(rxindx>4 && rxindx == P18_rxBuffer[2])
  {
    uint8_t temp = P18_rxBuffer[0];
    for(uint8_t i = 1; i < P18_rxBuffer[2]-1; i++)
    {
      temp = temp^P18_rxBuffer[i];
    }
    if(temp==P18_rxBuffer[rxindx-1])
    {
      P18_decode();
    }
    rxindx = 0;
    memset(P18_rxBuffer,0,MAXPACKSIZE);
    return;
  }
}

static float _cvtFix2Float(uint8_t* rst)
{
  float data = 0;
  if(rst[0]&0x80)
  {
    data = -(float)(
             (rst[0]-0x80)*256+rst[1]+
             (rst[2]*256+rst[3])*0.0001
               );
  }
  else
  {
    data = (float)(
             rst[0]*256+rst[1]+
             (rst[2]*256+rst[3])*0.0001
               );
  }
  return data;
}

void P18_decode(void)
{
  switch(P18_rxBuffer[3])
  {
    case READ_CH_VOLT:
    {
      //memcpy(&P18_device.voltage[P18_rxBuffer[5]],&P18_rxBuffer[6],sizeof(int));
      P18_device.voltage[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case READ_CH_SHIFT:
    {
      //memcpy(&P18_device.shift[P18_rxBuffer[5]],&P18_rxBuffer[6],sizeof(int));
      P18_device.shift[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case RTREAD_CH_VOLT:
    {
      //memcpy(&P18_device.voltage[P18_rxBuffer[5]],&P18_rxBuffer[6],sizeof(int));
      P18_device.voltage[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case RTREAD_CH_SHIFT:
    {
      //memcpy(&P18_device.shift[P18_rxBuffer[5]],&P18_rxBuffer[6],sizeof(int));
      P18_device.shift[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case RTREAD_ALL_VOLT:
    {
      //memcpy(P18_device.voltage,&P18_rxBuffer[5],3*sizeof(int));
      P18_device.voltage[CHANNEL0] = _cvtFix2Float(P18_rxBuffer+5);
      P18_device.voltage[CHANNEL1] = _cvtFix2Float(P18_rxBuffer+9);
      P18_device.voltage[CHANNEL2] = _cvtFix2Float(P18_rxBuffer+13);
      break;
    }
    case RTREAD_ALL_SHIFT:
    {
      //memcpy(P18_device.shift,&P18_rxBuffer[5],3*sizeof(int));
      P18_device.shift[CHANNEL0] = _cvtFix2Float(P18_rxBuffer+5);
      P18_device.shift[CHANNEL1] = _cvtFix2Float(P18_rxBuffer+9);
      P18_device.shift[CHANNEL2] = _cvtFix2Float(P18_rxBuffer+13);
      break;
    }
    case CTRL_READ_LOOP:
    {
      P18_device.loopStatus[P18_rxBuffer[5]] = (P18_loop_t)P18_rxBuffer[6];
      break;
    }
    case CTRL_READ_AD:
    {
      P18_device.ADStatus[P18_rxBuffer[5]] = (P18_ADstatus_t)P18_rxBuffer[6];
      break;
    }
    case READ_CH_LOAD:
    {
      P18_device.load[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case READ_CH_SHIFTLIMH:
    {
      P18_device.shift_limh[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case READ_CH_POWER:
    {
      P18_device.power[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case READ_SYS_VOLTLIML:
    {
      P18_device.voltage_liml[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case READ_SYS_VOLTLIMH:
    {
      P18_device.voltage_limh[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case READ_SYS_SHIFTLIML:
    {
      P18_device.shift_liml[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      break;
    }
    case PID_READ_PID:
    {
      P18_device.P[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+6);
      P18_device.I[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+10);
      P18_device.D[P18_rxBuffer[5]] = _cvtFix2Float(P18_rxBuffer+14);
      break;
    }
    case READ_ADDRESS:
    {
      P18_device.addr = P18_rxBuffer[5];
      break;
    }
    case RTREAD_DATA_M:
    {
      //TODO:判断发送的指令是电压还是位移
      break;
    }
    case RTREAD_DATA_S:
    {
      //TODO:根据第5位判断读电压还是位移
      break;
    }
    case READ_DATA_S:
    {
      //TODO:根据第5位判断读电压还是位移
      break;
    }
    case PID_READ_STATUS:
    {
      //TODO:
      break;
    }
    default:
      break;
  }
}