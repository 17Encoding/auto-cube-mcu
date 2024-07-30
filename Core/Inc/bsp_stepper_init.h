#ifndef __BSP_STEP_MOTOR_INIT_H
#define __BSP_STEP_MOTOR_INIT_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

//右引脚定义
/*******************************************************/
//Motor 方向 
#define MOTOR_DIR_PIN_R                   GPIO_PIN_4   
#define MOTOR_DIR_GPIO_PORT_R             GPIOH                    
#define MOTOR_DIR_GPIO_CLK_ENABLE_R()     __HAL_RCC_GPIOH_CLK_ENABLE()

//Motor 使能 
#define MOTOR_EN_PIN_R                    GPIO_PIN_5
#define MOTOR_EN_GPIO_PORT_R              GPIOH                       
#define MOTOR_EN_GPIO_CLK_ENABLE_R()      __HAL_RCC_GPIOH_CLK_ENABLE()

//Motor 脉冲

#define MOTOR_PUL_PIN_R                   GPIO_PIN_5
#define MOTOR_PUL_GPIO_PORT_R             GPIOD
#define MOTOR_PUL_GPIO_CLK_ENABLE_R()     __HAL_RCC_GPIOD_CLK_ENABLE()

/************************************************************/

//左引脚定义
/*******************************************************/
//Motor 方向 
#define MOTOR_DIR_PIN_L                   GPIO_PIN_1   
#define MOTOR_DIR_GPIO_PORT_L             GPIOA                    
#define MOTOR_DIR_GPIO_CLK_ENABLE_L()     __HAL_RCC_GPIOA_CLK_ENABLE()

//Motor 使能 
#define MOTOR_EN_PIN_L                    GPIO_PIN_6
#define MOTOR_EN_GPIO_PORT_L              GPIOD                       
#define MOTOR_EN_GPIO_CLK_ENABLE_L()      __HAL_RCC_GPIOD_CLK_ENABLE()

//Motor 脉冲

#define MOTOR_PUL_PIN_L                   GPIO_PIN_2
#define MOTOR_PUL_GPIO_PORT_L             GPIOA
#define MOTOR_PUL_GPIO_CLK_ENABLE_L()     __HAL_RCC_GPIOA_CLK_ENABLE()

/************************************************************/

//上引脚定义
/*******************************************************/
//Motor 方向 
#define MOTOR_DIR_PIN_U                   GPIO_PIN_4   
#define MOTOR_DIR_GPIO_PORT_U             GPIOA                    
#define MOTOR_DIR_GPIO_CLK_ENABLE_U()     __HAL_RCC_GPIOA_CLK_ENABLE()

//Motor 使能 
#define MOTOR_EN_PIN_U                    GPIO_PIN_3
#define MOTOR_EN_GPIO_PORT_U              GPIOA                       
#define MOTOR_EN_GPIO_CLK_ENABLE_U()      __HAL_RCC_GPIOA_CLK_ENABLE()

//Motor 脉冲

#define MOTOR_PUL_PIN_U                   GPIO_PIN_3
#define MOTOR_PUL_GPIO_PORT_U             GPIOD
#define MOTOR_PUL_GPIO_CLK_ENABLE_U()     __HAL_RCC_GPIOD_CLK_ENABLE()

/************************************************************/

//下引脚定义
/*******************************************************/
//Motor 方向 
#define MOTOR_DIR_PIN_D                   GPIO_PIN_11   
#define MOTOR_DIR_GPIO_PORT_D             GPIOB                    
#define MOTOR_DIR_GPIO_CLK_ENABLE_D()     __HAL_RCC_GPIOB_CLK_ENABLE()

//Motor 使能 
#define MOTOR_EN_PIN_D                    GPIO_PIN_10
#define MOTOR_EN_GPIO_PORT_D              GPIOB                       
#define MOTOR_EN_GPIO_CLK_ENABLE_D()      __HAL_RCC_GPIOB_CLK_ENABLE()

//Motor 脉冲

#define MOTOR_PUL_PIN_D                   GPIO_PIN_2
#define MOTOR_PUL_GPIO_PORT_D             GPIOE
#define MOTOR_PUL_GPIO_CLK_ENABLE_D()     __HAL_RCC_GPIOE_CLK_ENABLE()

/************************************************************/

//前引脚定义
/*******************************************************/
//Motor 方向 
#define MOTOR_DIR_PIN_F                   GPIO_PIN_5   
#define MOTOR_DIR_GPIO_PORT_F             GPIOE                    
#define MOTOR_DIR_GPIO_CLK_ENABLE_F()     __HAL_RCC_GPIOE_CLK_ENABLE()

//Motor 使能 
#define MOTOR_EN_PIN_F                    GPIO_PIN_3
#define MOTOR_EN_GPIO_PORT_F              GPIOE                       
#define MOTOR_EN_GPIO_CLK_ENABLE_F()      __HAL_RCC_GPIOE_CLK_ENABLE()

//Motor 脉冲

#define MOTOR_PUL_PIN_F                   GPIO_PIN_4
#define MOTOR_PUL_GPIO_PORT_F             GPIOE
#define MOTOR_PUL_GPIO_CLK_ENABLE_F()     __HAL_RCC_GPIOE_CLK_ENABLE()

/************************************************************/

