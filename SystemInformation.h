#include "types.h"
#include "cpu.h"

#ifndef __system_information_h
#define __system_information_h

struct SystemInformation {
    cpu_t cpu; 
    mem_t mem; 
    stack_t stack;
    display_t display;
    keys_t keys;
};

#endif
