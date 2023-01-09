/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-22 13:58:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2023-01-09 11:09:37
 * @FilePath: \CODE\Peripheral\P18\P18_TFCTRL.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "P18_TFCTRL.h"

tf_function_t P18_X_BSF, P18_Y_BSF;
tf_function_t P18_X_CTRL, P18_Y_CTRL;

BoucWenPram P18_Bouc1;
BoucWenPram P18_Bouc2;

float inputs[2] = {0,0};
float BSF_outputs[2] = {0,0};
float CTRL_outputs[2] = {0,0};
float FB_inputs[2] = {0,0};
float k_FF[2] = {1.09,1.09};

void P18_tfInit(void)
{
    float num_BSF_X[3] = {1,-1.049,0.57};
    float den_BSF_X[3] = {1,-0.4992,0.0197};
    tf_initZFunction_ND(&P18_X_BSF,num_BSF_X,3,den_BSF_X,3,1,0.0005);

    float num_BSF_Y[3] = {1,-1.397,0.6688};
    float den_BSF_Y[3] = {1,-0.7281,2.271e-14};
    tf_initZFunction_ND(&P18_Y_BSF,num_BSF_Y,3,den_BSF_Y,3,1,0.0005);

    float num_CTRL_X[1] = {0.0005};
    float den_CTRL_X[2] = {1,-1};
    tf_initZFunction_ND(&P18_X_CTRL,num_CTRL_X,1,den_CTRL_X,2,1,0.0005);
    th_setLimit(&P18_X_CTRL,-9,9);
    
    float num_CTRL_Y[1] = {0.000025};
    float den_CTRL_Y[2] = {1,-1};
    tf_initZFunction_ND(&P18_Y_CTRL,num_CTRL_Y,1,den_CTRL_Y,2,1,0.0005);
    th_setLimit(&P18_Y_CTRL,-9,9);
    
    //P18_Bouc1.A = 0.226;
    //P18_Bouc1.Beta = 1.856;
    //P18_Bouc1.bias = 0.173;
    //P18_Bouc1.Gamma = /*-0.707*/0;
    //P18_Bouc1.t = 0.0005;
    //P18_Bouc1.xlast = 0;
    //P18_Bouc1.zlast = 0;
    //P18_Bouc1.xdotlast = 0;
    
    P18_Bouc1.A = 0.264;
    P18_Bouc1.Beta = 1.145;
    P18_Bouc1.bias = 0.105;
    P18_Bouc1.Gamma = 0.378;
    P18_Bouc1.t = 0.0005;
    P18_Bouc1.xlast = 0;
    P18_Bouc1.zlast = 0;
    P18_Bouc1.xdotlast = 0;

    P18_Bouc2.A = 0.264;
    P18_Bouc2.Beta = 1.145;
    P18_Bouc2.bias = 0.105;
    P18_Bouc2.Gamma = 0.378;
    P18_Bouc2.t = 0.0005;
    P18_Bouc2.xlast = 0;
    P18_Bouc2.zlast = 0;
    P18_Bouc2.xdotlast = 0;
}

void P18_tfCtrlCallBack(void)
{
  //uint32_t time = systick_getval();
    FB_inputs[0] = P18_getVoltageFromADC(CHANNEL0);
    FB_inputs[1] = P18_getVoltageFromADC(CHANNEL1);
    
    //滞回位移
    float Z1 = BoucWen_getZ(&P18_Bouc1, inputs[0]) - P18_Bouc1.bias;
    float Z2 = BoucWen_getZ(&P18_Bouc2, inputs[1]) - P18_Bouc2.bias;

    //前馈PI加带阻滤波
    /*
    //PI
    CTRL_outputs[0] =  tf_update(&P18_X_CTRL,inputs[0] - FB_inputs[0]);
    CTRL_outputs[1] =  tf_update(&P18_Y_CTRL,inputs[1] - FB_inputs[1]);
    //前馈
    CTRL_outputs[0] = CTRL_outputs[0] + inputs[0] * k_FF[0];
    CTRL_outputs[1] = CTRL_outputs[1] + inputs[1] * k_FF[1];
    //滤波
    BSF_outputs[0] = tf_update(&P18_X_BSF,CTRL_outputs[0]);
    BSF_outputs[1] = tf_update(&P18_Y_BSF,CTRL_outputs[1]);
    P18_setVoltageToDAC(BSF_outputs[0], BSF_outputs[1]);*/

    //带阻滤波闭环 加BoucWen前馈
    CTRL_outputs[0] = tf_update(&P18_X_CTRL,inputs[0] - FB_inputs[0]);
    CTRL_outputs[1] = tf_update(&P18_Y_CTRL,inputs[1] - FB_inputs[1]);
    BSF_outputs[0] = tf_update(&P18_X_BSF,CTRL_outputs[0] + Z1 + inputs[0]);
    BSF_outputs[1] = tf_update(&P18_Y_BSF,CTRL_outputs[1] + Z2 + inputs[1]);
    P18_setVoltageToDAC(BSF_outputs[0], BSF_outputs[1]);
    //P18_setVoltageToDAC(CTRL_outputs[0], CTRL_outputs[1]);

    //带阻滤波开环测试
    /*BSF_outputs[0] = tf_update(&P18_X_BSF,inputs[0]);
    BSF_outputs[1] = tf_update(&P18_Y_BSF,inputs[1]);
    P18_setVoltageToDAC(BSF_outputs[0], BSF_outputs[1]);*/

    //开环BOUCWEN前馈
    //BSF_outputs[0] = /*inputs[0] + */Z1;
    //BSF_outputs[1] = /*inputs[1] + */Z2;
    //P18_setVoltageToDAC(BSF_outputs[0], BSF_outputs[1]);
    //纯开环
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