#ifndef __adc_h
#define __adc_h

void ad_init(void);
uint32_t ad_getvalue(void);
uint8_t ad_judge(uint32_t a);
#endif
