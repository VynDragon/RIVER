#pragma once

#include <stdint.h>

// Section Undefined
typedef struct Hart Hart;
// Section End

#define WORDTYPE(WORDLEN)	uint ## WORDLEN ## _t
#define WORD			WORDTYPE(32)

typedef	int(*ISA_Instruction)(Hart*, WORD*);

typedef struct ISA_filter {
	WORD					mask;
	unsigned char			shift;
	WORD					value;
	ISA_Instruction			*instruction;
	const struct ISA_filter	*filters;
} ISA_filter;
