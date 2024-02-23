#include "MainAPP/UIM/UIM.h"
#include "stm32f4xx_hal.h"

//UART_HandleTypeDef huart2;

void UIM_Init(void) {
    // Configuration of UART parameters (baud rate, etc.)
    /*huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE; //hardware flow control
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;*/

    // Initialization of UART with configured parameters
    /*if (HAL_UART_Init(&huart2) != HAL_OK) {
        Error_Handler();
    }*/
}

void UIM_Transmit(uint8_t *data, uint16_t length) {
    // Transmission of data via UART
    //HAL_UART_Transmit(&huart2, data, length, HAL_MAX_DELAY);
}

void UIM_Receive(uint8_t *buffer, uint16_t length) {
    // Reception of data via UART
    //HAL_UART_Receive(&huart2, buffer, length, HAL_MAX_DELAY);
}
