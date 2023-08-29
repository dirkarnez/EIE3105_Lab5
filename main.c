//#include "stm32f10x.h"                  // Device header

//void delay(int t) {
//	int i;
//	for(i = 0; i < t; i++)
//		GPIOA->BSRR |= 0x01; // do something to PA0
//}

//int main(void) {
//	//GPIO set up for PA5 (on-board LED)
//	RCC->APB2ENR |= RCC_APB2Periph_GPIOA; //Enable APB2 peripheral clock
//	GPIOA->CRL &= ~0x00F00000; //clear the setting
//	GPIOA->CRL |= 0 << 22 | 2 << 20; //GPIO_Mode_Out_PP, GPIO_Speed_2MHz
//	
//	while(1) {
//		GPIOA->BSRR |= 0x20;
//		delay(3000000);
//		GPIOA->BRR  |= 0x20;
//		delay(3000000);
//	}
//}

//#include "stm32f10x.h"                  // Device header

//void DelayMs(uint32_t ms);

//static __IO uint32_t msTicks;

//void DelayMs(uint32_t ms)
//{
//	// Reload us value
//	msTicks = ms;
//	// Wait until usTick reach zero
//	while (msTicks);
//}

//// SysTick_Handler function will be called every 1 ms
//void SysTick_Handler()
//{
//	if (msTicks != 0)
//	{
//		msTicks--;
//	}
//}

//int main(void) {
//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
//	
//	//Enable APB2 periphral clock
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	// Update SystemCoreClock value
//	SystemCoreClockUpdate();
//	
//	// Configure the SysTick timer to overflow every 1 ms
//	SysTick_Config(SystemCoreClock / 1000);
//	
//	while(1) {
//		GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
//		DelayMs(1000);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET);
//		DelayMs(1000);
//	}	
//}


//#include "stm32f10x.h"
//#include "RTE_Components.h"             // Component selection
//#include "stdbool.h"

////PC13
//#define BUTTON_RCC_GPIO   RCC_APB2Periph_GPIOC
//#define BUTTON_GPIO	      GPIOC
//#define BUTTON_GPIO_PIN   GPIO_Pin_13
//#define BUTTON_EXTI_LINE     EXTI_Line13
//#define BUTTON_GPIO_PORTSOURCE GPIO_PortSourceGPIOC
//#define BUTTON_GPIO_PINSOURCE  GPIO_PinSource13

//static bool state = false;
//static bool state_changed = false;

//int main(void) {
//	GPIO_InitTypeDef GPIO_InitStruct;
//	EXTI_InitTypeDef EXTI_InitStruct;
//	NVIC_InitTypeDef NVIC_InitStruct;
//	
//	// GPIO clock for I/O
//	RCC_APB2PeriphClockCmd(BUTTON_RCC_GPIO, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	
//	// Configure I/O for L3
//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStruct);
// 
//	// Configure I/O for EXTI13
//	GPIO_InitStruct.GPIO_Pin = BUTTON_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_Init(BUTTON_GPIO, &GPIO_InitStruct);
//	
//	// EXTI Configuration
//	GPIO_EXTILineConfig(BUTTON_GPIO_PORTSOURCE, BUTTON_GPIO_PINSOURCE);

//	EXTI_InitStruct.EXTI_Line = BUTTON_EXTI_LINE;
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStruct);
//	
//	// Enable Interrupt
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
//    	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x02;
//	NVIC_Init(&NVIC_InitStruct);
//	
//	
//	while(1) {
//		if(state_changed) {
//			if(state) {
//				GPIO_ResetBits(GPIOA, GPIO_Pin_5);
//			} else {
//				GPIO_SetBits(GPIOA, GPIO_Pin_5);
//			}
//			state_changed = false;
//		}
//	}
//}

//void EXTI15_10_IRQHandler(void) {
//  if (EXTI_GetITStatus(EXTI_Line13) != RESET) {				
//		state = !state;
//		state_changed = true;
//		EXTI_ClearITPendingBit(EXTI_Line13);
//	}
//}

//#include "stm32f10x.h"
//#include "RTE_Components.h"             // Component selection
//#include "stdbool.h"

////PC13
//#define BUTTON_RCC_GPIO   RCC_APB2Periph_GPIOC
//#define BUTTON_GPIO	      GPIOC
//#define BUTTON_GPIO_PIN   GPIO_Pin_13
//#define BUTTON_EXTI_LINE     EXTI_Line13
//#define BUTTON_GPIO_PORTSOURCE GPIO_PortSourceGPIOC
//#define BUTTON_GPIO_PINSOURCE  GPIO_PinSource13

//static bool state = false;
//static bool state_changed = false;

