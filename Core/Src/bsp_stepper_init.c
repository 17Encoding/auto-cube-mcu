#include "bsp_stepper_init.h"
#include "core_delay.h"   
#include "stm32f4xx.h"

//右电机转动函数
void stepper_turn_r(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*根据细分数求得步距角被分成多少个方波*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //顺时针
  {
    MOTOR_DIR_R(CW);
  }
  else if(dir==CCW)//逆时针
  {
    MOTOR_DIR_R(CCW);
  }
  /*开使能*/
  MOTOR_EN_R(ON);
  /*模拟方波*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_R(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_R(LOW);
    delay_us(tim/2);
  }
  /*关使能*/
  MOTOR_EN_R(OFF);
}

//左电机转动函数
void stepper_turn_l(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*根据细分数求得步距角被分成多少个方波*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //顺时针
  {
    MOTOR_DIR_L(CW);
  }
  else if(dir==CCW)//逆时针
  {
    MOTOR_DIR_L(CCW);
  }
  /*开使能*/
  MOTOR_EN_L(ON);
  /*模拟方波*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_L(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_L(LOW);
    delay_us(tim/2);
  }
  /*关使能*/
  MOTOR_EN_L(OFF);
}

//上电机转动函数
void stepper_turn_u(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*根据细分数求得步距角被分成多少个方波*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //顺时针
  {
    MOTOR_DIR_U(CW);
  }
  else if(dir==CCW)//逆时针
  {
    MOTOR_DIR_U(CCW);
  }
  /*开使能*/
  MOTOR_EN_U(ON);
  /*模拟方波*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_U(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_U(LOW);
    delay_us(tim/2);
  }
  /*关使能*/
  MOTOR_EN_U(OFF);
}

//下电机转动函数
void stepper_turn_d(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*根据细分数求得步距角被分成多少个方波*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //顺时针
  {
    MOTOR_DIR_D(CW);
  }
  else if(dir==CCW)//逆时针
  {
    MOTOR_DIR_D(CCW);
  }
  /*开使能*/
  MOTOR_EN_D(ON);
  /*模拟方波*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_D(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_D(LOW);
    delay_us(tim/2);
  }
  /*关使能*/
  MOTOR_EN_D(OFF);
}

//前电机转动函数
void stepper_turn_f(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*根据细分数求得步距角被分成多少个方波*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //顺时针
  {
    MOTOR_DIR_F(CW);
  }
  else if(dir==CCW)//逆时针
  {
    MOTOR_DIR_F(CCW);
  }
  /*开使能*/
  MOTOR_EN_F(ON);
  /*模拟方波*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_F(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_F(LOW);
    delay_us(tim/2);
  }
  /*关使能*/
  MOTOR_EN_F(OFF);
}

//后电机转动函数
void stepper_turn_b(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*根据细分数求得步距角被分成多少个方波*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //顺时针
  {
    MOTOR_DIR_B(CW);
  }
  else if(dir==CCW)//逆时针
  {
    MOTOR_DIR_B(CCW);
  }
  /*开使能*/
  MOTOR_EN_B(ON);
  /*模拟方波*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_B(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_B(LOW);
    delay_us(tim/2);
  }
  /*关使能*/
  MOTOR_EN_B(OFF);
}


void stepper_Init()
{
  /*定义一个GPIO_InitTypeDef类型的结构体*/
  GPIO_InitTypeDef  GPIO_InitStruct;

  /*开启右电机相关的GPIO外设时钟*/
  MOTOR_DIR_GPIO_CLK_ENABLE_R();
  MOTOR_PUL_GPIO_CLK_ENABLE_R();
  MOTOR_EN_GPIO_CLK_ENABLE_R();
	
	/*开启左电机相关的GPIO外设时钟*/
  MOTOR_DIR_GPIO_CLK_ENABLE_L();
  MOTOR_PUL_GPIO_CLK_ENABLE_L();
  MOTOR_EN_GPIO_CLK_ENABLE_L();
	
	/*开启上电机相关的GPIO外设时钟*/
  MOTOR_DIR_GPIO_CLK_ENABLE_U();
  MOTOR_PUL_GPIO_CLK_ENABLE_U();
  MOTOR_EN_GPIO_CLK_ENABLE_U();
	
	/*开启下电机相关的GPIO外设时钟*/
  MOTOR_DIR_GPIO_CLK_ENABLE_D();
  MOTOR_PUL_GPIO_CLK_ENABLE_D();
  MOTOR_EN_GPIO_CLK_ENABLE_D();
	
	/*开启前电机相关的GPIO外设时钟*/
  MOTOR_DIR_GPIO_CLK_ENABLE_F();
  MOTOR_PUL_GPIO_CLK_ENABLE_F();
  MOTOR_EN_GPIO_CLK_ENABLE_F();
	
	/*开启后电机相关的GPIO外设时钟*/
  MOTOR_DIR_GPIO_CLK_ENABLE_B();
  MOTOR_PUL_GPIO_CLK_ENABLE_B();
  MOTOR_EN_GPIO_CLK_ENABLE_B();

  /*初始化右电机的GPIO引脚*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_R;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_R, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_R;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_R, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_R; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_R, &GPIO_InitStruct);

/*初始化左电机的GPIO引脚*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_L;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_L, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_L;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_L, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_L; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_L, &GPIO_InitStruct);
	
	/*初始化上电机的GPIO引脚*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_U;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_U, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_U;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_U, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_U; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_U, &GPIO_InitStruct);
	
	/*初始化下电机的GPIO引脚*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_D;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_D, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_D;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_D, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_D; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_D, &GPIO_InitStruct);
	
	/*初始化前电机的GPIO引脚*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_F;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_F, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_F;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_F, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_F; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_F, &GPIO_InitStruct);
	
	/*初始化后电机的GPIO引脚*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_B;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_B, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_B;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_B, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_B; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_B, &GPIO_InitStruct);

  /*关掉使能*/
  MOTOR_EN_R(OFF);
	MOTOR_EN_L(OFF);
	MOTOR_EN_U(OFF);
	MOTOR_EN_D(OFF);
	MOTOR_EN_F(OFF);
	MOTOR_EN_B(OFF);
}



















