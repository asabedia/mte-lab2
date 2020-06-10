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
			result = 0x6; break;
		case 0:
			result = 0x0; break;
	}
	
	uint8_t Fs = n / 4;
	result <<= Fs * 4;
	
	result += (0xffffffff >> (32 - Fs*4));
	
	return result;
}