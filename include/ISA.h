#pragma once

#include <stdint.h>

#define WORDTYPE(WORDLEN)	uint ## WORDLEN ## _t
#define WORD			WORDTYPE(32)

#define INSTRUCTION_OPCODE		0x7F
#define INSTRUCTION_RD			0xF80
#define INSTRUCTION_RD_SHIFT		7
#define INSTRUCTION_FUNCT3		0x7000
#define INSTRUCTION_FUNCT3_SHIFT	12
#define INSTRUCTION_RS1			0xF8000
#define INSTRUCTION_RS1_SHIFT		15
#define INSTRUCTION_RS2			0x1F00000
#define INSTRUCTION_RS2_SHIFT		20
#define INSTRUCTION_FUNCT7		0x1F00000
#define INSTRUCTION_FUNCT7_SHIFT	25