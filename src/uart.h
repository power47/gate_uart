#ifndef  UART_H
#define  UART_H


#define  _SRAM_BASE 		((uint32_t)0x20000000) // SRAM base address in the bit-band region
#define  _PERIPH_BASE 		((uint32_t)0x40000000) // Peripheral base address in the bit-band region

#define  _APB1PERIPH_BASE 	(_PERIPH_BASE + 0x00)
#define  _APB2PERIPH_BASE 	(_PERIPH_BASE + 0x10000)
#define  _AHBPERIPH_BASE 	(_PERIPH_BASE + 0x20000)


static uint32_t UART_base [5] = {
	(_APB2PERIPH_BASE + 0x1000), 
	(_APB1PERIPH_BASE + 0x4400), 
	(_APB1PERIPH_BASE + 0x4800), 
	(_APB1PERIPH_BASE + 0x4C00), 
	(_APB1PERIPH_BASE + 0x5000)
};


#define  UART_SR 			((uint32_t)0x00)
#define  UART_DR 			((uint32_t)0x04)
#define  UART_BRR 			((uint32_t)0x08)
#define  UART_CR1 			((uint32_t)0x0C)
#define  UART_CR2 			((uint32_t)0x10)
#define  UART_CR3 			((uint32_t)0x14)
#define  UART_GTPR 			((uint32_t)0x18)

#define  UART_REG(NUM,REG) 	(*((uint32_t *)(UART_base [NUM] + REG)))

#define  UART_SR_PE 		((uint16_t)0x0001) // Parity Error
#define  UART_SR_FE 		((uint16_t)0x0002) // Framing Error
#define  UART_SR_NE 		((uint16_t)0x0004) // Noise Error Flag
#define  UART_SR_ORE 		((uint16_t)0x0008) // OverRun Error
#define  UART_SR_IDLE 		((uint16_t)0x0010) // IDLE line detected
#define  UART_SR_RXNE 		((uint16_t)0x0020) // Read Data Register Not Empty
#define  UART_SR_TC 		((uint16_t)0x0040) // Transmission Complete
#define  UART_SR_TXE 		((uint16_t)0x0080) // Transmit Data Register Empty
#define  UART_SR_LBD 		((uint16_t)0x0100) // LIN Break Detection Flag
#define  UART_SR_CTS 		((uint16_t)0x0200) // CTS Flag

#define  UART_CR1_SBK 		((uint16_t)0x0001) // Send Break
#define  UART_CR1_RWU 		((uint16_t)0x0002) // Receiver wakeup
#define  UART_CR1_RE 		((uint16_t)0x0004) // Receiver Enable
#define  UART_CR1_TE 		((uint16_t)0x0008) // Transmitter Enable
#define  UART_CR1_IDLEIE 	((uint16_t)0x0010) // IDLE Interrupt Enable
#define  UART_CR1_RXNEIE 	((uint16_t)0x0020) // RXNE Interrupt Enable
#define  UART_CR1_TCIE 		((uint16_t)0x0040) // Transmission Complete Interrupt Enable
#define  UART_CR1_TXEIE 	((uint16_t)0x0080) // PE Interrupt Enable
#define  UART_CR1_PEIE 		((uint16_t)0x0100) // PE Interrupt Enable
#define  UART_CR1_PS 		((uint16_t)0x0200) // Parity Selection
#define  UART_CR1_PCE 		((uint16_t)0x0400) // Parity Control Enable
#define  UART_CR1_WAKE 		((uint16_t)0x0800) // Wakeup method
#define  UART_CR1_M 		((uint16_t)0x1000) // Word length
#define  UART_CR1_UE 		((uint16_t)0x2000) // UART Enable
#define  UART_CR1_OVER8 	((uint16_t)0x8000) // UART Oversmapling 8-bits

