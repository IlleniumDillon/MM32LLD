/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2023-01-20 11:16:40
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-20 13:13:32
 * @FilePath: \CODE\Code\Ctrl\PathPlan\PathPlan.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _PATHPLAN_H_
#define _PATHPLAN_H_

typedef struct _poly5d
{
    float c[6];
    float s0,v0,a0;
    float timeStep;
    int stepToGo;
    float tNow;
}poly5d;

void PP_poly5dInit(poly5d* p, float s0, float v0, float a0, float step);

void PP_poly5dNewPos(poly5d* p, float sf, float vf, float af, float tf);

float PP_poly5dOneStep(poly5d* p);

#endif