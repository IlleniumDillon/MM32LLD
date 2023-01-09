/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2023-01-07 14:35:18
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-09 11:08:39
 * @FilePath: \CODE\Code\Ctrl\BoucWen\BoucWen.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _BOUCWEN_H_
#define _BOUCWEN_H_

typedef struct _BoucWenPram
{
    float A;
    float Beta;
    float Gamma;
    float t;
    float bias;
    float zlast;
    float xlast;
    float xdotlast;
}BoucWenPram;


float BoucWen(float xdot, float z, float A, float Beta, float Gamma);

float BoucWen_getZ(BoucWenPram* parm, float x);

#endif