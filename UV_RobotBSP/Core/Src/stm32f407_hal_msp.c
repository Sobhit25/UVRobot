
#include "stm32f4xx.h"

void HAL_MspInit(void)
{
  /* NOTE : This function should not be modified, when the call back is needed,
            the HAL_MspInit could be implemented in the user file
   */

	// Here will do the Low level processor specific Inits

	//1. Set up the priority grouping of the Arm Cortex MX Processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required the system exceptions
	SCB->SHCSR |= 0x7 << 16; // USAGE FAULT, MEM FAULT, BUD FAULT

	//3. Configure the priority for the system exception
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0,0);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	//Here we are going to do low level initializations of UART2 Peripheral
	GPIO_InitTypeDef gpio_uart;

	//1. Enable the clock for the UART2 peripheral
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

	//2. Do the pin muxing configurations
	gpio_uart.Mode = GPIO_MODE_AF_PP;
	gpio_uart.Pull = GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_uart.Alternate = GPIO_AF7_USART2;

	gpio_uart.Pin = GPIO_PIN_5; //UART TX
	HAL_GPIO_Init(GPIOD, &gpio_uart);

	gpio_uart.Pin = GPIO_PIN_6; //UART RX
	HAL_GPIO_Init(GPIOD, &gpio_uart);

	//3. Enable the IRQ and set up the priority (NVIC Settings)
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);

}

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
	//Here we are going to do low level initializations of UART2 Peripheral
	GPIO_InitTypeDef gpio_i2c;

	//1. Enable the clock for the UART2 peripheral
	__HAL_RCC_I2C2_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	//2. Do the pin muxing configurations
	gpio_i2c.Mode = GPIO_MODE_AF_OD;
	gpio_i2c.Pull = GPIO_PULLUP;
	gpio_i2c.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_i2c.Alternate = GPIO_AF4_I2C2;

	gpio_i2c.Pin = GPIO_PIN_10; //I2C SCL
	HAL_GPIO_Init(GPIOB, &gpio_i2c);

	gpio_i2c.Pin = GPIO_PIN_11; //I2C SDA
	HAL_GPIO_Init(GPIOB, &gpio_i2c);

	//3. Enable the IRQ and set up the priority (NVIC Settings)
	HAL_NVIC_EnableIRQ(I2C2_EV_IRQn);
	HAL_NVIC_SetPriority(I2C2_EV_IRQn, 15, 0);

}
