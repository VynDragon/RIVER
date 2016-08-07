#pragma once

#include "RISC-V.h"

#define HARTNUMBER		1

typedef struct Hart { // no core structure as they are seen as harts by the code running.
	WORD	registers[32];
	WORD	pc;
} Hart;

typedef struct CPU {
	Hart harts[HARTNUMBER];
	
} CPU;