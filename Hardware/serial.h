#ifndef __serial_h
#define __serial_h

void serial_init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);
uint16_t serial_receivebyte(void);
uint8_t get_serialflag(void);

#endif
