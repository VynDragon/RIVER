#pragma once

#include <stdint.h>
#include "const.h"

// Section Undefined
typedef struct Hart Hart;
// Section End

#define WORDTYPE(WORDLEN)	uint ## WORDLEN ## _t
#define WORD			WORDTYPE(32)

typedef	uint8_t (*ISA_Instruction)(Hart*, const WORD*);

typedef struct ISA_filter {
	WORD			mask;
	WORD			shift;
	WORD			value;
	ISA_Instruction		instruction;
	const struct ISA_filter	*filters;
} ISA_filter;

#define ISA_filter_end { 0, 0, 0, 0, 0 }
#define ISA_filter_end_mask 0

ISA_Instruction	resolveInstruction(const ISA_filter *isa, Hart *hart, const WORD *instruction);
uint8_t		executeInstruction(const ISA_filter *isa, Hart *hart, const WORD *instruction);
