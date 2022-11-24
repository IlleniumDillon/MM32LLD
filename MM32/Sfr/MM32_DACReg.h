/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-11-17 18:20:42
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-11-23 21:03:25
 * @FilePath: \CODE\MM32\Sfr\MM32_DACReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_DACREG_H_
#define _MM32_DACREG_H_

#include "MM32_RegBase.h"

#include "MM32_DACRegDef.h"

#define MOUDLE_DAC		((MM32_DAC*)DAC_BASE)

#define DAC_CR		((MM32_DAC_CR*)(DAC_BASE+0x00))

#define DAC_SWTRIGR		((MM32_DAC_SWTRIGR*)(DAC_BASE+0x04))

#define DAC_DHR12R1 		((MM32_DAC_DHR12R1 *)(DAC_BASE+0x08))

#define DAC_DHR12L1		((MM32_DAC_DHR12L1*)(DAC_BASE+0x0C))

#define DAC_DHR8R1		((MM32_DAC_DHR8R1*)(DAC_BASE+0x10))

#define DAC_DHR12R2		((MM32_DAC_DHR12R2*)(DAC_BASE+0x14))

#define DAC_DHR12L2		((MM32_DAC_DHR12L2*)(DAC_BASE+0x18))

#define DAC_DHR8R2		((MM32_DAC_DHR8R2*)(DAC_BASE+0x1C))

#define DAC_DHR12RD		((MM32_DAC_DHR12RD*)(DAC_BASE+0x20))

#define DAC_DHR12LD		((MM32_DAC_DHR12LD*)(DAC_BASE+0x24))

#define DAC_DHR8RD		((MM32_DAC_DHR8RD*)(DAC_BASE+0x28))

#define DAC_DOR1		((MM32_DAC_DOR1*)(DAC_BASE+0x2C))

#define DAC_DOR2		((MM32_DAC_DOR2*)(DAC_BASE+0x30))

#endif