#include <stdlib.h>

#include "cpu.h"

System	*allocateSystem(uint8_t hartNb, WORD memorySize)
{
	System	*system = malloc(sizeof(System));
	system->cpu.harts = malloc(sizeof(Hart) * hartNb);
	system->cpu.hartNb = hartNb;
	system->memory.raw = malloc(sizeof(WORD) * memorySize);
	system->memory.size = memorySize;
	for (int i = 0; i < hartNb; i++)
	{
		system->cpu.harts->memory = &system->memory;
	}
	return system;
}