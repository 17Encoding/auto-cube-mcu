#include "main.h"
#include "usart.h"
#include "stm32f4xx_it.h"

extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart1;

void NMI_Handler(void)
{

  while (1)
  {
  }
}

void HardFault_Handler(void)
{
  while (1)
  {

  }
}

void MemManage_Handler(void)
{
  while (1)
  {

  }
}

void BusFault_Handler(void)
{

  while (1)
  {

  }
}

void UsageFault_Handler(void)
{
  while (1)
  {

  }
}


void SVC_Handler(void)
{

}

void DebugMon_Handler(void)
{

}

void PendSV_Handler(void)
{

}

void SysTick_Handler(void)
{

  HAL_IncTick();

}

void USART1_IRQHandler(void)
{
	uint32_t tmp_flag=0;
	uint32_t temp;
	tmp_flag=__HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE);
	if(tmp_flag!=RESET){
		__HAL_UART_CLEAR_IDLEFLAG(&huart1);
		HAL_UART_DMAStop(&huart1);
		temp=__HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
		rxlen=BUFF_SIZE-temp;
		rec_end_flag=1;
	}
  HAL_UART_IRQHandler(&huart1);

}

void DMA2_Stream2_IRQHandler(void)
{

  HAL_DMA_IRQHandler(&hdma_usart1_rx);

}

void DMA2_Stream7_IRQHandler(void)
{

  HAL_DMA_IRQHandler(&hdma_usart1_tx);

}

