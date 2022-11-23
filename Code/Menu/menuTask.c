/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-10 15:58:38
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 13:00:47
 * @FilePath: \CODE\Code\Menu\menuTask.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "menuTask.h"

float Vpp = 0.1;
float Freq = 0.1;
float Offset = 5;

void menu_selfCheck(void)
{
    int i = 10000000;
    if(P18_device.addr==0)
    {
        P18_uartInit();
        OLED_clearBuf();
        OLED_printf(24,3,"self check...");
        oled_refresh = 1;
        while(i--);
        P18_devCheck();
        OLED_clearBuf();
        OLED_printf(24,3,"self check pass!");
        OLED_printf(24,4,"addr :%d",P18_device.addr);
        oled_refresh = 1;
        i = 10000000;
        while(i--);
    }
    else
    {
        OLED_clearBuf();
        OLED_printf(6,3,"self check done");
        oled_refresh = 1;
        i = 10000000;
        while(i--);
    }
}

void menu_loopSet(void)
{
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./Loop Set");
    OLED_printf(6,3,"<Open Loop>");
    OLED_printf(6,4,"Close Loop     ");
    oled_refresh = 1;
    P18_loop_t flag = OPENLOOP;
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            while(P18_device.loopStatus[CHANNEL0]!=flag)
            {
                P18_setChannelLoopStatus(CHANNEL0,flag);
                P18_readChannelLoopStatus(CHANNEL0);
            }
            while(P18_device.loopStatus[CHANNEL1]!=flag)
            {
                P18_setChannelLoopStatus(CHANNEL1,flag);
                P18_readChannelLoopStatus(CHANNEL1);
            }
            while(P18_device.loopStatus[CHANNEL2]!=flag)
            {
                P18_setChannelLoopStatus(CHANNEL2,flag);
                P18_readChannelLoopStatus(CHANNEL2);
            }
            OLED_clearBuf();
            OLED_printf(6,3,"OK!");
            oled_refresh = 1;
            keyPressFlag = 0;
            int i = 10000000;
            while(i--);
            break;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./Loop Set");
            OLED_printf(6,3,"<Open Loop>");
            OLED_printf(6,4,"Close Loop     ");
            oled_refresh = 1;
            flag = OPENLOOP;
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./Loop Set");
            OLED_printf(6,3,"Open Loop");
            OLED_printf(6,4,"<Close Loop>");
            oled_refresh = 1;
            flag = CLOSELOOP;
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            break;
        }
    }
}

void menu_ADSet(void)
{
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./AD Set");
    OLED_printf(6,3,"<Analog>");
    OLED_printf(6,4,"Digital     ");
    oled_refresh = 1;
    P18_ADstatus_t flag = ANALOG;
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            while(P18_device.ADStatus[CHANNEL0]!=flag)
            {
                P18_setChannelADStatus(CHANNEL0,flag);
                P18_readChannelADStatus(CHANNEL0);
            }
            while(P18_device.ADStatus[CHANNEL1]!=flag)
            {
                P18_setChannelADStatus(CHANNEL1,flag);
                P18_readChannelADStatus(CHANNEL1);
            }
            while(P18_device.ADStatus[CHANNEL2]!=flag)
            {
                P18_setChannelADStatus(CHANNEL2,flag);
                P18_readChannelADStatus(CHANNEL2);
            }
            OLED_clearBuf();
            OLED_printf(6,3,"OK!");
            oled_refresh = 1;
            keyPressFlag = 0;
            int i = 10000000;
            while(i--);
            break;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./AD Set");
            OLED_printf(6,3,"<Analog>");
            OLED_printf(6,4,"Digital     ");
            oled_refresh = 1;
            flag = ANALOG;
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./AD Set");
            OLED_printf(6,3,"Analog    ");
            OLED_printf(6,4,"<Digital>");
            oled_refresh = 1;
            flag = DIGITAL;
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            break;
        }
    }
}

