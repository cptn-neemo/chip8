#include <array>

#ifndef __cpu_h
#define __cpu_h

struct cpu_t {
    // Initialize all the registers to have a value of 0
    cpu_t() { v.fill(0); }

    // Registers
    std::array<unsigned char, 16> v;
    unsigned short I{0};

    // Timers
    unsigned short delayTimer{0};
    unsigned short soundTimer{0};

    // Stack/Instruction pointers
    unsigned short sp{0};
    unsigned short ip{0};

    // Current opcode to execute
    unsigned short opcode{0};
};

#endif
