#include <stm32f4xx.h>

#include <stdio.h>

#include "init.h"
#include "buffer.h"
#include "api_uart.h"


API_UART_t API_UART_i;
API_UART_t API_UART_o;

void API_UART_i_callback_Rx (uint32_t data);
void API_UART_o_callback_Tx (uint32_t data);



int main (void)
{
	initAll ();

	buffer_Init ();

	API_UART_Init (&API_UART_i, API_UART1, 84000000,   9600, API_UART_PARITY_EVEN, API_UART_STOP_1);
	API_UART_Init (&API_UART_o, API_UART2, 42000000, 115200, API_UART_PARITY_EVEN, API_UART_STOP_1);

	API_UART_set_callback_Rx (&API_UART_i, API_UART_i_callback_Rx);
	API_UART_set_callback_Tx (&API_UART_o, API_UART_o_callback_Tx);

	NVIC_SetPriority ( 
		USART1_IRQn, 
		NVIC_EncodePriority ( 
			NVIC_GetPriorityGrouping (), 
			0, 
			2));
	NVIC_EnableIRQ (USART1_IRQn);

	NVIC_SetPriority ( 
		USART2_IRQn, 
		NVIC_EncodePriority ( 
			NVIC_GetPriorityGrouping (), 
			0, 
			1));
	NVIC_EnableIRQ (USART2_IRQn);


	while (1)
	{
	}
}


void API_UART_i_callback_Rx (uint32_t data)
{
	int i = -1;


	i = buffer_push (data);

	if (i >= 0)
	{
		API_UART_transmit (&API_UART_o, buffer + i, 128);
	}
}


void API_UART_o_callback_Tx (uint32_t data)
{
}



//
// Interrupt's
//
void USART1_IRQHandler (void)
{
	API_UART_IRQ_Handler (&API_UART_i);
}

void USART2_IRQHandler (void)
{
	API_UART_IRQ_Handler (&API_UART_o);
}