void menu_baudSet(void)
{
    P18_baud_t baudEnumList[9] = {BAUD_9600,BAUD_19200,BAUD_38400,BAUD_57600,BAUD_76800,BAUD_115200,BAUD_128000,BAUD_230400,BAUD_256000};
    int baudList[9] = {9600,19200,38400,57600,76800,115200,128000,230400,256000};
    uint8_t indx = 0;
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./Baud Set");
    OLED_printf(6,4,"[baud]:%d   ",baudList[indx]);
    oled_refresh = 1;
    
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            P18_setBaud(baudEnumList[indx]);
            int i = 10000000;
            while(i--);
            MM32RCC_disableUART4();
            MM32RCC_enableUART4();
            i = 10000000;
            while(i--);
            P18_device.baud = baudList[indx];
            MM32UART_TXPin txpin2 = {.port = GPIOA, .pin = P00, .conf = AF_PUSHPULL, .af = AF8, .moudle = UART4};
            MM32UART_RXPin rxpin2 = {.port = GPIOA, .pin = P01, .conf = INPUT_FLOATING, .af = AF8, .moudle = UART4};
            MM32UART_moudleInit(&txpin2,&rxpin2,NULL,NULL,P18_device.baud);
            P18_uartInit();
            P18_device.addr = 0;
            OLED_clearBuf();
            OLED_printf(24,3,"self check...");
            oled_refresh = 1;
            i = 10000000;
            while(i--);
            P18_devCheck();
            OLED_clearBuf();
            OLED_printf(24,3,"self check pass!");
            OLED_printf(24,4,"addr :%d",P18_device.addr);
            oled_refresh = 1;
            i = 10000000;
            while(i--);
                break;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            if(indx!=8)indx++;
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./Baud Set");
            OLED_printf(6,4,"[baud]:%d   ",baudList[indx]);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            if(indx!=0)indx--;
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./Baud Set");
            OLED_printf(6,4,"[baud]:%d   ",baudList[indx]);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            keyPressFlag = 0;
            break;
        }
        else if(keyPressFlag & KEYPRESS_RIGHT)
        {
            ;
        }
    }
}

void menu_FBtimeSet(void)
{
    uint8_t step = 1;
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./FB Time Set");
    OLED_printf(6,3,"[step]:%dms   ",step);
    OLED_printf(6,4,"FB Time:%dms   ",P18_device.fbTime);
    oled_refresh = 1;
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            break;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            keyPressFlag = 0;
            if((uint16_t)P18_device.fbTime+step <= 255)
            {
                P18_device.fbTime = P18_device.fbTime + step;
            }
            
            OLED_clearBuf();
            OLED_printf(0,0,">>./FB Time Set");
            OLED_printf(6,3,"[step]:%dms   ",step);
            OLED_printf(6,4,"FB Time:%dms   ",P18_device.fbTime);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            keyPressFlag = 0;
            if(P18_device.fbTime>step)
            {
                P18_device.fbTime = P18_device.fbTime - step;
            }
            OLED_clearBuf();
            OLED_printf(0,0,">>./FB Time Set");
            OLED_printf(6,3,"[step]:%dms   ",step);
            OLED_printf(6,4,"FB Time:%dms   ",P18_device.fbTime);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            keyPressFlag = 0;
            
            if(step!=100)
            {
                step = step*10;
            }
            OLED_clearBuf();
            OLED_printf(0,0,">>./FB Time Set");
            OLED_printf(6,3,"[step]:%dms   ",step);
            OLED_printf(6,4,"FB Time:%dms   ",P18_device.fbTime);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_RIGHT)
        {
            keyPressFlag = 0;
            step = step/10;
            if(step==0)
            {
                step = 1;
            }
            OLED_clearBuf();
            OLED_printf(0,0,">>./FB Time Set");
            OLED_printf(6,3,"[step]:%dms   ",step);
            OLED_printf(6,4,"FB Time:%dms   ",P18_device.fbTime);
            oled_refresh = 1;
        }
    }
}

void menu_FBStart(void)
{
    P18_readAllChannelShiftRealtime(P18_device.fbTime);
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./FB Start");
    OLED_printf(6,4,"FB Time:%dms Start",P18_device.fbTime);
    oled_refresh = 1;
    int i = 10000000;
    while(i--);
}

void menu_FBStop(void)
{
    P18_readRealtimeStop();
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./FB Stop");
    OLED_printf(6,4,"FB Time:%dms Stop",P18_device.fbTime);
    oled_refresh = 1;
    int i = 10000000;
    while(i--);
}

void _paraSet(char* name, float* para)
{
    float step = 1;
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./%s Set",name);
    OLED_printf(6,3,"[step]:%.3f   ",step);
    OLED_printf(6,4,"%s:%.3f   ",name,*para);
    oled_refresh = 1;
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            OLED_clearBuf();
            oled_refresh = 1;
            keyPressFlag = 0;
            return;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            keyPressFlag = 0;
            *para += step;
            
            OLED_clearBuf();
            OLED_printf(0,0,">>./%s Set",name);
            OLED_printf(6,3,"[step]:%.3f   ",step);
            OLED_printf(6,4,"%s:%.3f   ",name,*para);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            keyPressFlag = 0;
            *para -= step;
            OLED_clearBuf();
            OLED_printf(0,0,">>./%s Set",name);
            OLED_printf(6,3,"[step]:%.3f   ",step);
            OLED_printf(6,4,"%s:%.3f   ",name,*para);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            keyPressFlag = 0;
            
            step *= 10;
            OLED_clearBuf();
            OLED_printf(0,0,">>./%s Set",name);
            OLED_printf(6,3,"[step]:%.3f   ",step);
            OLED_printf(6,4,"%s:%.3f   ",name,*para);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_RIGHT)
        {
            keyPressFlag = 0;
            step /= 10;
            
            OLED_clearBuf();
            OLED_printf(0,0,">>./%s Set",name);
            OLED_printf(6,3,"[step]:%.3f   ",step);
            OLED_printf(6,4,"%s:%.3f   ",name,*para);
            oled_refresh = 1;
        }
    }
}

