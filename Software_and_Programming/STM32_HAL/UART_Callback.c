uint8_t Data[100];

uint8_t bugga[1000];
uint8_t bugga_pos=0;
void transmitdata();

int main(void)
{

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_CAN_Init();
  MX_USART4_UART_Init();
  MX_TIM1_Init();

  HAL_UART_Receive_IT(&huart4, Data, 1);

  while (1);
}

void transmitdata() {
    uint8_t bub[4] = " \n\r";
    //if bugga_pos == 0

	HAL_UART_Transmit_IT(&huart4, bugga, bugga_pos);
     bugga_pos = 0;
     HAL_TIM_Base_Stop_IT(&htim1);

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART4)
    {
         bugga[bugga_pos] = Data[0];
         bugga_pos++;
         HAL_UART_Receive_IT(&huart4, Data, 1);
         HAL_TIM_Base_Start_IT(&htim1);

    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1) //check if the interrupt comes from TIM3
        {
		   transmitdata();
        }
}
