#include <stdio.h>
#include <LPC17xx.h>
#include <stdbool.h>
#include "periphutils.h"
#define PART 1

int main(void);

#if PART == 1
	#include "part1.main"
#elif PART == 2
	#include "part2.main"
#elif PART == 3
	#include "part3.main"
#elif PART == 4
	#include "part4.main"
#endif
