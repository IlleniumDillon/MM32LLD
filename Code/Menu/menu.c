/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-05 17:00:33
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 13:32:24
 * @FilePath: \CODE\Code\Menu\menu.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "menu.h"

MM32GPIO_GPIO_Pin SW_1 = {.port = GPIOF, .pin = P00, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin SW_2 = {.port = GPIOC, .pin = P15, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin SW_3 = {.port = GPIOC, .pin = P14, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin SW_4 = {.port = GPIOC, .pin = P13, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin BUT_RIGHT = {.port = GPIOF, .pin = P05, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin BUT_DOWN = {.port = GPIOF, .pin = P02, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin BUT_LEFT = {.port = GPIOF, .pin = P01, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin BUT_OK = {.port = GPIOF, .pin = P03, .conf = INPUT_FLOATING};
MM32GPIO_GPIO_Pin BUT_UP = {.port = GPIOF, .pin = P04, .conf = INPUT_FLOATING};

menuNode menuSpace[MENUSPZCESIZE] = {0};
uint8_t menuCurLev = 0;
uint8_t menuCurNum = 0;

uint8_t keyPressFlag = 0;

void keyUpTask(void* p)
{
    uint8_t temp = 0;
    if(menuCurLev==0)
    {
        temp = menuCurNum;
    }
    else
    {
        temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
    }
    if(menuSpace[temp].prev!=MENUNULL)
    {
        menuCurNum--;
    }
    Menu_display();
}

void keyDownTask(void* p)
{
    uint8_t temp = 0;
    if(menuCurLev==0)
    {
        temp = menuCurNum;
    }
    else
    {
        temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
    }
    if(menuSpace[temp].next!=MENUNULL && menuSpace[menuSpace[temp].next].menu.name!=NULL)
    {
        menuCurNum++;
    }
    Menu_display();
}

void keyLeftTask(void* p)
{
    
}

void keyRightTask(void* p)
{
    
}

void keyOkTask(void* p)
{
    menuCurLev = menuCurNum+1;
    menuCurNum = 0;
    Menu_display();
}

void backTask(void* p)
{
    menuCurLev = 0;
    Menu_display();
}

void Menu_init(void)
{
    MM32GPIO_setPinConfig(SW_1.port,SW_1.pin,SW_1.conf);
    MM32GPIO_setPinConfig(SW_2.port,SW_2.pin,SW_2.conf);
    MM32GPIO_setPinConfig(SW_3.port,SW_3.pin,SW_3.conf);
    MM32GPIO_setPinConfig(SW_4.port,SW_4.pin,SW_4.conf);
    MM32GPIO_setPinConfig(BUT_RIGHT.port,BUT_RIGHT.pin,BUT_RIGHT.conf);
    MM32GPIO_setPinConfig(BUT_DOWN.port,BUT_DOWN.pin,BUT_DOWN.conf);
    MM32GPIO_setPinConfig(BUT_LEFT.port,BUT_LEFT.pin,BUT_LEFT.conf);
    MM32GPIO_setPinConfig(BUT_OK.port,BUT_OK.pin,BUT_OK.conf);
    MM32GPIO_setPinConfig(BUT_UP.port,BUT_UP.pin,BUT_UP.conf);
    /*MM32EXTI_pinInit(BUT_RIGHT,RISING,10);
    MM32EXTI_pinInit(BUT_DOWN,RISING,11);
    MM32EXTI_pinInit(BUT_LEFT,RISING,12);
    MM32EXTI_pinInit(BUT_OK,RISING,13);
    MM32EXTI_pinInit(BUT_UP,RISING,14);*/

    OLED_init();
    //OLED_Buffer_Upload(&DISP_image_100thAnniversary[0][0]);
    OLED_printBufToBuf(&DISP_image_100thAnniversary[0][0]);
    oled_refresh = 1;
    for(int i = 0; i < 10000000; i++);

    for(int i = 0; i < LEVEL0SIZE; i++)
    {
        menuSpace[i].child = LEVEL0SIZE + i * LEVEL1SIZE;
        menuSpace[i].next = (i+1 == LEVEL0SIZE) ?  MENUNULL : i+1;
        menuSpace[i].parent = MENUNULL;
        menuSpace[i].prev = (i == 0) ? MENUNULL : i-1;
    }
    for(int i = 0; i < LEVEL0SIZE; i++)
    {
        for(int j = 0; j < LEVEL1SIZE; j++)
        {
            menuSpace[LEVEL0SIZE + i * LEVEL1SIZE + j].child = MENUNULL;
            menuSpace[LEVEL0SIZE + i * LEVEL1SIZE + j].next = (j+1 == LEVEL1SIZE) ?  MENUNULL : LEVEL0SIZE + i * LEVEL1SIZE + j + 1;
            menuSpace[LEVEL0SIZE + i * LEVEL1SIZE + j].parent = i;
            menuSpace[LEVEL0SIZE + i * LEVEL1SIZE + j].prev = (j == 0) ? MENUNULL : LEVEL0SIZE + i * LEVEL1SIZE + j - 1;
        }
    }
    Menu_setNode("Sys Op", (void*)0, MENU,0,0);
        Menu_setNode("..", (void*)backTask, FUNCTION,1,0);
        Menu_setNode("Self Check", (void*)menu_selfCheck, FUNCTION,1,1);
        Menu_setNode("Loop Set", (void*)menu_loopSet, FUNCTION,1,2);
        Menu_setNode("A/D Set", (void*)menu_ADSet, FUNCTION,1,3);
        Menu_setNode("Baud Set", (void*)menu_baudSet, FUNCTION,1,4);
    Menu_setNode("Basic Op", (void*)0, MENU,0,1);
        Menu_setNode("..", (void*)backTask, FUNCTION,2,0);
        Menu_setNode("FBtime Set", (void*)menu_FBtimeSet, FUNCTION,2,1);
        Menu_setNode("FB Start", (void*)menu_FBStart, FUNCTION,2,2);
        Menu_setNode("FB Stop", (void*)menu_FBStop, FUNCTION,2,3);
        /*Menu_setNode("Baud Set", (void*)0, FUNCTION,2,4);*/
    Menu_setNode("Para Set", (void*)0, MENU,0,2);
        Menu_setNode("..", (void*)backTask, FUNCTION,3,0);
        Menu_setNode("CH1", (void*)menu_CH1Set, FUNCTION,3,1);
        Menu_setNode("CH2", (void*)menu_CH2Set, FUNCTION,3,2);
        //Menu_setNode("D", (void*)0, FUNCTION,3,3);
    Menu_setNode("Wave Set", (void*)0, MENU,0,3);
        Menu_setNode("..", (void*)backTask, FUNCTION,4,0);
        Menu_setNode("Wave Def", (void*)menu_waveDef, FUNCTION,4,1);
        Menu_setNode("Send Wave", (void*)menu_waveSend, FUNCTION,4,2);
        Menu_setNode("Stop Wave", (void*)menu_waveStop, FUNCTION,4,3);
    Menu_setNode("Help", (void*)0, MENU,0,4);
        Menu_setNode("..", (void*)backTask, FUNCTION,5,0);
        Menu_setNode("set voltage 0", (void*)menu_setVolt0, FUNCTION,5,1);
        Menu_setNode("set voltage 100", (void*)menu_setVolt100, FUNCTION,5,2);
        Menu_setNode("save para", (void*)Menu_savePara, FUNCTION,5,3);
        Menu_setNode("load para", (void*)Menu_loadPara, FUNCTION,5,4);
}

void Menu_setNode(char* name, void* dataBase, dataTypeFlag type, uint8_t level, uint8_t num)
{
    uint8_t temp = 0;
    if(level==0)
    {
        temp = num;
    }
    else
    {
        temp = (level-1) * LEVEL1SIZE + num + LEVEL0SIZE;
    }
    menuSpace[temp].menu.name = name;
    menuSpace[temp].menu.dataBase = dataBase;
    menuSpace[temp].menu.flag = type;
    if(type==INT)
    {
        menuSpace[temp].menu.data.I = *(int*)dataBase;
    }
    else if(type==FLOAT)
    {
        menuSpace[temp].menu.data.F = *(float*)dataBase;
    }
    else
    {
        menuSpace[temp].menu.data.P = dataBase;
    }
    menuSpace[temp].menu.keyDownTask = &keyDownTask;
    menuSpace[temp].menu.keyUpTask = &keyUpTask;
    menuSpace[temp].menu.keyLeftTask = &keyLeftTask;
    menuSpace[temp].menu.keyRightTask = &keyRightTask;
    menuSpace[temp].menu.keyOkTask = &keyOkTask;
    if(type==FUNCTION) menuSpace[temp].menu.keyOkTask = (menuFunction)menuSpace[temp].menu.data.P;
}

void Menu_display(void)
{
    uint8_t temp = menuCurLev * LEVEL1SIZE + (menuCurLev!=0)*LEVEL0SIZE;
    if(menuCurLev==0)
    {
        temp = 0;
    }
    else
    {
        temp = (menuCurLev-1) * LEVEL1SIZE + LEVEL0SIZE+menuCurNum/6*6;
    }
    /*OLED_Fill(0);
    OLED_P6x8Str(24,0,"P18 controller");
    OLED_P6x8Str(0,1,"----------------------");*/
    OLED_clearBuf();
    OLED_printfStrToBuf(24,0,"P18 controller");
    OLED_printfStrToBuf(0,1,"---------------------");
    uint8_t cont = 2;
    while(menuSpace[temp].menu.name!=NULL && temp != MENUNULL)
    {
        //OLED_P6x8Str(6,cont,menuSpace[temp].menu.name);
        OLED_printfStrToBuf(6,cont,menuSpace[temp].menu.name);
        temp = menuSpace[temp].next;
        cont++;
        if(cont==8) break;
    }
    OLED_printfStrToBuf(0,menuCurNum%6+2,">");
    oled_refresh = 1;
}

void Menu_loop(void)
{
    Menu_getPinState();
    uint8_t temp = 0;
    if(menuCurLev==0)
    {
        temp = menuCurNum;
    }
    else
    {
        temp = (menuCurLev-1) * LEVEL1SIZE + menuCurNum + LEVEL0SIZE;
    }
    if(keyPressFlag & KEYPRESS_DOWN)
    {
        menuSpace[temp].menu.keyDownTask(NULL);
        Menu_display();
    }
    else if(keyPressFlag & KEYPRESS_LEFT)
    {
        menuSpace[temp].menu.keyLeftTask(NULL);
        Menu_display();
    }
    else if(keyPressFlag & KEYPRESS_OK)
    {
        menuSpace[temp].menu.keyOkTask(NULL);
        Menu_display();
    }
    else if(keyPressFlag & KEYPRESS_RIGHT)
    {
        menuSpace[temp].menu.keyRightTask(NULL);
        Menu_display();
    }
    else if(keyPressFlag & KEYPRESS_UP)
    {
        menuSpace[temp].menu.keyUpTask(NULL);
        Menu_display();
    }
    keyPressFlag = 0;
}

void Menu_loadPara(void)
{
    P18_save_t save = {0};
    uint8_t data[1024] = {0};
    nvic_interrput_disable();
    MM32FLASH_readPage(0,data);
    nvic_interrput_enable();
    memcpy(&save,data,sizeof(save));
    P18_device.baud = save.baud;
    P18_device.fbTime = save.fbTime;
    memcpy(P18_device.P,save.P,3*sizeof(float));
    memcpy(P18_device.I,save.I,3*sizeof(float));
    memcpy(P18_device.D,save.D,3*sizeof(float));
}

void Menu_savePara(void)
{
    P18_save_t save = {0};
    uint8_t data[1024] = {0};
    
    save.baud = P18_device.baud;
    save.fbTime = P18_device.fbTime;
    memcpy(save.P,P18_device.P,3*sizeof(float));
    memcpy(save.I,P18_device.I,3*sizeof(float));
    memcpy(save.D,P18_device.D,3*sizeof(float));

    memcpy(data,&save,sizeof(save));

    nvic_interrput_disable();
    MM32FLASH_erasePage(0);
    MM32FLASH_writePage(0,data);
    nvic_interrput_enable();
}

void Menu_getPinState(void)
{
    keyPressFlag = 0;
    if(MM32GPIO_getPinState(BUT_RIGHT.port,BUT_RIGHT.pin) || MM32GPIO_getPinState(BUT_DOWN.port,BUT_DOWN.pin) ||
        MM32GPIO_getPinState(BUT_LEFT.port,BUT_LEFT.pin) || MM32GPIO_getPinState(BUT_OK.port,BUT_OK.pin) ||
        MM32GPIO_getPinState(BUT_UP.port,BUT_UP.pin))
    {
        int i = 1500000;
        while(i--);

        if(MM32GPIO_getPinState(BUT_RIGHT.port,BUT_RIGHT.pin))
        {
            keyPressFlag |= KEYPRESS_RIGHT;
        }
        else if(MM32GPIO_getPinState(BUT_DOWN.port,BUT_DOWN.pin))
        {
            keyPressFlag |= KEYPRESS_DOWN;
        }
        else if(MM32GPIO_getPinState(BUT_LEFT.port,BUT_LEFT.pin))
        {
            keyPressFlag |= KEYPRESS_LEFT;
        }
        else if(MM32GPIO_getPinState(BUT_OK.port,BUT_OK.pin))
        {
            keyPressFlag |= KEYPRESS_OK;
        }
        else if(MM32GPIO_getPinState(BUT_UP.port,BUT_UP.pin))
        {
            keyPressFlag |= KEYPRESS_UP;
        }
        else
        {
            keyPressFlag = 0;
        }
    }
}