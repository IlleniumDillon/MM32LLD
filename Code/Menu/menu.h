/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-05 17:00:29
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-15 16:03:48
 * @FilePath: \CODE\Code\Menu\menu.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MENU_H_
#define _MENU_H_

#include "stdio.h"
#include "MM32_GPIO.h"
#include "MM32_EXTI.h"
#include "OLED.h"
#include "P18_CTRL.h"
#include "menuTask.h"
#include "MM32_FLASH.h"

#define MENUSPZCESIZE (255)
#define MENUNULL (255)
#define LEVEL0SIZE (5)
#define LEVEL1SIZE (40)

#define KEYPRESS_UP (0X1 << 0)
#define KEYPRESS_DOWN (0X1 << 1)
#define KEYPRESS_LEFT (0X1 << 2)
#define KEYPRESS_RIGHT (0X1 << 3)
#define KEYPRESS_OK (0X1 << 4)

typedef void(*menuFunction)(void* userData);

typedef enum _dataTypeFlag
{
    INT,
    FLOAT,
    FUNCTION,
    MENU
}dataTypeFlag;

typedef union _dataType
{
    int I;
    float F;
    void* P;
}dataType;

typedef struct _menuType
{
    dataType data;
    dataTypeFlag flag;
    void* dataBase;
    
    char *name;
    
    menuFunction keyUpTask;
    menuFunction keyDownTask;
    menuFunction keyOkTask;
    menuFunction keyLeftTask;
    menuFunction keyRightTask;
}menuType;

typedef struct _menuNode
{
    uint8_t parent;
    uint8_t next;
    uint8_t prev;
    uint8_t child;
    menuType menu;
}menuNode;

extern menuNode menuSpace[MENUSPZCESIZE];
extern uint8_t menuCurLev;
extern uint8_t menuCurNum;

extern uint8_t keyPressFlag;

void Menu_init(void);

void Menu_setNode(char* name, void* dataBase, dataTypeFlag type, uint8_t level, uint8_t num);

void Menu_display(void);

void Menu_loop(void);

void Menu_loadPara(void);

void Menu_savePara(void);

void Menu_getPinState(void);

#endif