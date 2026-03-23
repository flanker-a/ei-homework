#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "HCSR04.h"
#include "Delay.h"
#include "serial.h"
#include "servo.h"
#include "adc.h"
#include "led.h"

uint16_t T2,T3,T4;
uint8_t flag;
uint16_t k = 0;

int main(void)
{
	OLED_Init();
	HCSR04_Init();
	LED_Init();
	serial_init();
	servo_init();
	ad_init();
	
	
	while (1)
	{
		T2 = HCSR04_GetValue2();
		T3 = HCSR04_GetValue3();
		T4 = HCSR04_GetValue4();
		if(T2 < 10)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_12);
			GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		}
		else if(T2 >= 10)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_13);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		}
		
		
		if(T3 < 10)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_14);
			GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		}
		else if(T3 >= 10)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_15);
			GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		}
		
		
		if(T4 < 10)
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_11);
			GPIO_ResetBits(GPIOA,GPIO_Pin_12);
		}
		else if(T4 >= 10)
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_12);
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);
		}
//		
//		k = serial_receivebyte();
//		if(k == 0x0031)
//		{
//			servo_angle(90);
//			if(ad_judge(ad_getvalue()) == 1)
//			{
//				servo_angle(0);
//			}
//		}
//		else
//		{
			if(ad_judge(ad_getvalue()) == 1)
			{
				servo_angle(0);
			}
//			
//		}
//		OLED_ShowNum(1, 10, T2, 3);
//		Delay_ms(100);
	}
}
