////////// UART DEBUGS TRANSMITTED

{
    uint8_t buf[100], l = sprintf(buf, "Transmitting CAN:  ID: %d DLC: %d Data: %d %d %d %d %d %d %d %d \n\r", TxMessage.StdId, TxMessage.DLC, TxMessage.Data[0], TxMessage.Data[1], TxMessage.Data[2], TxMessage.Data[3], TxMessage.Data[4], TxMessage.Data[5], TxMessage.Data[6], TxMessage.Data[7]);

    HAL_UART_Transmit(&huart4, buf, l, 1000);
}

////////// UART DEBUGS RECEIVED


{
    uint8_t buf[100], l = sprintf(buf, "\t Receiving CAN:  ID: %d DLC: %d Data: %d %d %d %d %d %d %d %d \n\r", RxMessage.StdId, RxMessage.DLC, RxMessage.Data[0], RxMessage.Data[1], RxMessage.Data[2], RxMessage.Data[3], RxMessage.Data[4], RxMessage.Data[5], RxMessage.Data[6], RxMessage.Data[7]);

    HAL_UART_Transmit(&huart4, buf, l, 1000);
}

////////// Transmitting

CanTxMsgTypeDef TxMessage;
hcan.pTxMsg = &TxMessage;
hcan.pTxMsg->StdId = 2;
hcan.pTxMsg->RTR = CAN_RTR_DATA;
hcan.pTxMsg->IDE = CAN_ID_STD;
hcan.pTxMsg->DLC=2;
hcan.pTxMsg->Data[0] = 16;
hcan.pTxMsg->Data[1] = 29;

HAL_CAN_Transmit(&hcan, 10);

////////// Dual Bus Filters

void CAN_FilterSetup(void) {
  hspi1.Init.Mode = SPI_MODE_SLAVE;

  CAN_FilterConfTypeDef  sFilterConfig1;

  sFilterConfig1.FilterNumber = 0;
  sFilterConfig1.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig1.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig1.FilterIdHigh = 0x0000;
  sFilterConfig1.FilterIdLow = 0x0000;
  sFilterConfig1.FilterMaskIdHigh = 0x0000;
  sFilterConfig1.FilterMaskIdLow = 0x0000;
  sFilterConfig1.FilterFIFOAssignment = CAN_FIFO0;
  sFilterConfig1.FilterActivation = ENABLE;
  HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig1);

  hcan1.pRxMsg = &RxMessage1;
  HAL_CAN_Receive_IT(&hcan1, CAN_FIFO0);

  sFilterConfig1.FilterNumber = 1;
  HAL_CAN_ConfigFilter(&hcan2, &sFilterConfig1);

  hcan2.pRxMsg = &RxMessage2;
  HAL_CAN_Receive_IT(&hcan2, CAN_FIFO0);
}

////////// Single Bus Filters - MASK

void CAN_FilterSetup(void) {
  CAN_FilterConfTypeDef  sFilterConfig;

  sFilterConfig.FilterNumber = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x0000;
  sFilterConfig.FilterIdLow = 0x0000;
  sFilterConfig.FilterMaskIdHigh = 0x0000;
  sFilterConfig.FilterMaskIdLow = 0x0000;
  sFilterConfig.FilterFIFOAssignment = CAN_FIFO0;
  sFilterConfig.FilterActivation = ENABLE;
  HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);

  hcan.pRxMsg = &RxMessage;
  HAL_CAN_Receive_IT(&hcan, CAN_FIFO0);
}

////////// Single Bus Filters - ID LIST
void CAN_FilterSetup(void) {
  CAN_FilterConfTypeDef  sFilterConfig;

  sFilterConfig.FilterNumber = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
  sFilterConfig.FilterIdHigh = PASSTHRU_ID;
  sFilterConfig.FilterIdLow = PASSTHRU_ID << 5; // << for reasons!

  sFilterConfig.FilterFIFOAssignment = CAN_FIFO0;
  sFilterConfig.FilterActivation = ENABLE;
  HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);

  hcan.pRxMsg = &RxMessage;
  HAL_CAN_Receive_IT(&hcan, CAN_FIFO0);
}


////////// Single Bus Filters - ID LIST -- MULTIPLE IDs

void CAN_FilterSetup(void) {
  CAN_FilterConfTypeDef  sFilterConfig;

  sFilterConfig.FilterNumber = 0;
  sFilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
  sFilterConfig.FilterIdHigh = PASSTHRU_ID_RX;
  sFilterConfig.FilterIdLow = PASSTHRU_ID_RX << 5; // << for reasons!

  sFilterConfig.FilterFIFOAssignment = CAN_FIFO0;
  sFilterConfig.FilterActivation = ENABLE;
  HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);



  sFilterConfig.FilterNumber = 1;
  sFilterConfig.FilterIdHigh = PASSTHRU_ID_TX;
  sFilterConfig.FilterIdLow = PASSTHRU_ID_TX << 5; // << for reasons!

  HAL_CAN_ConfigFilter(&hcan, &sFilterConfig);

  hcan.pRxMsg = &RxMessage;
  HAL_CAN_Receive_IT(&hcan, CAN_FIFO0);

}
