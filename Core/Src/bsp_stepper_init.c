#include "bsp_stepper_init.h"
#include "core_delay.h"   
#include "stm32f4xx.h"

//�ҵ��ת������
void stepper_turn_r(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*����ϸ������ò���Ǳ��ֳɶ��ٸ�����*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //˳ʱ��
  {
    MOTOR_DIR_R(CW);
  }
  else if(dir==CCW)//��ʱ��
  {
    MOTOR_DIR_R(CCW);
  }
  /*��ʹ��*/
  MOTOR_EN_R(ON);
  /*ģ�ⷽ��*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_R(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_R(LOW);
    delay_us(tim/2);
  }
  /*��ʹ��*/
  MOTOR_EN_R(OFF);
}

//����ת������
void stepper_turn_l(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*����ϸ������ò���Ǳ��ֳɶ��ٸ�����*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //˳ʱ��
  {
    MOTOR_DIR_L(CW);
  }
  else if(dir==CCW)//��ʱ��
  {
    MOTOR_DIR_L(CCW);
  }
  /*��ʹ��*/
  MOTOR_EN_L(ON);
  /*ģ�ⷽ��*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_L(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_L(LOW);
    delay_us(tim/2);
  }
  /*��ʹ��*/
  MOTOR_EN_L(OFF);
}

//�ϵ��ת������
void stepper_turn_u(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*����ϸ������ò���Ǳ��ֳɶ��ٸ�����*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //˳ʱ��
  {
    MOTOR_DIR_U(CW);
  }
  else if(dir==CCW)//��ʱ��
  {
    MOTOR_DIR_U(CCW);
  }
  /*��ʹ��*/
  MOTOR_EN_U(ON);
  /*ģ�ⷽ��*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_U(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_U(LOW);
    delay_us(tim/2);
  }
  /*��ʹ��*/
  MOTOR_EN_U(OFF);
}

//�µ��ת������
void stepper_turn_d(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*����ϸ������ò���Ǳ��ֳɶ��ٸ�����*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //˳ʱ��
  {
    MOTOR_DIR_D(CW);
  }
  else if(dir==CCW)//��ʱ��
  {
    MOTOR_DIR_D(CCW);
  }
  /*��ʹ��*/
  MOTOR_EN_D(ON);
  /*ģ�ⷽ��*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_D(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_D(LOW);
    delay_us(tim/2);
  }
  /*��ʹ��*/
  MOTOR_EN_D(OFF);
}

//ǰ���ת������
void stepper_turn_f(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*����ϸ������ò���Ǳ��ֳɶ��ٸ�����*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //˳ʱ��
  {
    MOTOR_DIR_F(CW);
  }
  else if(dir==CCW)//��ʱ��
  {
    MOTOR_DIR_F(CCW);
  }
  /*��ʹ��*/
  MOTOR_EN_F(ON);
  /*ģ�ⷽ��*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_F(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_F(LOW);
    delay_us(tim/2);
  }
  /*��ʹ��*/
  MOTOR_EN_F(OFF);
}

//����ת������
void stepper_turn_b(int tim,float angle,float subdivide,uint8_t dir)  
{
  int n,i;
  /*����ϸ������ò���Ǳ��ֳɶ��ٸ�����*/
  n=(int)(angle/(1.8/subdivide));
  if(dir==CW) //˳ʱ��
  {
    MOTOR_DIR_B(CW);
  }
  else if(dir==CCW)//��ʱ��
  {
    MOTOR_DIR_B(CCW);
  }
  /*��ʹ��*/
  MOTOR_EN_B(ON);
  /*ģ�ⷽ��*/
  for(i=0;i<n;i++)
  {   
    MOTOR_PLU_B(HIGH);
    delay_us(tim/2);
    MOTOR_PLU_B(LOW);
    delay_us(tim/2);
  }
  /*��ʹ��*/
  MOTOR_EN_B(OFF);
}


void stepper_Init()
{
  /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
  GPIO_InitTypeDef  GPIO_InitStruct;

  /*�����ҵ����ص�GPIO����ʱ��*/
  MOTOR_DIR_GPIO_CLK_ENABLE_R();
  MOTOR_PUL_GPIO_CLK_ENABLE_R();
  MOTOR_EN_GPIO_CLK_ENABLE_R();
	
	/*����������ص�GPIO����ʱ��*/
  MOTOR_DIR_GPIO_CLK_ENABLE_L();
  MOTOR_PUL_GPIO_CLK_ENABLE_L();
  MOTOR_EN_GPIO_CLK_ENABLE_L();
	
	/*�����ϵ����ص�GPIO����ʱ��*/
  MOTOR_DIR_GPIO_CLK_ENABLE_U();
  MOTOR_PUL_GPIO_CLK_ENABLE_U();
  MOTOR_EN_GPIO_CLK_ENABLE_U();
	
	/*�����µ����ص�GPIO����ʱ��*/
  MOTOR_DIR_GPIO_CLK_ENABLE_D();
  MOTOR_PUL_GPIO_CLK_ENABLE_D();
  MOTOR_EN_GPIO_CLK_ENABLE_D();
	
	/*����ǰ�����ص�GPIO����ʱ��*/
  MOTOR_DIR_GPIO_CLK_ENABLE_F();
  MOTOR_PUL_GPIO_CLK_ENABLE_F();
  MOTOR_EN_GPIO_CLK_ENABLE_F();
	
	/*����������ص�GPIO����ʱ��*/
  MOTOR_DIR_GPIO_CLK_ENABLE_B();
  MOTOR_PUL_GPIO_CLK_ENABLE_B();
  MOTOR_EN_GPIO_CLK_ENABLE_B();

  /*��ʼ���ҵ����GPIO����*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_R;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_R, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_R;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_R, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_R; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_R, &GPIO_InitStruct);

/*��ʼ��������GPIO����*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_L;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_L, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_L;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_L, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_L; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_L, &GPIO_InitStruct);
	
	/*��ʼ���ϵ����GPIO����*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_U;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_U, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_U;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_U, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_U; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_U, &GPIO_InitStruct);
	
	/*��ʼ���µ����GPIO����*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_D;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_D, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_D;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_D, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_D; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_D, &GPIO_InitStruct);
	
	/*��ʼ��ǰ�����GPIO����*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_F;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_F, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_F;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_F, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_F; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_F, &GPIO_InitStruct);
	
	/*��ʼ��������GPIO����*/                                 
  GPIO_InitStruct.Pin = MOTOR_DIR_PIN_B;  
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
  GPIO_InitStruct.Pull =GPIO_PULLUP;  
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR_DIR_GPIO_PORT_B, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_PUL_PIN_B;  
  HAL_GPIO_Init(MOTOR_PUL_GPIO_PORT_B, &GPIO_InitStruct); 
  GPIO_InitStruct.Pin = MOTOR_EN_PIN_B; 
  HAL_GPIO_Init(MOTOR_EN_GPIO_PORT_B, &GPIO_InitStruct);

  /*�ص�ʹ��*/
  MOTOR_EN_R(OFF);
	MOTOR_EN_L(OFF);
	MOTOR_EN_U(OFF);
	MOTOR_EN_D(OFF);
	MOTOR_EN_F(OFF);
	MOTOR_EN_B(OFF);
}



