void menu_CH1Set(void)
{
    uint8_t flag = 0;
    keyPressFlag = 0;
    OLED_clearBuf();
    oled_refresh = 1;
    OLED_clearBuf();
    OLED_printf(0,0,">>./CH1 Set");
    //OLED_printf(6,3,"[step]:%d   ",step);
    OLED_printf(0,4,">");
    OLED_printf(6,4,"P:%f   ",P18_device.P[0]);
    OLED_printf(6,5,"I:%f   ",P18_device.I[0]);
    OLED_printf(6,6,"D:%f   ",P18_device.D[0]);
    oled_refresh = 1;
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            keyPressFlag = 0;
            switch (flag)
            {
                case 0:
                {
                    _paraSet("P",&P18_device.P[0]);
                    break;
                }
                case 1:
                {
                    _paraSet("I",&P18_device.I[0]);
                    break;
                }
                case 2:
                {
                    _paraSet("D",&P18_device.D[0]);
                    break;
                }
                default:
                    break;
            }
            keyPressFlag = 0;
            OLED_printf(0,0,">>./CH1 Set");
            OLED_printf(0,4,">");
            OLED_printf(6,4,"P:%f   ",P18_device.P[0]);
            OLED_printf(6,5,"I:%f   ",P18_device.I[0]);
            OLED_printf(6,6,"D:%f   ",P18_device.D[0]);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./CH1 Set");
            OLED_printf(6,4,"P:%f   ",P18_device.P[0]);
            OLED_printf(6,5,"I:%f   ",P18_device.I[0]);
            OLED_printf(6,6,"D:%f   ",P18_device.D[0]);
            if(flag != 0)
            {
                flag--;
                OLED_printf(0,4," ");
                OLED_printf(0,5," ");
                OLED_printf(0,6," ");
                OLED_printf(0,4+flag,">");
                oled_refresh = 1;
            }
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./CH1 Set");
            OLED_printf(6,4,"P:%f   ",P18_device.P[0]);
            OLED_printf(6,5,"I:%f   ",P18_device.I[0]);
            OLED_printf(6,6,"D:%f   ",P18_device.D[0]);
            if(flag != 2)
            {
                flag++;
                OLED_printf(0,4," ");
                OLED_printf(0,5," ");
                OLED_printf(0,6," ");
                OLED_printf(0,4+flag,">");
                oled_refresh = 1;
            }
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            break;
        }
    }
}

void menu_CH2Set(void)
{
    uint8_t flag = 0;
    keyPressFlag = 0;
    OLED_clearBuf();
    oled_refresh = 1;
    OLED_clearBuf();
    OLED_printf(0,0,">>./CH2 Set");
    //OLED_printf(6,3,"[step]:%d   ",step);
    OLED_printf(0,4,">");
    OLED_printf(6,4,"P:%f   ",P18_device.P[1]);
    OLED_printf(6,5,"I:%f   ",P18_device.I[1]);
    OLED_printf(6,6,"D:%f   ",P18_device.D[1]);
    oled_refresh = 1;
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            keyPressFlag = 0;
            switch (flag)
            {
                case 0:
                {
                    _paraSet("P",&P18_device.P[1]);
                    break;
                }
                case 1:
                {
                    _paraSet("I",&P18_device.I[1]);
                    break;
                }
                case 2:
                {
                    _paraSet("D",&P18_device.D[1]);
                    break;
                }
                default:
                    break;
            }
            flag = 0;
            keyPressFlag = 0;
            OLED_printf(0,0,">>./CH2 Set");
            OLED_printf(0,4,">");
            OLED_printf(6,4,"P:%f   ",P18_device.P[1]);
            OLED_printf(6,5,"I:%f   ",P18_device.I[1]);
            OLED_printf(6,6,"D:%f   ",P18_device.D[1]);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./CH2 Set");
            OLED_printf(6,4,"P:%f   ",P18_device.P[1]);
            OLED_printf(6,5,"I:%f   ",P18_device.I[1]);
            OLED_printf(6,6,"D:%f   ",P18_device.D[1]);
            if(flag != 0)
            {
                flag--;
                OLED_printf(0,4," ");
                OLED_printf(0,5," ");
                OLED_printf(0,6," ");
                OLED_printf(0,4+flag,">");
                oled_refresh = 1;
            }
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./CH2 Set");
            OLED_printf(6,4,"P:%f   ",P18_device.P[1]);
            OLED_printf(6,5,"I:%f   ",P18_device.I[1]);
            OLED_printf(6,6,"D:%f   ",P18_device.D[1]);
            if(flag != 2)
            {
                flag++;
                OLED_printf(0,4," ");
                OLED_printf(0,5," ");
                OLED_printf(0,6," ");
                OLED_printf(0,4+flag,">");
                oled_refresh = 1;
            }
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            break;
        }
    }
}

