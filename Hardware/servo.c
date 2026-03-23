#include "stm32f10x.h"                  // Device header
#include "pwm.h"

void servo_init(void)
{
	PWM_Init();									
}

void servo_angle(float angle)
{
	PWM_SetCompare1(angle / 180 * 2000 + 500);
}
