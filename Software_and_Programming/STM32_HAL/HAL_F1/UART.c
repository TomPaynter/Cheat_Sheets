////////// Transmit:
{
  uint8_t buf[100], l = sprintf(buf, " ID: %d DLC: %d Data: %d %d %d %d %d %d %d %d \n\r", RxMessage2.StdId, RxMessage2.DLC, RxMessage2.Data[0], RxMessage2.Data[1], RxMessage2.Data[2], RxMessage2.Data[3], RxMessage2.Data[4], RxMessage2.Data[5], RxMessage2.Data[6], RxMessage2.Data[7]);

  HAL_UART_Transmit(&huart1, buf, l, 1000);
}

////////// Recieve:
