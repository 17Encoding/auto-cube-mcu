#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

extern UART_HandleTypeDef huart1;

#define BUFF_SIZE 100
extern volatile uint8_t rxlen;
extern volatile uint8_t rec_end_flag;
extern uint8_t buff[35];

void MX_USART1_UART_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */


