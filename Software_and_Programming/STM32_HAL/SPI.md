# Using SPI1

## Standard Includes:
```c
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
```

## Standard HAL Init()
```c
 HAL_Init();
```

## Chip Select
 Im using the Nucleo LED2 line as the chip select as this makes it easy to debug!

 ```c
 // LED clock initialization
 LED2_GPIO_CLK_ENABLE();

 GPIO_InitTypeDef GPIO_InitStruct;
 GPIO_InitStruct.Pin = LED2_PIN;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 GPIO_InitStruct.Pull = GPIO_PULLUP;
 GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
 HAL_GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);

 HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, 1);
```

## Setting up the GPIOs

We must set them to AF push pull with no Pullups
```c
 __GPIOB_CLK_ENABLE();

 GPIO_InitTypeDef GPIO_InitStructB;
	 GPIO_InitStructB.Pin = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
	 GPIO_InitStructB.Mode = GPIO_MODE_AF_PP;
	 GPIO_InitStructB.Pull = GPIO_NOPULL;
	 GPIO_InitStructB.Speed = GPIO_SPEED_FAST;
	 GPIO_InitStructB.Alternate = GPIO_AF5_SPI1;
 HAL_GPIO_Init(GPIOB, &GPIO_InitStructB);
```

## SPI Setup

```c
 __SPI1_CLK_ENABLE();

 SPI_HandleTypeDef SpiHandle;
   SpiHandle.Instance               = SPI1;
   SpiHandle.Init.Mode = SPI_MODE_MASTER;
   SpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
   SpiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
   SpiHandle.Init.CLKPhase          = SPI_PHASE_1EDGE;
   SpiHandle.Init.CLKPolarity       = SPI_POLARITY_HIGH;
   SpiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLED;
   SpiHandle.Init.CRCPolynomial     = 7;
   SpiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
   SpiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB;
   SpiHandle.Init.NSS               = SPI_NSS_SOFT;
   SpiHandle.Init.TIMode            = SPI_TIMODE_DISABLED;

 HAL_SPI_Init(&SpiHandle);
```
## Recieving, Blocking Mode

```c
//Clear CS Pin
HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, 0);

SPI_HALs_Status = HAL_SPI_Receive (&SpiHandle, recieve, 2, 1000);

for (i = 0; i < 600; i++);

//Reset CS Pin
HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, 1);
```
