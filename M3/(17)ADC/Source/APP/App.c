/**
  ******************************************************************************
  * @file    APP.c
  * @author  phone
  * @version V1.0
  * @date    2014-12-10
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * @{ʵ��ƽ̨:Ұ�� iSO STM32 ������ 
  * @{�ŵ��ȳ�������	
	* @{ USE_STM3210B_EVAL
	--cpu Cortex-M3 -g --apcs=interwork 
	-I C:\Keil\ARM\RV31\INC 
  ******************************************************************************
  */ 
	
/* Includes ------------------------------------------------------------------*/
#include <stm32f10x.h>
#include "BSP.h"
//#include "bsp_led.h"  
#include "bsp_usart1.h"
#include "bsp_adc.h"

float ADC_ConvertedValueLocal;      

void Delay(__IO u32 nCount); 


#if 1
/**---------------------------------------------------------------------------------
  * @brief       ������.
  * @param    		��
  *	@arg         NULL
  * @retval     null
  ---------------------------------------------------------------------------------*/
int main(void)
{
	/*�����ǵ���ϵͳʱ�ӣ���3.0�汾�Ŀ��У�
	��main������������ã���3.5�汾�У�
	ϵͳʱ�ӷ����������ļ�����
	�������е�ʱ�����ȴ������ຯ��ִ�е�
	�����ļ� 151��    ��
	LDR     R0, =SystemInit			  ;����ϵͳʱ��
	SetSysClock();	
	*/
	/*�������ߵ���*/
	#ifdef DEBUG
		debug();
	#endif
	
	/*����Ӳ����ʼ��*/
	ALL_Config();
	/* enable adc1 and config adc1 to dma mode */
	ADC1_Init();

	printf("\r\n ----����һ��ADCʵ��(DMA����)----\r\n");
/**--------------------------------------------------------------------------------
* @brief       ADC���úú�ֱ�Ӵ����ݵ�ַ����
---------------------------------------------------------------------------------*/
	#if 1
	while(1)
	{
		ADC_ConvertedValueLocal =(float) (*(__IO u16 *)ADC1_DR_Address)/4096*3.3;// ��ȡת����ADֵ
		printf("\r\n The current AD value = 0x%04X \r\n", *(__IO u16 *)ADC1_DR_Address); 	
	  printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal); 
		Delay(0x5fffee);  
	}
	#endif
/**--------------------------------------------------------------------------------
* @brief       ����DMA���ݴ���
---------------------------------------------------------------------------------*/
	#if 0
	while(1)
	{
		ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; // ��ȡת����ADֵ
		printf("\r\n The current AD value = 0x%04X \r\n", ADC_ConvertedValue); 	
	  printf("\r\n The current AD value = %f V \r\n",ADC_ConvertedValueLocal); 
		Delay(0xffffee);  
	}
	#endif
}
#endif

/**---------------------------------------------------------------------------------
  * @brief       CPU��ʱ����
  * @param    		��
  ---------------------------------------------------------------------------------*/
void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}

/**---------------------------------------------------------------------------------
  * @brief       ��⴫�ݸ������Ĳ����Ƿ�����Ч�Ĳ���
  * @param    		��
	* @example		 ĳ��������ȡֵ��Χֻ����С��3������������������Ĳ�������3��
	* @example	   �����assert_param()���������г�����õ��������ʱ����			
  ---------------------------------------------------------------------------------*/
#ifdef DEBUG
void assert_failed(uint8_t* file, uint32_t line){
while (1);}
#endif
/*********************************************END OF FILE**********************/



