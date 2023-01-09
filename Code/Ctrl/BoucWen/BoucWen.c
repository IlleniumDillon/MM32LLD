/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2023-01-07 14:35:29
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-09 11:08:52
 * @FilePath: \CODE\Code\Ctrl\BoucWen\BoucWen.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BoucWen.h"

float _abs(float a)
{
    return a > 0 ? a : -a;
}

float BoucWen(float xdot, float z, float A, float Beta, float Gamma)
{
    return A * xdot - 
           Beta * _abs(xdot) * _abs(z) * z -
           Gamma * xdot * _abs(z) * _abs(z);
}

float BoucWen_getZ(BoucWenPram* parm, float x)
{
    float xdot = (x - parm->xlast) / parm->t;
    xdot = 0.7 * xdot + 0.3 * parm->xdotlast;
    float z = parm->zlast + parm->t * BoucWen(xdot, parm->zlast, parm->A, parm->Beta, parm->Gamma);
    parm->xlast = x;
    parm->zlast = z;
    parm->xdotlast = xdot;
    return z;
}