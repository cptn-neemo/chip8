#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Registers& v, OPCODE opcode) : 
    v(v),
    opcode(opcode),
    xIndex(Opcode::getXRegister(opcode)),
    yIndex(Opcode::getYRegister(opcode))
{  }

unsigned char BinaryOperation::getXIndex() {
    return xIndex;
}

unsigned char BinaryOperation::getYIndex() {
    return yIndex;
}
unsigned char BinaryOperation::getXValue() {
    return v[xIndex];
}

unsigned char BinaryOperation::getYValue() {
    return v[yIndex];
}

void BinaryOperation::setXRegisterTo(unsigned char value) {
    v[xIndex] = value;
}

void BinaryOperation::setVF() {
    v[VF] = 1;
}

void BinaryOperation::clearVF() {
    v[VF] = 0;
}