//int main(void) {
//	GPIO_InitTypeDef GPIO_InitStruct;
//	EXTI_InitTypeDef EXTI_InitStruct;
//	NVIC_InitTypeDef NVIC_InitStruct;
//	
//	// GPIO clock for I/O
//	RCC_APB2PeriphClockCmd(BUTTON_RCC_GPIO, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	
//	// Configure I/O for L3
//	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStruct);
// 
//	// Configure I/O for EXTI13
//	GPIO_InitStruct.GPIO_Pin = BUTTON_GPIO_PIN;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_Init(BUTTON_GPIO, &GPIO_InitStruct);
//	
//	// EXTI Configuration
//	GPIO_EXTILineConfig(BUTTON_GPIO_PORTSOURCE, BUTTON_GPIO_PINSOURCE);

//	EXTI_InitStruct.EXTI_Line = BUTTON_EXTI_LINE;
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStruct);
//	
//	// Enable Interrupt
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
//    	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x02;
//	NVIC_Init(&NVIC_InitStruct);
//	
//	
//	while(1) {
//		if(state_changed) {
//			if(state) {
//				GPIO_ResetBits(GPIOA, GPIO_Pin_5);
//			} else {
//				GPIO_SetBits(GPIOA, GPIO_Pin_5);
//			}
//			state_changed = false;
//		}
//	}
//}

//void EXTI15_10_IRQHandler(void) {
//  if (EXTI_GetITStatus(EXTI_Line13) != RESET) {				
//		state = !state;
//		state_changed = true;
//		EXTI_ClearITPendingBit(EXTI_Line13);
//	}
//}

//#include "stm32f10x.h"                  // Device header
//#include "stdbool.h"

////TI2 PA1 Tim2 Ch2
//#define BUTTON_RCC_GPIO RCC_APB2Periph_GPIOA
//#define BUTTON_GPIO GPIOA
//#define BUTTON_GPIO_PIN GPIO_Pin_1
//#define L3_RCC_GPIO RCC_APB2Periph_GPIOB

//static bool state = true;

//int main(void) {
//	GPIO_InitTypeDef GPIO_InitStruct;
//	TIM_TimeBaseInitTypeDef timerInitStructure;
//	
//// GPIO clock for I/O
//RCC_APB2PeriphClockCmd(BUTTON_RCC_GPIO, ENABLE);
//RCC_APB2PeriphClockCmd(L3_RCC_GPIO, ENABLE);
//	
//// Configure I/O for L3
//GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
//GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//GPIO_Init(GPIOB, &GPIO_InitStruct);
//	
//// Configure I/O for BUTTON
//GPIO_InitStruct.GPIO_Pin = BUTTON_GPIO_PIN;
//GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
//GPIO_Init(BUTTON_GPIO, &GPIO_InitStruct);
//	
////Timer 2 set up
//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

//timerInitStructure.TIM_Prescaler = 0;
//timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//timerInitStructure.TIM_Period = 5;
//timerInitStructure.TIM_ClockDivision = 0;
//timerInitStructure.TIM_RepetitionCounter = 0;
//TIM_TimeBaseInit(TIM2, &timerInitStructure);
//TIM_Cmd(TIM2, ENABLE);
//TIM_TIxExternalClockConfig(TIM2, TIM_TIxExternalCLK1Source_TI2, TIM_ICPolarity_Rising, 0);

////Enable update event for Timer2
//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
//NVIC_EnableIRQ(TIM2_IRQn);
//while(1) {}

//}

//void TIM2_IRQHandler(void) {
//	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
//	if(state == 1) {
//		GPIO_SetBits(GPIOB, GPIO_Pin_8);
//		state = 0;
//	} else {
//		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
//		state = 1;
//	}
//	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}                          
//}

// Serial
#include "stm32f10x.h"                  // Device header
#include "string.h"

int main(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//USART2 TX RX
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//USART2 ST-LINK USB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	

	//USART_ClockInitTypeDef USART_ClockInitStructure; 
	
	USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
 	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_Init(USART2, &USART_InitStructure);
	USART_Cmd(USART2, ENABLE);

	// Enable the USART2 TX Interrupt 
	USART_ITConfig(USART2, USART_IT_TC, ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	// Enable the USART2 RX Interrupt
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE );
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	while(1) {}
}

unsigned char character, state = 0;
unsigned char pressed_character = 0;
int i = 0;

void USART2_IRQHandler() {
	if(USART_GetITStatus(USART2, USART_IT_TC) != RESET) {
		if (state == 0) {
			USART_SendData(USART2, 'a');
		}
		USART_ClearITPendingBit(USART2, USART_IT_TC);
	}
	
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) {
		character = (unsigned char) USART_ReceiveData(USART2); 
		if (pressed_character == 0) {
			state = 1;
			i = 0;
			pressed_character = character;
		} else {
			if (pressed_character == character) {
				state = 0;
				pressed_character = 0;
			} else {
				state = 2;
			}
		}
	}
	
	if (state == 0) {
			USART_SendData(USART2, 'a');
	} else if (state == 1) {
		if (i < 10) {
			USART_SendData(USART2, pressed_character);
			i++;
		}
	}
}


