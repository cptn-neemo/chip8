#include "../types.h"
#include "../SystemInformation.h"
#include "Opcode.h"

#ifndef __unary_op_h
#define __unary_op_h


class UnaryOperation {
    public:
        UnaryOperation(Registers&, OPCODE);
        unsigned char getXIndex();
        unsigned char getXValue();
        OPCODE getNNValue();
        void setXRegisterTo(unsigned char value);

    private:
        OPCODE opcode{0};
        unsigned char xIndex{16};
        OPCODE nn{0};
        Registers& v;
};

#endif
