#include <array>

#ifndef __types_h
#define __types_h

const unsigned int NUM_OPCODES = 35;
const unsigned int PROGRAM_START = 0x200;
const unsigned int DISPLAY_LENGTH = 64*32;

using mem_t = std::array<unsigned char, 4096>;
using stack_t = std::array<unsigned short, 16>;
using display_t = std::array<unsigned char, 64*32>;
using keys_t = std::array<bool, 16>;
using OPCODE = unsigned short;
using Registers = std::array<unsigned char, 16>;

#endif
