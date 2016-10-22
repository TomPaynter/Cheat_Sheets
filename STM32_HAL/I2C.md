```c
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"


int main()
{


	__GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		//GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


	__GPIOB_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStructB;
		GPIO_InitStructB.Pin = GPIO_PIN_8 | GPIO_PIN_9;
		GPIO_InitStructB.Mode = GPIO_MODE_AF_OD;
		GPIO_InitStructB.Pull = GPIO_NOPULL;
		GPIO_InitStructB.Speed = GPIO_SPEED_HIGH;
		GPIO_InitStructB.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructB);
/*
	 GPIO_InitTypeDef GPIO_InitStructB2;
	 GPIO_InitStructB2.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	 GPIO_InitStructB2.Mode = GPIO_MODE_OUTPUT_OD;
	// GPIO_InitStructB2.Pull = GPIO_PULLUP;
	 GPIO_InitStructB2.Speed = GPIO_SPEED_FAST;
	 HAL_GPIO_Init(GPIOB, &GPIO_InitStructB2);
*/
	__USART2_CLK_ENABLE();

	UART_HandleTypeDef UartHandle;
		UartHandle.Instance = USART2;
		UartHandle.Init.BaudRate = 115200;
		UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
		UartHandle.Init.StopBits = UART_STOPBITS_1;
		UartHandle.Init.Parity = UART_PARITY_NONE;
		UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		UartHandle.Init.Mode = UART_MODE_TX_RX;

	HAL_UART_Init(&UartHandle);


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

uint8_t str[8] = { "Cheeky\n\r" };

HAL_StatusTypeDef bob;
uint8_t I2C_Address = 48;
uint8_t I2C_Data = 8;
uint8_t I2C_Read = 0;
uint16_t i;

    while (1)
    {
        HAL_UART_Transmit(&UartHandle, str, 8, 100);

        //__HAL_I2C_RESET_HANDLE_STATE(&hi2c1);
        bob = HAL_I2C_GetState(&hi2c1);

        bob = HAL_I2C_Master_Transmit(&hi2c1,  I2C_Address, &I2C_Data, 1, 10000);

        //__HAL_I2C_RESET_HANDLE_STATE(&hi2c1);
        bob = HAL_I2C_GetState(&hi2c1);

        for (i = 0; i < 60; i++);

        bob = HAL_I2C_Master_Receive(&hi2c1,  I2C_Address + 1, &I2C_Read, 1, 10000);

        for (i = 0; i < 60; i++);


        bob = HAL_I2C_GetState(&hi2c1);

    }
}
```
