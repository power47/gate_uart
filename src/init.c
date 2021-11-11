#include <stm32f4xx.h>


#define  _INIT
#include "init.h"


void init_clock (void);



void initAll (void)
{
	init_clock ();

//	Disable JTAG and SWD pins
//	AFIO -> MAPR = 	AFIO_MAPR_SWJ_CFG_JTAGDISABLE;

	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN | 
					  RCC_AHB1ENR_GPIOBEN;

	RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;

	RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;



	// Disable standart UART1 output
	GPIOA -> AFR [1] 	&= ~(0x0F << GPIO_AFRH_AFSEL9_Pos);
	GPIOA -> AFR [1] 	&= ~(0x0F << GPIO_AFRH_AFSEL10_Pos);


	// U1.TX = PB6
	GPIOB -> MODER 		|=  (GPIO_MODER_MODER6_1);
	GPIOB -> MODER 		&= ~(GPIO_MODER_MODER6_0);
	GPIOB -> OTYPER 	&= ~(GPIO_OTYPER_OT_6);
	GPIOB -> OSPEEDR 	|=  (GPIO_OSPEEDR_OSPEED6_1 | GPIO_OSPEEDR_OSPEED6_0);
	GPIOB -> PUPDR 		&= ~(GPIO_PUPDR_PUPD6_1 | GPIO_PUPDR_PUPD6_0);
	GPIOB -> AFR [0] 	|=  (7 << GPIO_AFRL_AFSEL6_Pos);

	// U1.RX = PB7
	GPIOB -> MODER 		|=  (GPIO_MODER_MODER7_1);
	GPIOB -> MODER 		&= ~(GPIO_MODER_MODER7_0);
	GPIOB -> OTYPER 	&= ~(GPIO_OTYPER_OT_7);
	GPIOB -> OSPEEDR 	|=  (GPIO_OSPEEDR_OSPEED7_1 | GPIO_OSPEEDR_OSPEED7_0);
	GPIOB -> PUPDR 		&= ~(GPIO_PUPDR_PUPD7_1 | GPIO_PUPDR_PUPD7_0);
	GPIOB -> AFR [0] 	|=  (7 << GPIO_AFRL_AFSEL7_Pos);


	// U2.TX = PA2
	GPIOA -> MODER 		|=  (GPIO_MODER_MODER2_1);
	GPIOA -> MODER 		&= ~(GPIO_MODER_MODER2_0);
	GPIOA -> OTYPER 	&= ~(GPIO_OTYPER_OT_2);
	GPIOA -> OSPEEDR 	|=  (GPIO_OSPEEDR_OSPEED2_1 | GPIO_OSPEEDR_OSPEED2_0);
	GPIOA -> PUPDR 		&= ~(GPIO_PUPDR_PUPD2_1 | GPIO_PUPDR_PUPD2_0);
	GPIOA -> AFR [0] 	|=  (7 << GPIO_AFRL_AFSEL2_Pos);

	// U2.RX = PA3
	GPIOA -> MODER 		|=  (GPIO_MODER_MODER3_1);
	GPIOA -> MODER 		&= ~(GPIO_MODER_MODER3_0);
	GPIOA -> OTYPER 	&= ~(GPIO_OTYPER_OT_3);
	GPIOA -> OSPEEDR 	|=  (GPIO_OSPEEDR_OSPEED3_1 | GPIO_OSPEEDR_OSPEED3_0);
	GPIOA -> PUPDR 		&= ~(GPIO_PUPDR_PUPD3_1 | GPIO_PUPDR_PUPD3_0);
	GPIOA -> AFR [0] 	|=  (7 << GPIO_AFRL_AFSEL3_Pos);
}


void init_clock (void)
{
	// 2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
	RCC -> APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	RCC -> APB1ENR |= RCC_APB1ENR_PWREN;


	// 3. Configure the FLASH PREFETCH and the LATENCY Related Settings
	FLASH -> ACR = 	FLASH_ACR_ICEN | 
					FLASH_ACR_DCEN | 
					FLASH_ACR_PRFTEN | 
					FLASH_ACR_LATENCY_5WS;


	// Select voltage output (max freq - 168M)
	PWR -> CR |= (1 << PWR_CR_VOS_Pos);


	// 1. ENABLE HSE and wait for the HSE to become Ready
	RCC -> CR |= RCC_CR_HSEON;
	while (!(RCC -> CR & RCC_CR_HSERDY))
		;


#define  PLL_M 		4
#define  PLL_N 		168
#define  PLL_P 		0

	// 5. Configure the MAIN PLL
	RCC -> PLLCFGR = 	(PLL_M << 0) | 
						(PLL_N << 6) | 
						(PLL_P << 16) | 
						(RCC_PLLCFGR_PLLSRC_HSE);


	// 6. Enable the PLL and wait for it to become ready
	RCC -> CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY))
		;


	// 4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
	// AHB PR
	RCC -> CFGR |= RCC_CFGR_HPRE_DIV1;

	// APB1 PR - 42M
	RCC -> CFGR |= RCC_CFGR_PPRE1_DIV4;

	// APB2 PR - 84M
	RCC -> CFGR |= RCC_CFGR_PPRE2_DIV2;

	// MCO1
	RCC -> CFGR |= (7 << RCC_CFGR_MCO1PRE_Pos);
	RCC -> CFGR |= (3 << RCC_CFGR_MCO1_Pos);

	// MCO2
	RCC -> CFGR |= (7 << RCC_CFGR_MCO2PRE_Pos);
	RCC -> CFGR |= (0 << RCC_CFGR_MCO2_Pos);


	// 7. Select the Clock Source and wait for it to be set
	RCC -> CFGR |= RCC_CFGR_SW_PLL;
	while ((RCC -> CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
		;
}
