/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-12-11 15:53:14
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-11 15:54:16
 * @FilePath: \CODE\MM32\Sfr\MM32_CRCReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_CRCREG_H_
#define _MM32_CRCREG_H_

#include "MM32_RegBase.h"

#include "MM32_CRCRegDef.h"

#define MOUDLE_CRC		((MM32_CRC*)CRC_BASE)

#define CRC_DR		((MM32_CRC_DR*)(CRC_BASE+0x00))

#define CRC_IDR		((MM32_CRC_IDR*)(CRC_BASE+0x04))

#define CRC_CR		((MM32_CRC_CR*)(CRC_BASE+0x08))

#define CRC_MIR		((MM32_CRC_MIR*)(CRC_BASE+0x0C))

#endif