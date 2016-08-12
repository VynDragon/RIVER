#include "ISA.h"
#include <stdio.h>

ISA_Instruction	resolveInstruction(const ISA_filter *isa, Hart *hart, const WORD *instruction)
{
	WORD value = *instruction & isa->mask;
	value = value >> isa->shift;
	while (*(WORD*)isa != ISA_filter_end_mask)
	{
		if (value == isa->value)
		{
			if (isa->instruction != 0)
				return isa->instruction;
			else
				return resolveInstruction(isa->filters, hart, instruction);
		}
		isa++;
	}
	return NULL;
}

uint8_t		executeInstruction(const ISA_filter *isa, Hart *hart, const WORD *instruction)
{
	ISA_Instruction iInstruction = resolveInstruction(isa, hart, instruction);
	if (iInstruction == NULL)
		return 128;
	return iInstruction(hart, instruction);
}