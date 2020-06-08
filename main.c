#include <stdio.h>
#include <LPC17xx.h>
#include <stdbool.h>

int main(void){
	while(true){
		//volatile uint16_t *ptr = &LPC_GPIO2->FIOPINL;
		//*ptr &= 0x0;
												
		LPC_GPIO2->FIODIRL = 0x0;
		//LPC_GPIO2->FIOPINL &= ~(0x1f << 2);
		LPC_GPIO2->FIOCLRL = (0x6 << 2);
		//0x11 = 00010001
		// 0x1, 0x3, 0x6, 0xf
		// 0001, 0011, 0111, 1111
		// 0x1f
		// 0000 0000 0111 1100 --> 0x1f << 2
		// 1111 1111 1110 0000 --> ~0x1f
		// 0011 1111 1111 1111 --> default
		// 0011 1111 1110 0000
		
		
		LPC_GPIO2->FIODIRL = 0xffff;
		
		int x = LPC_GPIO2->FIOPIN;
		int low = LPC_GPIO2->FIOPINL;
		int high = LPC_GPIO2->FIOPINH;
		
		int a1= (int)&(LPC_GPIO2->FIOPINL); 
		int a2= (int)&(LPC_GPIO2->FIOPINH);
		
		printf("%x, %x, low: %x, high: %x\n", a1, a2, low, high);
	}
	// 00000000 00000000 00111111 11111111 --> button up
	// 00000000 00000000 00000000 00000000
	// 00000000 00000000 00111011 11111111 --> button down
	
}
