#include "../SystemInformation.h"
#include "../types.h"
#include "../cpu.h"

#ifndef __opcode_h
#define __opcode_h

class Opcode {
    public:
        static OPCODE getFirstIndex(OPCODE);
        static OPCODE getLastNQuadbits(OPCODE, unsigned int);
        static OPCODE getXRegister(OPCODE);
        static OPCODE getYRegister(OPCODE);
};

#endif
