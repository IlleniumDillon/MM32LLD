/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2023-01-20 11:16:45
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-20 13:21:18
 * @FilePath: \CODE\Code\Ctrl\PathPlan\PathPlan.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "PathPlan.h"

void PP_poly5dInit(poly5d* p, float s0, float v0, float a0, float step)
{
    p->s0 = s0;
    p->v0 = v0;
    p->a0 = a0;
    p->timeStep = step;
    p->stepToGo = 0;
}

void PP_poly5dNewPos(poly5d* p, float sf, float vf, float af, float tf)
{
    p->c[0] = p->s0;
    p->c[1] = p->v0;
    p->c[2] = p->a0 / 2;
    p->c[3] = (20*sf - 20*p->s0 - (8*vf + 12*p->v0)*tf - (3*p->a0 - af)*tf*tf) / (2*tf*tf*tf);
    p->c[4] = (30*p->s0 - 30*sf + (14*vf + 16*p->v0)*tf + (3*p->a0 - 2*af)*tf*tf) / (2*tf*tf*tf*tf);
    p->c[5] = (12*sf - 12*p->s0 - (6*vf + 6*p->v0)*tf - (p->a0 - af)*tf*tf) / (2*tf*tf*tf*tf*tf);

    p->stepToGo = (int)(tf / p->timeStep);

    p->s0 = sf;
    p->v0 = vf;
    p->a0 = af;

    p->tNow = 0;
}

float PP_poly5dOneStep(poly5d* p)
{
    if(p->stepToGo <= 0) return p->s0;
    p->tNow += p->timeStep;
    p->stepToGo--;
    return p->c[0] + 
           p->c[1] * p->tNow + 
           p->c[2] * p->tNow * p->tNow + 
           p->c[3] * p->tNow * p->tNow * p->tNow + 
           p->c[4] * p->tNow * p->tNow * p->tNow * p->tNow + 
           p->c[5] * p->tNow * p->tNow * p->tNow * p->tNow * p->tNow;
}