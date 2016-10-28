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



	uint8_t mastring[8] = { "Cheeky\n\r" };

	uint16_t i;

    while (1)
    {
        HAL_UART_Transmit(&UartHandle, mastring, 8, 100);

        for (i = 0; i < 60000; i++);


    }
}
