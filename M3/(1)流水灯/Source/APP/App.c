/**
  ******************************************************************************
  * @file    APP.c
  * @author  phone
  * @version V1.0
  * @date    2014-11-06
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * @{实验平台:野火 iSO STM32 开发板 
  * @{雅典娜程序整理	
	* @{ USE_STM3210B_EVAL
	--cpu Cortex-M3 -g --apcs=interwork 
	-I C:\Keil\ARM\RV31\INC 
  ******************************************************************************
  */ 
	
/* Includes ------------------------------------------------------------------*/
#include <stm32f10x.h>
#include "BSP.h"
#include "bsp_led.h"  

void Delay(__IO u32 nCount); 

#if 1
/**---------------------------------------------------------------------------------
  * @brief       主函数.
  * @param    		无
  *	@arg         NULL
  * @retval     null
  ---------------------------------------------------------------------------------*/
int main(void)
{
	/*首先是调用系统时钟，在3.0版本的库中，
	在main函数中仍需调用，在3.5版本中，
	系统时钟放在了启动文件这里
	函数运行的时候是先从这个汇编函数执行的
	启动文件 151行    ：
	LDR     R0, =SystemInit			  ;设置系统时钟
	SetSysClock();	
	*/
	/*便于在线调试*/
	#ifdef DEBUG
		debug();
	#endif
	
	/*外设硬件初始化*/
	ALL_Config();

/**----------------------------------------------------------------------
* @brief 方法1，直接控制寄存器
-----------------------------------------------------------------------*/
	#if 0
	while(1)
	{
		// ODR GPIOB
		// 15 14 13 12     11 10 9 8    7 6 5 4    3 2 1 0
		// 0  0  0  0      0  0  0 0    0 0 0 0    0 0 0 0 (复位值)
		// 1  1  1  1      1  1  1 1    1 1 1 1    1 1 1 0

		GPIOB->ODR = 0XFFFE; 		//低电平，GPIOB0（LED0）灯亮
		Delay(0x0FFFFF);
		GPIOB->ODR = 0XFFFF;		//高电平，GPIOB0（LED0）灯灭

		// ODR GPIOF
		// 15 14 13 12     11 10 9 8    7 6 5 4    3 2 1 0
		// 0  0  0  0      0  0  0 0    0 0 0 0    0 0 0 0 (复位值)
		// 1  1  1  1      1  1  1 1    0 1 1 1    1 1 1 1	
		GPIOF->ODR = 0XFF7F; 		//低电平，GPIOF7（LED1）灯亮
		Delay(0x0FFFFF);
		GPIOF->ODR = 0XFFFF;		//高电平，GPIOF7（LED1）灯亮

		// ODR GPIOF
		// 15 14 13 12     11 10 9 8    7 6 5 4    3 2 1 0
		// 0  0  0  0      0  0  0 0    0 0 0 0    0 0 0 0 (复位值)
		// 1  1  1  1      1  1  1 0    1 1 1 1    1 1 1 1		 	
		GPIOF->ODR = 0XFEFF; 		//低电平，GPIOF8（LED2）灯亮
		Delay(0x0FFFFF);
		GPIOF->ODR = 0XFFFF;		//高电平，GPIOF8（LED2）灯亮 
	}
	#endif
	
/**----------------------------------------------------------------------
* @brief 方法2，使用固件库控制IO
-----------------------------------------------------------------------*/
	#if 0
	while(1)
	{
		LED1( ON );			  // 亮
		Delay(0x0FFFFF);
		LED1( OFF );		  // 灭

		LED2( ON );			  // 亮
		Delay(0x0FFFFF);
		LED2( OFF );		  // 灭

		LED3( ON );			  // 亮
		Delay(0x0FFFFF);
		LED3( OFF );		  // 灭	   
	}
	#endif	
	
/**----------------------------------------------------------------------
* @brief 方法3，使用寄存器控制IO
-----------------------------------------------------------------------*/
	#if 1
	while(1)
	{

		LED1_TOGGLE;	 			//led1状态反转，亮	
    Delay(0x0FFFFF); 
		LED1_TOGGLE;				//led1状态反转，灭

		LED2_TOGGLE;				//led2状态反转，亮
		Delay(0x0FFFFF);	   
		LED2_TOGGLE;		  	//led2状态反转，灭

		LED3_TOGGLE;				//led3状态反转，亮
		Delay(0x0FFFFF);
		LED3_TOGGLE;				//led3状态反转，灭
	}
	#endif	
}
#endif

/**---------------------------------------------------------------------------------
  * @brief       CPU延时函数
  * @param    		无
  ---------------------------------------------------------------------------------*/
void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}

/**---------------------------------------------------------------------------------
  * @brief       检测传递给函数的参数是否是有效的参数
  * @param    		无
	* @example		 某个参数的取值范围只能是小于3的正整数，如果给出的参数大于3，
	* @example	   则这个assert_param()可以再运行程序调用到这个函数时报错			
  ---------------------------------------------------------------------------------*/
#ifdef DEBUG
void assert_failed(uint8_t* file, uint32_t line){
while (1);}
#endif
/*********************************************END OF FILE**********************/




