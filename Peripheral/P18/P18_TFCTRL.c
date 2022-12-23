/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-22 13:58:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-23 10:53:24
 * @FilePath: \CODE\Peripheral\P18\P18_TFCTRL.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "P18_TFCTRL.h"

tf_function_t P18_X_BSF, P18_Y_BSF;
tf_function_t P18_X_CTRL, P18_Y_CTRL;

float inputs[2] = {0,0};
float BSF_outputs[2] = {0,0};
float CTRL_outputs[2] = {0,0};
float FB_inputs[2] = {0,0};

void P18_tfInit(void)
{
    float num[3] = {1,-1.049,0.57};
    float den[3] = {1,-0.4992,0.0197};
    tf_initZFunction_ND(&P18_X_BSF,num,3,den,3,1,0.0005);
    tf_initZFunction_ND(&P18_Y_BSF,num,3,den,3,1,0.0005);
    tf_initZFunction_ND(&P18_X_CTRL,num,3,den,3,1,0.0005);
    tf_initZFunction_ND(&P18_Y_CTRL,num,3,den,3,1,0.0005);
}

void P18_tfCtrlCallBack(void)
{
  //uint32_t time = systick_getval();
    FB_inputs[0] = P18_getVoltageFromADC(CHANNEL0);
    FB_inputs[1] = P18_getVoltageFromADC(CHANNEL1);
    /*CTRL_outputs[0] =  tf_update(&P18_X_CTRL,inputs[0] - FB_inputs[0]);
    CTRL_outputs[1] =  tf_update(&P18_Y_CTRL,inputs[1] - FB_inputs[1]);
    BSF_outputs[0] = tf_update(&P18_X_BSF,CTRL_outputs[0]);
    BSF_outputs[1] = tf_update(&P18_Y_BSF,CTRL_outputs[1]);
    P18_setVoltageToDAC(BSF_outputs[0], BSF_outputs[1]);*/
    BSF_outputs[0] = tf_update(&P18_X_BSF,inputs[0]);
    BSF_outputs[1] = tf_update(&P18_Y_BSF,inputs[1]);
    P18_setVoltageToDAC(BSF_outputs[0], BSF_outputs[1]);
    //P18_setVoltageToDAC(inputs[0], inputs[1]);
    
    if(DMA1_DMA_CNDTR7->B.NDT == 0)
    {
      memcpy(SCOPE_dataPtr,inputs,8);
      memcpy(SCOPE_dataPtr+8,BSF_outputs,8);
      memcpy(SCOPE_dataPtr+16,CTRL_outputs,8);
      memcpy(SCOPE_dataPtr+24,FB_inputs,8);
      HOST_uartUploadStart();
    }
    /*time = systick_getval()-time;
    float time_s = (float)time/120000000;
    if(time_s)
    {
      time_s = 0;
    }*/
}