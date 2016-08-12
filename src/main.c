#include "cpu.h"
#include "RISC-V.h"

int main(int ac, char **av)
{
	System *system = allocateSystem(1, 65536);
	system->memory.raw[0] = 0b01000000000000000000000000110011;
	executeInstruction(ISA, system->cpu.harts, system->memory.raw);
}