void menu_waveDef(void)
{
    uint8_t flag = 0;
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./Wave Def");
    OLED_printf(6,2,"Channel:CH1");
    OLED_printf(6,3,"Type:Square");
    OLED_printf(0,4,">");
    OLED_printf(6,4,"Vpp:%.3fV   ",Vpp);
    OLED_printf(6,5,"Freq:%.3fHz   ",Freq);
    OLED_printf(6,6,"Offset:%.3fV   ",Offset);
    oled_refresh = 1;
    while(1)
    {
        Menu_getPinState();
        if(keyPressFlag & KEYPRESS_OK)
        {
            keyPressFlag = 0;
            switch (flag)
            {
                case 0:
                {
                    _paraSet("Vpp",&Vpp);
                    break;
                }
                case 1:
                {
                    _paraSet("Freq",&Freq);
                    break;
                }
                case 2:
                {
                    _paraSet("Offset",&Offset);
                    break;
                }
                default:
                    break;
            }
            flag = 0;
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./Wave Def");
            OLED_printf(6,2,"Channel:CH1");
            OLED_printf(6,3,"Type:Square");
            OLED_printf(0,4,">");
            OLED_printf(6,4,"Vpp:%.3fV   ",Vpp);
            OLED_printf(6,5,"Freq:%.3fHz   ",Freq);
            OLED_printf(6,6,"Offset:%.3fV   ",Offset);
            oled_refresh = 1;
        }
        else if(keyPressFlag & KEYPRESS_UP)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./Wave Def");
            OLED_printf(6,2,"Channel:CH1");
            OLED_printf(6,3,"Type:Square");
            OLED_printf(6,4,"Vpp:%.3fV   ",Vpp);
            OLED_printf(6,5,"Freq:%.3fHz   ",Freq);
            OLED_printf(6,6,"Offset:%.3fV   ",Offset);
            if(flag != 0)
            {
                flag--;
                OLED_printf(0,4," ");
                OLED_printf(0,5," ");
                OLED_printf(0,6," ");
                OLED_printf(0,4+flag,">");
                oled_refresh = 1;
            }
        }
        else if(keyPressFlag & KEYPRESS_DOWN)
        {
            keyPressFlag = 0;
            OLED_clearBuf();
            OLED_printf(0,0,">>./Wave Def");
            OLED_printf(6,2,"Channel:CH1");
            OLED_printf(6,3,"Type:Square");
            OLED_printf(6,4,"Vpp:%.3fV   ",Vpp);
            OLED_printf(6,5,"Freq:%.3fHz   ",Freq);
            OLED_printf(6,6,"Offset:%.3fV   ",Offset);
            if(flag != 2)
            {
                flag++;
                OLED_printf(0,4," ");
                OLED_printf(0,5," ");
                OLED_printf(0,6," ");
                OLED_printf(0,4+flag,">");
                oled_refresh = 1;
            }
        }
        else if(keyPressFlag & KEYPRESS_LEFT)
        {
            break;
        }
    }
}
void menu_waveSend(void)
{
    P18_setChannelFastShiftWave(CHANNEL1,SQUAREWAVE,Vpp,Freq,Offset);
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./Wave Send");
    OLED_printf(6,4,"Start");
    oled_refresh = 1;
    int i = 10000000;
    while(i--);
}
void menu_waveStop(void)
{
    P18_setChannelFastWaveStop();
    keyPressFlag = 0;
    OLED_clearBuf();
    OLED_printf(0,0,">>./Wave Stop");
    OLED_printf(6,4,"Stop");
    oled_refresh = 1;
    int i = 10000000;
    while(i--);
}

void menu_setVolt0(void)
{
    target_X = 0;
}

void menu_setVolt100(void)
{
    target_X = 100;
}