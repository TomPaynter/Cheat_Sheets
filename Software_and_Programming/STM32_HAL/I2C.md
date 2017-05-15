# I2C with the STM32 HAL Library

DONT USE __HAL_I2C_RESET_HANDLE_STATE(&hi2c1);__ It will stop things from working and make you sad!

# Setting Up I2C1 on PB8 and 9

## Standard Includes

```c
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
```
## Setup GPIO pins and I2C

```c

//GPIO Setup
__GPIOB_CLK_ENABLE();

GPIO_InitTypeDef GPIO_InitStructB;
	GPIO_InitStructB.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	GPIO_InitStructB.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStructB.Pull = GPIO_PULLUP;
	GPIO_InitStructB.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructB.Alternate = GPIO_AF4_I2C1;
	
HAL_GPIO_Init(GPIOB, &GPIO_InitStructB);


//I2C Setup
__I2C1_CLK_ENABLE();

I2C_HandleTypeDef hi2c1;
	hi2c1.Instance = I2C1;
	hi2c1.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.ClockSpeed      = 100000;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
	hi2c1.Init.DutyCycle       = I2C_DUTYCYCLE_2;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
	hi2c1.Init.NoStretchMode   = I2C_NOSTRETCH_ENABLE;
	hi2c1.Init.OwnAddress1     = 0xFE;
	hi2c1.Init.OwnAddress2     = 0xFE;

HAL_I2C_Init(&hi2c1);
```

## Setting Addresses

Unlike most other I2C libraries, on 8-bit mode you __MUST__ bitshift the 7 bit address left by one in order to have it as a full 8-bit address. Then the read write flag must also be set as required.

To convert from the generic 7-bit address a write address is simply multiply by 2. A read address is then multiply by 2 and add 1.
```c
uint8_t I2C_GenericAddress = 24;
uint8_t I2C_Data = 5;
uint8_t I2C_Read[2] = 0;

```

## Read and Write

I am simply using the stanard blocking mode. It is simple and works for now, when its no longer suffucient Ill look into something else!

```c
HAL_StatusTypeDef HI2Cs_Status;

HI2Cs_Status = HAL_I2C_Master_Transmit(&hi2c1,  2 * I2C_GenericAddress, &I2C_Data, 1, 10000);

for (i = 0; i < 60; i++); //Short Delay

HI2Cs_Status = HAL_I2C_Master_Receive(&hi2c1,  2 * I2C_GenericAddress + 1, I2C_Read, 2, 10000);

for (i = 0; i < 60; i++); //Short Delay

```
