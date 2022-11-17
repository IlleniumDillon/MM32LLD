/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-10 15:58:30
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-11 20:33:37
 * @FilePath: \CODE\Code\Menu\menuTask.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MENUTASK_H_
#define _MENUTASK_H_

#include "P18_CTRL.h"
#include "OLED.h"
#include "menu.h"

void menu_selfCheck(void);

void menu_loopSet(void);

void menu_ADSet(void);

void menu_baudSet(void);

void menu_FBtimeSet(void);

void menu_FBStart(void);
void menu_FBStop(void);

void menu_CH1Set(void);
void menu_CH2Set(void);

void menu_waveDef(void);
void menu_waveSend(void);
void menu_waveStop(void);

void menu_setVolt0(void);
void menu_setVolt100(void);

#endif