//后引脚定义
/*******************************************************/
//Motor 方向 
#define MOTOR_DIR_PIN_B                   GPIO_PIN_8   
#define MOTOR_DIR_GPIO_PORT_B             GPIOI                    
#define MOTOR_DIR_GPIO_CLK_ENABLE_B()     __HAL_RCC_GPIOI_CLK_ENABLE()

//Motor 使能 
#define MOTOR_EN_PIN_B                    GPIO_PIN_6
#define MOTOR_EN_GPIO_PORT_B              GPIOE                       
#define MOTOR_EN_GPIO_CLK_ENABLE_B()      __HAL_RCC_GPIOE_CLK_ENABLE()

//Motor 脉冲

#define MOTOR_PUL_PIN_B                   GPIO_PIN_5
#define MOTOR_PUL_GPIO_PORT_B             GPIOB
#define MOTOR_PUL_GPIO_CLK_ENABLE_B()     __HAL_RCC_GPIOB_CLK_ENABLE()

/************************************************************/
#define HIGH GPIO_PIN_SET       //高电平
#define LOW  GPIO_PIN_RESET     //低电平

#define ON  LOW                 //开
#define OFF HIGH                //关

#define CW  HIGH                //顺时针
#define CCW LOW                 //逆时针


//右控制使能引脚
/* 带参宏，可以像内联函数一样使用 */
#define MOTOR_EN_R(x)         HAL_GPIO_WritePin(MOTOR_EN_GPIO_PORT_R,MOTOR_EN_PIN_R,x)
#define MOTOR_PLU_R(x)        HAL_GPIO_WritePin(MOTOR_PUL_GPIO_PORT_R,MOTOR_PUL_PIN_R,x)
#define MOTOR_DIR_R(x)        HAL_GPIO_WritePin(MOTOR_DIR_GPIO_PORT_R,MOTOR_DIR_PIN_R,x)

//左控制使能引脚
/* 带参宏，可以像内联函数一样使用 */
#define MOTOR_EN_L(x)         HAL_GPIO_WritePin(MOTOR_EN_GPIO_PORT_L,MOTOR_EN_PIN_L,x)
#define MOTOR_PLU_L(x)        HAL_GPIO_WritePin(MOTOR_PUL_GPIO_PORT_L,MOTOR_PUL_PIN_L,x)
#define MOTOR_DIR_L(x)        HAL_GPIO_WritePin(MOTOR_DIR_GPIO_PORT_L,MOTOR_DIR_PIN_L,x)

//前控制使能引脚
/* 带参宏，可以像内联函数一样使用 */
#define MOTOR_EN_F(x)         HAL_GPIO_WritePin(MOTOR_EN_GPIO_PORT_F,MOTOR_EN_PIN_F,x)
#define MOTOR_PLU_F(x)        HAL_GPIO_WritePin(MOTOR_PUL_GPIO_PORT_F,MOTOR_PUL_PIN_F,x)
#define MOTOR_DIR_F(x)        HAL_GPIO_WritePin(MOTOR_DIR_GPIO_PORT_F,MOTOR_DIR_PIN_F,x)

//后控制使能引脚
/* 带参宏，可以像内联函数一样使用 */
#define MOTOR_EN_B(x)         HAL_GPIO_WritePin(MOTOR_EN_GPIO_PORT_B,MOTOR_EN_PIN_B,x)
#define MOTOR_PLU_B(x)        HAL_GPIO_WritePin(MOTOR_PUL_GPIO_PORT_B,MOTOR_PUL_PIN_B,x)
#define MOTOR_DIR_B(x)        HAL_GPIO_WritePin(MOTOR_DIR_GPIO_PORT_B,MOTOR_DIR_PIN_B,x)

//上控制使能引脚
/* 带参宏，可以像内联函数一样使用 */
#define MOTOR_EN_U(x)         HAL_GPIO_WritePin(MOTOR_EN_GPIO_PORT_U,MOTOR_EN_PIN_U,x)
#define MOTOR_PLU_U(x)        HAL_GPIO_WritePin(MOTOR_PUL_GPIO_PORT_U,MOTOR_PUL_PIN_U,x)
#define MOTOR_DIR_U(x)        HAL_GPIO_WritePin(MOTOR_DIR_GPIO_PORT_U,MOTOR_DIR_PIN_U,x)

//下控制使能引脚
/* 带参宏，可以像内联函数一样使用 */
#define MOTOR_EN_D(x)         HAL_GPIO_WritePin(MOTOR_EN_GPIO_PORT_D,MOTOR_EN_PIN_D,x)
#define MOTOR_PLU_D(x)        HAL_GPIO_WritePin(MOTOR_PUL_GPIO_PORT_D,MOTOR_PUL_PIN_D,x)
#define MOTOR_DIR_D(x)        HAL_GPIO_WritePin(MOTOR_DIR_GPIO_PORT_D,MOTOR_DIR_PIN_D,x)

extern void stepper_Init(void);
extern void stepper_turn_r(int tim,float angle,float subdivide,uint8_t dir);
extern void stepper_turn_l(int tim,float angle,float subdivide,uint8_t dir);
extern void stepper_turn_u(int tim,float angle,float subdivide,uint8_t dir);
extern void stepper_turn_d(int tim,float angle,float subdivide,uint8_t dir);
extern void stepper_turn_f(int tim,float angle,float subdivide,uint8_t dir);
extern void stepper_turn_b(int tim,float angle,float subdivide,uint8_t dir);
#endif /* __STEP_MOTOR_INIT_H */


