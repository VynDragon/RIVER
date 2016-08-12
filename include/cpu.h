#pragma once

#include "ISA.h"


typedef struct Memory {
	WORD	size;
	WORD	*raw;
} Memory;

typedef struct Hart { // no core structure as they are seen as harts by the code running.
	WORD	registers[32];
	WORD	pc;
	Memory	*memory;
} Hart;

typedef struct CPU {
	uint8_t	hartNb;
	Hart 	*harts;
} CPU;

typedef struct	System {
	CPU	cpu;
	Memory	memory;
} System;

System	*allocateSystem(uint8_t hartNb, WORD memorySize);