#define  UART_CR2_ADD 		((uint16_t)0x000F) // Address of the UART node
#define  UART_CR2_LBDL 		((uint16_t)0x0020) // LIN Break Detection Length
#define  UART_CR2_LBDIE 	((uint16_t)0x0040) // LIN Break Detection Interrupt Enable
#define  UART_CR2_LBCL 		((uint16_t)0x0100) // Last Bit Clock pulse
#define  UART_CR2_CPHA 		((uint16_t)0x0200) // Clock Phase
#define  UART_CR2_CPOL 		((uint16_t)0x0400) // Clock Polarity
#define  UART_CR2_CLKEN 	((uint16_t)0x0800) // Clock Enable
#define  UART_CR2_STOP 		((uint16_t)0x3000) // STOP[1:0] bits (STOP bits)
#define  UART_CR2_STOP_0 	((uint16_t)0x1000) // Bit 0
#define  UART_CR2_STOP_1 	((uint16_t)0x2000) // Bit 1
#define  UART_CR2_LINEN 	((uint16_t)0x4000) // LIN mode enable

#define  UART_CR3_EIE 		((uint16_t)0x0001) // Error Interrupt Enable
#define  UART_CR3_IREN 		((uint16_t)0x0002) // IrDA mode Enable
#define  UART_CR3_IRLP 		((uint16_t)0x0004) // IrDA Low-Power
#define  UART_CR3_HDSEL 	((uint16_t)0x0008) // Half-Duplex Selection
#define  UART_CR3_NACK 		((uint16_t)0x0010) // Smartcard NACK enable
#define  UART_CR3_SCEN 		((uint16_t)0x0020) // Smartcard mode enable
#define  UART_CR3_DMAR 		((uint16_t)0x0040) // DMA Enable Receiver
#define  UART_CR3_DMAT 		((uint16_t)0x0080) // DMA Enable Transmitter
#define  UART_CR3_RTSE 		((uint16_t)0x0100) // RTS Enable
#define  UART_CR3_CTSE 		((uint16_t)0x0200) // CTS Enable
#define  UART_CR3_CTSIE 	((uint16_t)0x0400) // CTS Interrupt Enable
#define  UART_CR3_ONEBIT 	((uint16_t)0x0800) // One Bit method




#define  UART_COUNT 		2
#define  UART1 				0
#define  UART2 				1

typedef void (*UART_pFnk) (uint32_t);

typedef struct {
	int 		num;

	uint8_t * 	ptr_data_Tx;
	int 		data_Tx_len;
	int 		data_Tx_index;
	UART_pFnk 	callback_Tx;

	UART_pFnk 	callback_Rx;
} UART_t;


typedef enum {
	UART_PARITY_EVEN 	= 0, 
	UART_PARITY_ODD 	= 1
} UART_parity_t;

typedef enum {
	UART_STOP_1 	= 0, 
	UART_STOP_05 	= 1, 
	UART_STOP_2 	= 2, 
	UART_STOP_15 	= 3
} UART_stop_t;





static void UART_set_baud (UART_t * pUART, uint32_t baud, uint32_t clock)
{
	uint32_t div;
	uint32_t mant;
	uint32_t fraq;


	div = (uint32_t)((((uint64_t)(clock))*100U)/(16U*((uint64_t)(baud))));

	mant = (uint32_t)(div / 100U);
	fraq = (uint32_t)(((div - (mant * 100U)) * 16U) / 10U);


	UART_REG(pUART -> num, UART_BRR) = (mant << 4) + (fraq & 0x0F);
}



static void UART_set_parity (UART_t * pUART, UART_parity_t parity)
{
	if (parity == UART_PARITY_ODD)
	{
		UART_REG(pUART->num, UART_CR1) |=  UART_CR1_PCE;
	}
	else
	{
		UART_REG(pUART->num, UART_CR1) &= ~UART_CR1_PCE;
	}
}



