#include "../types.h"
#include "../SystemInformation.h"
#include "Opcode.h"

#ifndef __binary_op_h
#define __binary_op_h

const unsigned char VF = 15;

class BinaryOperation {
    public:
        BinaryOperation(Registers&, OPCODE);
        unsigned char getXIndex();
        unsigned char getYIndex();
        unsigned char getXValue();
        unsigned char getYValue();
        void setXRegisterTo(unsigned char value);
        void setVF();
        void clearVF();

    private:
        OPCODE opcode;
        unsigned char xIndex;
        unsigned char yIndex;
        Registers& v;
};

#endif
