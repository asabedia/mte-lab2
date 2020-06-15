#include "periphutils.h"

/*
n: integer specifying the number of continuous 1s in a binary string
returns the integer representation of the binary number that has n continuous 1s (with the last 1 being in bit 0)
*/
uint32_t IntToBits(uint8_t n){
	uint32_t result;
	switch (n%4){
		case 1:
			result = 0x1; break;
		case 2:
			result = 0x3; break;
		case 3:
			result = 0x7; break;
		case 0:
			result = 0x0; break;
	}
	
	uint8_t Fs = n / 4;
	result <<= Fs * 4;
	
	result += (0xffffffff >> (32 - Fs*4));
	
	return result;
}

void writeToGPIO(LPC_GPIO_TypeDef* port, uint8_t pin, bool bit_value){

	if(bit_value){
		port->FIOPIN |= (1 << pin);
	}else{
		port->FIOPIN &= ~(1 << pin);
	}
	
}

void writeLED(uint8_t led_num, bool bit_value){
	
	switch (led_num) {
		case 0:
			writeToGPIO(LPC_GPIO1, 28, bit_value); break;
		case 1:
			writeToGPIO(LPC_GPIO1, 29, bit_value);  break;
		case 2:
			writeToGPIO(LPC_GPIO1, 31, bit_value);  break;
		case 3:
			writeToGPIO(LPC_GPIO2, 2, bit_value);  break;
		case 4:
			writeToGPIO(LPC_GPIO2, 3, bit_value);  break;
		case 5:
			writeToGPIO(LPC_GPIO2, 4, bit_value);  break;
		case 6:
			writeToGPIO(LPC_GPIO2, 5, bit_value);  break;
		case 7:
			writeToGPIO(LPC_GPIO2, 6, bit_value);  break;
	}
	
	//LPC_GPIO1->FIODIR = IntToBits(32);
	//LPC_GPIO2->FIODIR = IntToBits(32);
}

void setLEDs(uint8_t* arr){
	for(int i=0; i < 8; i++) writeLED(i, arr[i]);
}

void set_all_LED(bool bit_value){
	for(int i =0; i < 8; i++) writeLED(i, bit_value);
}

void setupLED(void){
	LPC_GPIO1->FIODIR = 0xB0000000;
	LPC_GPIO2->FIODIR = IntToBits(5) << 2;
}

/*
FUNC void ShowLEDs(void) {
	printf("LEDs: %c%c%c%c %c%c%c%c\r\n",
		(PORT2 & bitmask(6)) ? 'X' : '_',
		(PORT2 & bitmask(5)) ? 'X' : '_',
		(PORT2 & bitmask(4)) ? 'X' : '_',
		(PORT2 & bitmask(3)) ? 'X' : '_',
		(PORT2 & bitmask(2)) ? 'X' : '_',
		(PORT1 & bitmask(31)) ? 'X' : '_',
		(PORT1 & bitmask(29)) ? 'X' : '_',
		(PORT1 & bitmask(28)) ? 'X' : '_');
}
*/

