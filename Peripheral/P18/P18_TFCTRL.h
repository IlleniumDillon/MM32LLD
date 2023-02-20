/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-22 13:58:02
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-20 13:18:14
 * @FilePath: \CODE\Peripheral\P18\P18_TFCTRL.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _P18_TFCTRL_H_
#define _P18_TFCTRL_H_

#include "P18_CMD.h"
#include "P18_Analog.h"
#include "tf.h"
#include "HOST.h"
#include "BoucWen.h"
#include "PathPlan.h"

extern tf_function_t P18_X_BSF, P18_Y_BSF;
extern tf_function_t P18_X_CTRL, P18_Y_CTRL;
extern float inputs[2];
extern float BSF_outputs[2];
extern float CTRL_outputs[2];
extern float FB_inputs[2];
extern poly5d P18_PP_X;
extern poly5d P18_PP_Y;

void P18_tfInit(void);

void P18_tfCtrlCallBack(void);

#endif