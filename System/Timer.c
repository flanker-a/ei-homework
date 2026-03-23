#include "stm32f10x.h"                  // Device header
#include "Timer.h"

extern uint16_t Time2;
extern uint16_t Time3;
extern uint16_t Time4;


void Timer_Init()
{
	Time2 = 0;
	Time3 = 0;
	Time4 = 0;
	//选择APB1总线下的定时器Timer2
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	
	
	TIM_InternalClockConfig(TIM2);		//TIM2使用内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;		//计数模式，此处为向上计数
	TIM_TimeBaseInitStructure.TIM_Period = 7199;		//ARR 1 = 0.0001S
	TIM_TimeBaseInitStructure.TIM_Prescaler = 0;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;		
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);		//使能中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;		//中断通道选择
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//优先级，同上
	
	NVIC_Init(&NVIC_InitStructure);
	
			//打开定时器
	//选择APB1总线下的定时器Timer3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	
	
	TIM_InternalClockConfig(TIM3);		//TIM3使用内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure3;
	TIM_TimeBaseInitStructure3.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure3.TIM_CounterMode = TIM_CounterMode_Up;		//计数模式，此处为向上计数
	TIM_TimeBaseInitStructure3.TIM_Period = 7199;		//ARR 1 = 0.0001S
	TIM_TimeBaseInitStructure3.TIM_Prescaler = 0;		//PSC
	TIM_TimeBaseInitStructure3.TIM_RepetitionCounter = 0;		
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure3);
	
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);		//使能中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure3;
	NVIC_InitStructure3.NVIC_IRQChannel = TIM3_IRQn;		//中断通道选择
	NVIC_InitStructure3.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure3.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure3.NVIC_IRQChannelSubPriority = 1;		//优先级，同上
	
	NVIC_Init(&NVIC_InitStructure3);
	
			//打开定时器
	//选择APB1总线下的定时器Timer4
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	
	
	TIM_InternalClockConfig(TIM4);		//TIM4使用内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure4;
	TIM_TimeBaseInitStructure4.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure4.TIM_CounterMode = TIM_CounterMode_Up;		//计数模式，此处为向上计数
	TIM_TimeBaseInitStructure4.TIM_Period = 7199;		//ARR 1 = 0.0001S
	TIM_TimeBaseInitStructure4.TIM_Prescaler = 0;		//PSC
	TIM_TimeBaseInitStructure4.TIM_RepetitionCounter = 0;		
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure4);
	
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);		//使能中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure4;
	NVIC_InitStructure4.NVIC_IRQChannel = TIM4_IRQn;		
	NVIC_InitStructure4.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure4.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure4.NVIC_IRQChannelSubPriority = 0;		
	
	NVIC_Init(&NVIC_InitStructure4);
	
	TIM_Cmd(TIM2, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
	TIM_Cmd(TIM4, ENABLE);		
}

void TIM2_IRQHandler()		
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{

		if (GPIO_ReadInputDataBit(Echo_Port, Echo_Pin) == 1)
		{
			Time2 ++;
		}
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		
	}
}

void TIM3_IRQHandler()		
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
	{

		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5) == 1)
		{
			Time3 ++;
		}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);		
	}
}

void TIM4_IRQHandler()		
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{

		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 1)
		{
			Time4 ++;
		}
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);		
	}
}