static void UART_set_stop (UART_t * pUART, UART_stop_t stop)
{
	if 		(stop == UART_STOP_1)
	{
		UART_REG(pUART->num, UART_CR2) &= ~UART_CR2_STOP_0;
		UART_REG(pUART->num, UART_CR2) &= ~UART_CR2_STOP_1;
	}
	else if (stop == UART_STOP_05)
	{
		UART_REG(pUART->num, UART_CR2) |=  UART_CR2_STOP_0;
		UART_REG(pUART->num, UART_CR2) &= ~UART_CR2_STOP_1;
	}
	else if (stop == UART_STOP_2)
	{
		UART_REG(pUART->num, UART_CR2) &= ~UART_CR2_STOP_0;
		UART_REG(pUART->num, UART_CR2) |=  UART_CR2_STOP_1;
	}
	else
	{
		UART_REG(pUART->num, UART_CR2) |=  UART_CR2_STOP_0;
		UART_REG(pUART->num, UART_CR2) |=  UART_CR2_STOP_1;
	}
}



static void UART_Init ( 
		UART_t * pUART, 
		int num, 
		uint32_t clock, 
		uint32_t baud, 
		UART_parity_t parity, 
		UART_stop_t stop)
{
	if (num >= UART_COUNT)
		return;


	pUART -> num = num;

	pUART -> ptr_data_Tx = NULL;
	pUART -> data_Tx_len = 0;
	pUART -> data_Tx_index = 0;
	pUART -> callback_Tx = NULL;

	pUART -> callback_Rx = NULL;


	UART_REG(pUART->num, UART_CR1) = 0x00;
	UART_REG(pUART->num, UART_CR2) = 0x00;
	UART_REG(pUART->num, UART_CR3) = 0x00;

	UART_REG(pUART->num, UART_CR1) |= UART_CR1_UE; 		// 8-bit word

	UART_REG(pUART->num, UART_CR1) &= ~UART_CR1_M; 		// 8-bit word

	UART_set_parity (pUART, parity);

	UART_set_stop (pUART, stop);

	UART_set_baud (pUART, baud, clock);
}


static void UART_set_callback_Tx (UART_t * pUART, UART_pFnk fnc)
{
	pUART -> callback_Tx = fnc;

	UART_REG(pUART->num,UART_CR1) |=  UART_CR1_TE;
	UART_REG(pUART->num,UART_CR1) |=  UART_CR1_TXEIE;
	UART_REG(pUART->num,UART_CR3) &= ~UART_CR3_DMAT;
}

static void UART_set_callback_Rx (UART_t * pUART, UART_pFnk fnc)
{
	pUART -> callback_Rx = fnc;

	UART_REG(pUART->num,UART_CR1) |=  UART_CR1_RE;
	UART_REG(pUART->num,UART_CR1) |=  UART_CR1_RXNEIE;
	UART_REG(pUART->num,UART_CR3) &= ~UART_CR3_DMAR;
}



static void UART_transmit (UART_t * pUART, uint8_t * p_data, int p_data_len)
{
	if (pUART -> data_Tx_index != 0 || 
		pUART -> data_Tx_len != 0)
		return;


	pUART -> ptr_data_Tx = p_data;
	pUART -> data_Tx_len = p_data_len;
	pUART -> data_Tx_index = 0;

	UART_REG(pUART -> num, UART_DR) = *(pUART -> ptr_data_Tx + pUART -> data_Tx_index);
}



static void UART_IRQ_Handler (UART_t * pUART)
{
	if (UART_REG(pUART -> num, UART_SR) & UART_SR_TXE)
	{
		pUART -> data_Tx_index ++;
		if (pUART -> data_Tx_index < pUART -> data_Tx_len)
		{
			UART_REG(pUART -> num, UART_SR) = ~UART_SR_TXE;
			UART_REG(pUART -> num, UART_DR) = *(pUART -> ptr_data_Tx + pUART -> data_Tx_index);
		}
		else
		{
			pUART -> data_Tx_index = 0;
			pUART -> data_Tx_len = 0;

			if (pUART -> callback_Tx != NULL)
			{
				(pUART -> callback_Tx) (0);
			}
		}
	}

	if (UART_REG(pUART -> num, UART_SR) & UART_SR_RXNE)
	{
		UART_REG(pUART -> num, UART_SR) = ~UART_SR_RXNE;

		if (pUART -> callback_Rx != NULL)
		{
			(pUART -> callback_Rx) (UART_REG(pUART -> num, UART_DR));
		}
	}
}


#endif
