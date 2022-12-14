/*
 * @Author: IlleniumDillon 147900130@qq.com
 * @Date: 2022-10-30 13:43:27
 * @LastEditors: IlleniumDillon 147900130@qq.com
 * @LastEditTime: 2022-12-12 14:59:00
 * @FilePath: \CODE\MM32\Sfr\MM32_DMAReg.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _MM32_DMAREG_H_
#define _MM32_DMAREG_H_

#include "MM32_RegBase.h"

#include "MM32_DMARegDef.h"

#define MOUDLE_DMA1		((MM32_DMA*)DMA1_BASE)

#define MOUDLE_DMA2		((MM32_DMA*)DMA2_BASE)

#define DMA1_DMA_ISR		((MM32_DMA_ISR*)(DMA1_BASE+0X00))

#define DMA1_DMA_IFCR		((MM32_DMA_IFCR*)(DMA1_BASE+0X04))

#define DMA1_DMA_CCR1		((MM32_DMA_CCR1*)(DMA1_BASE+0X08))

#define DMA1_DMA_CNDTR1		((MM32_DMA_CNDTR1*)(DMA1_BASE+0X0C))

#define DMA1_DMA_CPAR1		((MM32_DMA_CPAR1*)(DMA1_BASE+0X10))

#define DMA1_DMA_CMAR1		((MM32_DMA_CMAR1*)(DMA1_BASE+0X14))

#define DMA1_DMA_CCR2		((MM32_DMA_CCR2*)(DMA1_BASE+0X1C))

#define DMA1_DMA_CNDTR2		((MM32_DMA_CNDTR2*)(DMA1_BASE+0X20))

#define DMA1_DMA_CPAR2		((MM32_DMA_CPAR2*)(DMA1_BASE+0X24))

#define DMA1_DMA_CMAR2		((MM32_DMA_CMAR2*)(DMA1_BASE+0X28))

#define DMA1_DMA_CCR3		((MM32_DMA_CCR3*)(DMA1_BASE+0X30))

#define DMA1_DMA_CNDTR3		((MM32_DMA_CNDTR3*)(DMA1_BASE+0X34))

#define DMA1_DMA_CPAR3		((MM32_DMA_CPAR3*)(DMA1_BASE+0X38))

#define DMA1_DMA_CMAR3		((MM32_DMA_CMAR3*)(DMA1_BASE+0X3C))

#define DMA1_DMA_CCR4		((MM32_DMA_CCR4*)(DMA1_BASE+0X44))

#define DMA1_DMA_CNDTR4		((MM32_DMA_CNDTR4*)(DMA1_BASE+0X48))

#define DMA1_DMA_CPAR4		((MM32_DMA_CPAR4*)(DMA1_BASE+0X4C))

#define DMA1_DMA_CMAR4		((MM32_DMA_CMAR4*)(DMA1_BASE+0X50))

#define DMA1_DMA_CCR5		((MM32_DMA_CCR5*)(DMA1_BASE+0X58))

#define DMA1_DMA_CNDTR5		((MM32_DMA_CNDTR5*)(DMA1_BASE+0X5C))

#define DMA1_DMA_CPAR5		((MM32_DMA_CPAR5*)(DMA1_BASE+0X60))

#define DMA1_DMA_CMAR5		((MM32_DMA_CMAR5*)(DMA1_BASE+0X64))

#define DMA1_DMA_CCR6		((MM32_DMA_CCR6*)(DMA1_BASE+0X6C))

#define DMA1_DMA_CNDTR6		((MM32_DMA_CNDTR6*)(DMA1_BASE+0X70))

#define DMA1_DMA_CPAR6		((MM32_DMA_CPAR6*)(DMA1_BASE+0X74))

#define DMA1_DMA_CMAR6		((MM32_DMA_CMAR6*)(DMA1_BASE+0X78))

#define DMA1_DMA_CCR7		((MM32_DMA_CCR7*)(DMA1_BASE+0X80))

#define DMA1_DMA_CNDTR7		((MM32_DMA_CNDTR7*)(DMA1_BASE+0X84))

#define DMA1_DMA_CPAR7		((MM32_DMA_CPAR7*)(DMA1_BASE+0X88))

#define DMA1_DMA_CMAR7		((MM32_DMA_CMAR7*)(DMA1_BASE+0X8C))

#define DMA2_DMA_ISR		((MM32_DMA_ISR*)(DMA2_BASE+0X00))

#define DMA2_DMA_IFCR		((MM32_DMA_IFCR*)(DMA2_BASE+0X04))

#define DMA2_DMA_CCR1		((MM32_DMA_CCR1*)(DMA2_BASE+0X08))

#define DMA2_DMA_CNDTR1		((MM32_DMA_CNDTR1*)(DMA2_BASE+0X0C))

#define DMA2_DMA_CPAR1		((MM32_DMA_CPAR1*)(DMA2_BASE+0X10))

#define DMA2_DMA_CMAR1		((MM32_DMA_CMAR1*)(DMA2_BASE+0X14))

#define DMA2_DMA_CCR2		((MM32_DMA_CCR2*)(DMA2_BASE+0X1C))

#define DMA2_DMA_CNDTR2		((MM32_DMA_CNDTR2*)(DMA2_BASE+0X20))

#define DMA2_DMA_CPAR2		((MM32_DMA_CPAR2*)(DMA2_BASE+0X24))

#define DMA2_DMA_CMAR2		((MM32_DMA_CMAR2*)(DMA2_BASE+0X28))

#define DMA2_DMA_CCR3		((MM32_DMA_CCR3*)(DMA2_BASE+0X30))

#define DMA2_DMA_CNDTR3		((MM32_DMA_CNDTR3*)(DMA2_BASE+0X34))

#define DMA2_DMA_CPAR3		((MM32_DMA_CPAR3*)(DMA2_BASE+0X38))

#define DMA2_DMA_CMAR3		((MM32_DMA_CMAR3*)(DMA2_BASE+0X3C))

#define DMA2_DMA_CCR4		((MM32_DMA_CCR4*)(DMA2_BASE+0X44))

#define DMA2_DMA_CNDTR4		((MM32_DMA_CNDTR4*)(DMA2_BASE+0X48))

#define DMA2_DMA_CPAR4		((MM32_DMA_CPAR4*)(DMA2_BASE+0X4C))

#define DMA2_DMA_CMAR4		((MM32_DMA_CMAR4*)(DMA2_BASE+0X50))

#define DMA2_DMA_CCR5		((MM32_DMA_CCR5*)(DMA2_BASE+0X58))

#define DMA2_DMA_CNDTR5		((MM32_DMA_CNDTR5*)(DMA2_BASE+0X5C))

#define DMA2_DMA_CPAR5		((MM32_DMA_CPAR5*)(DMA2_BASE+0X60))

#define DMA2_DMA_CMAR5		((MM32_DMA_CMAR5*)(DMA2_BASE+0X64))

/*#define DMA2_DMA_CCR6		((MM32_DMA_CCR6*)(DMA2_BASE+0XA8))

#define DMA2_DMA_CNDTR6		((MM32_DMA_CNDTR6*)(DMA2_BASE+0XAC))

#define DMA2_DMA_CPAR6		((MM32_DMA_CPAR6*)(DMA2_BASE+0XB0))

#define DMA2_DMA_CMAR6		((MM32_DMA_CMAR6*)(DMA2_BASE+0XB4))

#define DMA2_DMA_CCR7		((MM32_DMA_CCR7*)(DMA2_BASE+0XC8))

#define DMA2_DMA_CNDTR7		((MM32_DMA_CNDTR7*)(DMA2_BASE+0XCC))

#define DMA2_DMA_CPAR7		((MM32_DMA_CPAR7*)(DMA2_BASE+0XD0))

#define DMA2_DMA_CMAR7		((MM32_DMA_CMAR7*)(DMA2_BASE+0XD4))*/

#endif
