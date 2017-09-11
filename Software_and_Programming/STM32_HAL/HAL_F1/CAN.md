# STM32F1 CAN

Using the STM32CubeMX to generate a 125 kHz baud:

```c
void MX_CAN1_Init(void)
{

  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 16;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SJW = CAN_SJW_1TQ;
  hcan1.Init.BS1 = CAN_BS1_9TQ;
  hcan1.Init.BS2 = CAN_BS2_8TQ;
  hcan1.Init.TTCM = DISABLE;
  hcan1.Init.ABOM = DISABLE;
  hcan1.Init.AWUM = DISABLE;
  hcan1.Init.NART = DISABLE;
  hcan1.Init.RFLM = DISABLE;
  hcan1.Init.TXFP = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

```
## Transmitting
And then on in the main function to transmit:

Noting the first two lines; they are defining and assigning the message structure.

```c
CanTxMsgTypeDef TxMessage;
hcan1.pTxMsg = &TxMessage;
hcan1.pTxMsg->StdId = id;
hcan1.pTxMsg->RTR = CAN_RTR_DATA;
hcan1.pTxMsg->IDE = CAN_ID_STD;
hcan1.pTxMsg->DLC=2;
hcan1.pTxMsg->Data[0] = a;
hcan1.pTxMsg->Data[1] = b;

HAL_CAN_Transmit(&hcan1, 10);
```

The example was using static variables as the CanTxMsgTypeDef however I dont think this is a wise idea ... dunno, its an option!

## Recieving

Likewise we must define a rieceve struct, and then use it!

```c
CanRxMsgTypeDef RxMessage;
hcan1.pRxMsg = &RxMessage;

CAN_FilterConfTypeDef  sFilterConfig;

sFilterConfig.FilterNumber = 0;
sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
sFilterConfig.FilterIdHigh = 0x0000;
sFilterConfig.FilterIdLow = 0x0000;
sFilterConfig.FilterMaskIdHigh = 0x0000;
sFilterConfig.FilterMaskIdLow = 0x0000;
sFilterConfig.FilterFIFOAssignment = 0;
sFilterConfig.FilterActivation = ENABLE;
sFilterConfig.BankNumber = 14;

HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig);
```
