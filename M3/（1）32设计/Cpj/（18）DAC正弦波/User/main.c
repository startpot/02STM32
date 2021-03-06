/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   DAC输出正弦波例程 PA4 PA5双通道输出（板子的PA4引脚复用会影响输出电压）
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 iSO STM32 开发板 
  * 论坛    :http://www.chuxue123.com
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "bsp_dac.h"


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
			/*初始化DAC，开始DAC转换*/
			DAC_Mode_Init();
	
  	  while(1);	 
}

/*********************************************END OF FILE**********************/

