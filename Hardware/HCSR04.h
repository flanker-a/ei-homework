#ifndef __HCSR04_H
#define __HCSR04_H

#define Trig_Port 		GPIOA
#define Trig_Pin 		GPIO_Pin_6
#define Trig_RCC		RCC_APB2Periph_GPIOA

#define Echo_Port 		GPIOA
#define Echo_Pin 		GPIO_Pin_7
#define Echo_RCC		RCC_APB2Periph_GPIOA

void HCSR04_Init(void);

uint16_t HCSR04_GetValue2(void);
uint16_t HCSR04_GetValue3(void);
uint16_t HCSR04_GetValue4(void);

#endif 
