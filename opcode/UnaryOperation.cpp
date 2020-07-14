#include "UnaryOperation.h"

UnaryOperation::UnaryOperation(Registers& v, OPCODE opcode) : 
    opcode(opcode),
    xIndex(Opcode::getXRegister(opcode)),
    nn(Opcode::getLastNQuadbits(opcode, 2)),
    v(v)
    {  }

unsigned char UnaryOperation::getXIndex() {
    return xIndex;
}

unsigned char UnaryOperation::getXValue() {
    return v[xIndex];
}

OPCODE UnaryOperation::getNNValue() {
    return nn;
}

void UnaryOperation::setXRegisterTo(unsigned char value) {
    v[xIndex] = value;
}
