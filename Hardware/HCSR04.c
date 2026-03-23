#include "stm32f10x.h"                  // Device header
#include "HCSR04.h"
#include "Timer.h"
#include "Delay.h"

uint16_t Time2;
uint16_t Time3;
uint16_t Time4;

void HCSR04_Init()
{
	RCC_APB2PeriphClockCmd(Trig_RCC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = Trig_Pin | GPIO_Pin_4 | GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Trig_Port, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Pin = Echo_Pin | GPIO_Pin_5 | GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Echo_Port, &GPIO_InitStruct);
	
	GPIO_ResetBits(Trig_Port, Trig_Pin);
	
}

void HCSR04_Start2()
{
	GPIO_SetBits(Trig_Port, Trig_Pin);
	Delay_us(45);
	GPIO_ResetBits(Trig_Port, Trig_Pin);
	Timer_Init();
}

uint16_t HCSR04_GetValue2()
{
	HCSR04_Start2();
	Delay_ms(100);
	return ((Time2 * 0.0001) * 34000) / 2;
//	return Time;
}

void HCSR04_Start3()
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	Delay_us(45);
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	Timer_Init();
}

uint16_t HCSR04_GetValue3()
{
	HCSR04_Start3();
	Delay_ms(100);
	return ((Time3 * 0.0001) * 34000) / 2;
//	return Time;
}

void HCSR04_Start4()
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
	Delay_us(45);
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	Timer_Init();
}

uint16_t HCSR04_GetValue4()
{
	HCSR04_Start4();
	Delay_ms(100);
	return ((Time4 * 0.0001) * 34000) / 2;
//	return Time;
}
