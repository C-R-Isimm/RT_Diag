/*
 * ComM.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Hamdi wel prezzz
 */

#include"MainAPP/ComM/ComM.h"

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

static void ComMConfigUART(){

UART_HandleTypeDef huart4;

 HAL_Init();
 //static void MX_UART4_Init(void)
 huart4.Instance = UART4;
 huart4.Init.BaudRate = 9600;
 huart4.Init.WordLength = UART_WORDLENGTH_8B;
 huart4.Init.StopBits = UART_STOPBITS_1;
 huart4.Init.Parity = UART_PARITY_NONE;
 huart4.Init.Mode = UART_MODE_TX_RX;
 huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 huart4.Init.OverSampling = UART_OVERSAMPLING_16;
 if (HAL_UART_Init(&huart4) != HAL_OK)
 {
  Error_Handler();
 }

//static void MX_GPIO_Init(void)
 GPIO_InitTypeDef GPIO_InitStruct = {0};
 _HAL_RCC_GPIOA_CLK_ENABLE();
 __HAL_RCC_GPIOC_CLK_ENABLE();

}

static void ComMConfigADC(){

 ADC_HandleTypeDef hadc1;

//static void MX_ADC1_Init(void);
 ADC_ChannelConfTypeDef sConfig = {0};

 /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)  */
 hadc1.Instance = ADC1;
 hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
 hadc1.Init.Resolution = ADC_RESOLUTION_12B;
 hadc1.Init.ScanConvMode = DISABLE;
 hadc1.Init.ContinuousConvMode = DISABLE;
 hadc1.Init.DiscontinuousConvMode = DISABLE;
 hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
 hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
 hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
 hadc1.Init.NbrOfConversion = 1;
 hadc1.Init.DMAContinuousRequests = DISABLE;
 hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
 if (HAL_ADC_Init(&hadc1) != HAL_OK)
 {
  Error_Handler();
 }
 /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
 */
 sConfig.Channel = ADC_CHANNEL_0;
 sConfig.Rank = 1;
 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
 if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
 {
  Error_Handler();
 }
}

/*GPIOx : we will use at the begin GPIOC
 * pin : number of the pin can take from 0--16
 * mode can take "output" or "input"*/
static void ComMConfigGPIO(GPIO_TypeDef* GPIOx, uint16_t pin, uint8_t mode){
 assert_param(GPIOx==GPIOC);
 assert_param(IS_GPIO_PIN(pin));
 assert_param(IS_GPIO_MODE(mode));
 GPIO_InitTypeDef GPIO_InitStruct = {0};
 /* GPIO Ports Clock Enable */

 __HAL_RCC_GPIOC_CLK_ENABLE();

 if (mode == GPIO_MODE_OUTPUT_PP){
 /*Configure GPIO pin Output Level */
 HAL_GPIO_WritePin(GPIOx, pin, GPIO_PIN_RESET);
 /*Configure GPIO pin : PC8 */
 GPIO_InitStruct.Pin = pin;
 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 }

 else if (mode == GPIO_MODE_INPUT){
 /*Configure GPIO pin : PC9 */
 GPIO_InitStruct.Pin = pin;
 GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
 GPIO_InitStruct.Pull = GPIO_NOPULL;
 }

 HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);

}

/**GPIOx : we will use at the begin GPIOC
 * pin : number of the pin can take from 0--16*/
static uint8_t ReadGPIO(GPIO_TypeDef* GPIOx, uint16_t pin)
{
 return HAL_GPIO_ReadPin(GPIOx,pin);
}

/**GPIOx : we will use at the begin GPIOC
 * pin : number of the pin can take from 0--16
 * pinvalue take 0 or 1 */
static void WriteGPIO(GPIO_TypeDef* GPIOx, uint16_t pin,int PinValue)
{
 HAL_GPIO_WritePin(GPIOx, pin, PinValue);
}

HAL_StatusTypeDef ComMConfigDevice(Devicetype Device)
{
 ADC_HandleTypeDef hadc1;
 ADC_HandleTypeDef huart4;

 if (Device == lm35)
 {
 ComMConfigADC();
 }

 else if (Device == tcrt)
 {
 ComMConfigGPIO(GPIOC,5,GPIO_MODE_INPUT);
 }

 else if (Device == Ultrasonic)
 {
// ComMConfigGPIO();
 }

 else if (Device == arduino)
 {
 ComMConfigUART();
 }

 else if (Device == qtr_8rc)
 {
//		ComMConfigGPIO();
 }

 else if (Device == dht11)
 {
 ComMConfigADC();
 }

 if ((HAL_UART_Init(&huart4) != HAL_OK)	&& (HAL_ADC_Init(&hadc1) != HAL_OK))
 {
 return HAL_ERROR ;
 }
 else
 {
		return HAL_OK;
 }
 }
uint32_t ComMReadSensorValue(Devicetype Device){

 uint32_t return_value=0;

 if (Device == lm35){
 ADC_HandleTypeDef hadc1;
 HAL_ADC_Start(&hadc1); // begin of conversion
 HAL_ADC_PollForConversion(&hadc1, 50); //wait the end of conversion
 return_value= HAL_ADC_GetValue(&hadc1);
 }

 else if (Device == tcrt)
 {
 return_value= ReadGPIO(GPIOC,5);
 }

 else if (Device == Ultrasonic)
 {

 }
 /*else if (Device == arduino){
 UART_HandleTypeDef huart4;
 HAL_UART_Transmit(&huart4, "Hello_CRI_UART!", 8,50); // Transmission message to Arduino
 HAL_UART_Receive(&huart4, x , 1 , 50);
 arduino will compare the message and the const declared in the arduino which have the same message value
 if  the same arduino will send 1 else will send 0 and the data will saved in x which will returned from function
 }*/

 else if (Device == qtr_8rc)
 {

 }

 else if (Device == dht11)
 {

 }

 else {}

	return return_value;
}

