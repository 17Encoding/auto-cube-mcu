#include "main.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"
#include "bsp_key.h"
#include "bsp_stepper_init.h"
#include "core_delay.h"
#define  DIV  2
void SystemClock_Config(void);

int main(void)
{
	int key_val=0;
  int i=0;
  int dir_val=CW;
  int angle_val=90;
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
	Key_GPIO_Config();
	stepper_Init();
	
  while(1){
		if(rec_end_flag==1){
				HAL_UART_Transmit_DMA(&huart1, (uint8_t*)buff, rxlen);
				delay_ms(1);
				rec_end_flag=0;
				break;
				/*
				rxlen=0;
				rec_end_flag=0;
				for(uint8_t i=0; i<rxlen; i++){
					buff[i]=0;
				}
				*/
			}
		HAL_UART_Receive_DMA(&huart1, (uint8_t*)buff, BUFF_SIZE);
	}
	/*
	buff[0]='R';
	buff[1]='L';
	buff[2]='U';
	buff[3]='D';
	buff[4]='F';
	buff[5]='B';
	buff[6]='r';
	buff[7]='l';
	buff[8]='u';
	buff[9]='d';
	buff[10]='f';
	buff[11]='b';
	rxlen=12;*/
  while (1)
  {
		
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_PIN) == KEY_ON  )
    {
			for(int i=0; i<rxlen; i++){
				//while( Key_Scan(KEY1_GPIO_PORT,KEY1_PIN) != KEY_ON  );
				switch(buff[i]){
				case 'R':
					stepper_turn_r(1000,90,DIV,CCW);//R
					break;
				case 'r':
					stepper_turn_r(1000,90,DIV,CW);//R'
					break;
				case 'K':
					stepper_turn_r(1000,180,DIV,CCW);//2R
					break;
				case 'L':
					stepper_turn_l(1000,90,DIV,CCW);//L
					break;
				case 'l':
					stepper_turn_l(1000,90,DIV,CW);//L'
					break;
				case 'H':
					stepper_turn_l(1000,180,DIV,CCW);//2L
					break;
				case 'U':
					stepper_turn_u(1000,90,DIV,CCW);//U
					break;
				case 'u':
					stepper_turn_u(1000,90,DIV,CW);//U'
					break;
				case 'N':
					stepper_turn_u(1000,180,DIV,CCW);//2U
					break;
				case 'D':
					stepper_turn_d(1000,90,DIV,CCW);//D
					break;
				case 'd':
					stepper_turn_d(1000,90,DIV,CW);//D'
					break;
				case 'O':
					stepper_turn_d(1000,180,DIV,CCW);//2D
					break;
				case 'F':
					stepper_turn_f(1000,90,DIV,CCW);//F
					break;
				case 'f':
					stepper_turn_f(1000,90,DIV,CW);//F'
					break;
				case 'E':
					stepper_turn_f(1000,180,DIV,CCW);//2F
					break;
				case 'B':
					stepper_turn_b(1000,90,DIV,CCW);//B
					break;
				case 'b':
					stepper_turn_b(1000,90,DIV,CW);//B'
					break;
				case 'Q':
					stepper_turn_b(1000,180,DIV,CCW);//2B
					break;
				}
				delay_ms(50);
			}
			break;
    }
	}
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

