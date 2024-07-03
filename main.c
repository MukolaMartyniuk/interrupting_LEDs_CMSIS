#include "stm32f4xx.h"

void GPIO_Init(void);


void EXTI_Init(void);


void EXTI0_IRQHandler(void);


void GPIO_Init(void){
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->MODER &= ~(3U << 0);
	
	GPIOD->MODER &= ~(3U << 24);
	GPIOD->MODER &= ~(3U << 28);
	
	GPIOD->MODER |= 1U << 24;
	GPIOD->MODER |= 1U << 28;
	
}

void EXTI_Init(void){
	
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;
	
	EXTI->IMR |= EXTI_IMR_MR0;
	EXTI->FTSR |= EXTI_FTSR_TR0;
	
	NVIC_EnableIRQ(EXTI0_IRQn);
}


void EXTI0_IRQHandler(void){
	
	static int led_state = 0;
	
	if (EXTI->PR & EXTI_PR_PR0){
		
		for(volatile int i = 0; i < 1000000; ++i);
		
			if (!(GPIOA->IDR & GPIO_IDR_ID0)){
				
			if (led_state == 0){
				GPIOD->ODR = 0x0000;
				GPIOD->ODR = 0x1000;
				led_state = 1;
			} else {
				GPIOD->ODR = 0x0000;
				GPIOD->ODR = 0x4000;
				led_state = 0;
			}
		}
		
		EXTI->PR = EXTI_PR_PR0;
	}
}



int main(void){
	
	GPIO_Init();
	
	EXTI_Init();
	
	while(1){
		
	}
}

