// Init Function:

void TIM3_Init() {

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef TIM3_TimeBaseStructure;

	//Setting up for 5.051 ms Interval
	TIM3_TimeBaseStructure.TIM_Period = 1993;
	TIM3_TimeBaseStructure.TIM_Prescaler = 180;
	TIM3_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM3_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM3_TimeBaseStructure);

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM3, ENABLE);

	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_EnableIRQ(TIM3_IRQn);
}

//ISR

void TIM3_IRQHandler(void) {
 if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET){
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

    uint8_t message[] = ":)\n";
    uint8_t	length = 3;
	for(uint8_t i = 0; i < length; i++) {
		uint16_t data = message[i];
		//while(USART_GetFlagStatus (USART2,USART_FLAG_TXE) != SET);
		USART_SendData(USART2, data);
		while(USART_GetFlagStatus (USART2,USART_FLAG_TXE) != SET);
	}

 }
}
