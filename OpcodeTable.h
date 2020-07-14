#include <stdexcept> 
#include <iostream>
#include "types.h"
#include "SystemInformation.h"
#include "opcode/Opcode.h"
#include "opcode/BinaryOperation.h"
#include "opcode/UnaryOperation.h"
#include <random>

#ifndef __opcode_table_h
#define __opcode_table_h

class OpcodeTable;
using Routine = void (OpcodeTable::*)(OPCODE);

class OpcodeTable {
    public:
        OpcodeTable(SystemInformation *sysInfo);
        void executeOpcode(OPCODE command);

    private:
        void setupTable();
        unsigned int getOpcodeTableIndex(OPCODE command);
        unsigned int get0thOpcodeTableIndex(OPCODE command);
        unsigned int get8thOpcodeTableIndex(OPCODE command);

        void callMachineCode(OPCODE);
        void clearDisplay(OPCODE);
        void subReturn(OPCODE);
        void jump(OPCODE);
        void call(OPCODE);
        void skipIfRegisterEqualToConstant(OPCODE);
        void skipIfRegisterNotEqualToConstant(OPCODE);
        void skipIfRegistersEqual(OPCODE);
        void setRegisterToConstant(OPCODE);
        void addConstantToRegister(OPCODE);
        void set(OPCODE);
        void binaryOr(OPCODE);
        void binaryAnd(OPCODE);
        void binaryXOR(OPCODE);
        void add(OPCODE);
        void subtract(OPCODE);
        void shiftRight(OPCODE);
        void subtractn(OPCODE);
        void shiftLeft(OPCODE);
        void skipIfRegistersNotEqual(OPCODE);
        void setI(OPCODE);
        void jumpWithOffset(OPCODE);
        void rand(OPCODE);

        void skipNextInstructionIf(bool);

        SystemInformation *sysInfo;
        std::array<Routine, NUM_OPCODES> table;

        std::mt19937 gen{100};
        std::uniform_int_distribution<> distrib{0, 255}; 
};

#endif
