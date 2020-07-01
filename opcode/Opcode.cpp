#include "Opcode.h"

OPCODE Opcode::getFirstIndex(OPCODE command) {
    return (command & 0xF000) >> 12;
}

OPCODE Opcode::getLastNQuadbits(OPCODE command, unsigned int n) {
    OPCODE bitMask = 0x0000;
    for (int i = 0; i < n; i++) {
        bitMask = bitMask << 4;
        bitMask += 0x000F;
    }
    return command & bitMask;
}
OPCODE Opcode::getXRegister(OPCODE command) {
    return (command & 0x0F00) >> 8;
}
OPCODE Opcode::getYRegister(OPCODE command) {
    return (command & 0x00F0) >> 4;
}
