extern	huart2;
extern  hi2c2;

void SysTick_Handler(void){
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart2);
}

void I2C2_IRQHandler(void)
{
	HAL_I2C_IRQHandler(&hi2c2);
}
