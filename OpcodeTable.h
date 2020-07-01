#include <stdexcept> 
#include <iostream>
#include "types.h"
#include "SystemInformation.h"
#include "opcode/Opcode.h"

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
        void skipIfRegistersNotEqual(OPCODE);
        void setRegisterToConstant(OPCODE);
        void addConstantToRegister(OPCODE);
        void set(OPCODE);
        void binaryOr(OPCODE);
        void binaryAnd(OPCODE);
        void binaryXOR(OPCODE);
        void add(OPCODE);
        void subtract(OPCODE);

        void skipNextInstructionIf(bool);
        void setRegister(unsigned char registerIndex, OPCODE value);

        SystemInformation *sysInfo;
        std::array<Routine, NUM_OPCODES> table;
};

#endif
