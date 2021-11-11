#include <stm32f4xx.h>

#include <stdio.h>

#include "init.h"
#include "buffer.h"
#include "uart.h"


UART_t UART_1;
UART_t UART_2;

void UART_1_callback_Rx (uint32_t data);
void UART_2_callback_Tx (uint32_t data);



int main (void)
{
	initAll ();

	buffer_Init ();

	UART_Init (&UART_1, UART1, 84000000,   9600, UART_PARITY_EVEN, UART_STOP_1);
	UART_Init (&UART_2, UART2, 42000000, 115200, UART_PARITY_EVEN, UART_STOP_1);
	
	UART_set_callback_Rx (&UART_1, UART_1_callback_Rx);
	UART_set_callback_Tx (&UART_2, UART_2_callback_Tx);

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


void UART_1_callback_Rx (uint32_t data)
{
	int i = -1;


	i = buffer_push (data);

	if (i >= 0)
	{
		UART_transmit (&UART_2, buffer + i, 128);
	}
}


void UART_2_callback_Tx (uint32_t data)
{
}



//
// Interrupt's
//
void USART1_IRQHandler (void)
{
	UART_IRQ_Handler (&UART_1);
}

void USART2_IRQHandler (void)
{
	UART_IRQ_Handler (&UART_2);
}

