#include "OpcodeTable.h"

unsigned char max(unsigned char x, unsigned char y) {
    return x > y ? x : y;
}

OpcodeTable::OpcodeTable(SystemInformation *sysInfo) : sysInfo(sysInfo) {
    setupTable();
}

void OpcodeTable::setupTable() {
    table[0] = &OpcodeTable::callMachineCode;
    table[1] = &OpcodeTable::clearDisplay;
    table[2] = &OpcodeTable::subReturn;
    table[3] = &OpcodeTable::jump;
    table[4] = &OpcodeTable::call;
    table[5] = &OpcodeTable::skipIfRegisterEqualToConstant;
    table[6] = &OpcodeTable::skipIfRegisterNotEqualToConstant;
    table[7] = &OpcodeTable::skipIfRegistersEqual;
    table[8] = &OpcodeTable::setRegisterToConstant;
    table[9] = &OpcodeTable::addConstantToRegister;
    table[10] = &OpcodeTable::set;
    table[11] = &OpcodeTable::binaryOr;
    table[12] = &OpcodeTable::binaryAnd;
    table[13] = &OpcodeTable::binaryXOR;
    table[14] = &OpcodeTable::add;
    table[15] = &OpcodeTable::subtract;
    table[16] = &OpcodeTable::shiftRight;
    table[17] = &OpcodeTable::subtractn;
    table[18] = &OpcodeTable::shiftLeft;
    table[19] = &OpcodeTable::skipIfRegistersNotEqual;
    table[20] = &OpcodeTable::setI;
    table[21] = &OpcodeTable::jumpWithOffset;
    table[22] = &OpcodeTable::rand;
}

void OpcodeTable::executeOpcode(OPCODE command) {
    unsigned int opcodeTableIndex = getOpcodeTableIndex(command);
    (this->*table[opcodeTableIndex])(command);
}

unsigned int OpcodeTable::getOpcodeTableIndex(OPCODE command) {
    const unsigned int initialIndex = Opcode::getFirstIndex(command);
    switch (initialIndex) {
        case 0x0:
            return get0thOpcodeTableIndex(command);
        case 0x1:
            return 3;
        case 0x2:
            return 4;
        case 0x3:
            return 5;
        case 0x4:
            return 6;
        case 0x5:
            return 7;
        case 0x6:
            return 8;
        case 0x7:
            return 9;
        case 0x8:
            return get8thOpcodeTableIndex(command);
        case 0x9:
            return 19;
        case 0xA:
            return 20;
        case 0xB:
            return 21;
        case 0xC:
            return 22;
        default:
            throw std::out_of_range("Opcode index did not match any possibility.");
    }
}

unsigned int OpcodeTable::get0thOpcodeTableIndex(OPCODE command) {
    if (command == 0x00EE) {
        return 2;
    } else if (command == 0x00E0) {
        return 1;
    } else {
        return 0;
    }
}

unsigned int OpcodeTable::get8thOpcodeTableIndex(OPCODE command) {
    const int INDEX_OFFSET = 10;

    unsigned int eighthIndex = Opcode::getLastNQuadbits(command, 1);
    if (eighthIndex == 0xE)
        eighthIndex = 0x8;

    return INDEX_OFFSET + eighthIndex;
}

void OpcodeTable::callMachineCode(OPCODE command) {
    throw std::invalid_argument("Machine code called. Not implemented.");
}

void OpcodeTable::clearDisplay(OPCODE command) {
    sysInfo->display.fill(0);
}

void OpcodeTable::subReturn(OPCODE command) {
    const unsigned int sp = --sysInfo->cpu.sp;
    sysInfo->cpu.ip = sysInfo->stack[sp];
}

void OpcodeTable::jump(OPCODE command) {
    const OPCODE jumpAddress = Opcode::getLastNQuadbits(command, 3);
    sysInfo->cpu.ip = jumpAddress;    
}

void OpcodeTable::call(OPCODE command) {
    const OPCODE callAddress = Opcode::getLastNQuadbits(command, 3);
    sysInfo->stack[sysInfo->cpu.sp++] = sysInfo->cpu.ip;
    sysInfo->cpu.ip = callAddress;
}

void OpcodeTable::skipIfRegisterEqualToConstant(OPCODE command) {
    UnaryOperation uop(sysInfo->cpu.v, command);

    skipNextInstructionIf(uop.getXValue() ==  uop.getNNValue());
}

void OpcodeTable::skipIfRegisterNotEqualToConstant(OPCODE command) {
    UnaryOperation uop(sysInfo->cpu.v, command);

    skipNextInstructionIf(uop.getXValue() !=  uop.getNNValue());
}

void OpcodeTable::skipIfRegistersEqual(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);

    skipNextInstructionIf(bop.getXValue() == bop.getYValue());
}

void OpcodeTable::skipNextInstructionIf(bool condition) {
    if (condition)
        sysInfo->cpu.ip += 2;
}

void OpcodeTable::setRegisterToConstant(OPCODE command) {
    UnaryOperation uop(sysInfo->cpu.v, command);

    uop.setXRegisterTo(uop.getNNValue());
}

void OpcodeTable::addConstantToRegister(OPCODE command) {
    UnaryOperation uop(sysInfo->cpu.v, command);

    uop.setXRegisterTo(uop.getXValue() + uop.getNNValue());
}

void OpcodeTable::set(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);
    bop.setXRegisterTo(bop.getYValue());
}

void OpcodeTable::binaryOr(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);
    bop.setXRegisterTo(bop.getXValue() | bop.getYValue());
}

void OpcodeTable::binaryAnd(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);
    bop.setXRegisterTo(bop.getXValue() & bop.getYValue());
}

void OpcodeTable::binaryXOR(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);
    bop.setXRegisterTo(bop.getXValue() ^ bop.getYValue());
}

void OpcodeTable::add(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);

    unsigned char sum = bop.getXValue() + bop.getYValue();
    if (sum < max(bop.getXValue(), bop.getYValue())) {
        bop.setVF();
    } else {
        bop.clearVF();
    }

    bop.setXRegisterTo(bop.getXValue() + bop.getYValue());
}

void OpcodeTable::subtract(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);
    if (bop.getXValue() < bop.getYValue()) {
        bop.setVF();
    } else {
        bop.clearVF();
    }
    bop.setXRegisterTo(bop.getXValue() - bop.getYValue());
}

void OpcodeTable::shiftRight(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);

    if (bop.getXValue() & 0x1) {
        bop.setVF();
    } else {
        bop.clearVF();
    }
    bop.setXRegisterTo(bop.getXValue() >> 1);
}

void OpcodeTable::subtractn(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);

    if (bop.getYValue() > bop.getXValue()) {
        bop.setVF();
    } else {
        bop.clearVF();
    }

    bop.setXRegisterTo(bop.getYValue() - bop.getXValue());
}

void OpcodeTable::shiftLeft(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);

    if (bop.getXValue() & 0x80) {
        bop.setVF();
    } else {
        bop.clearVF();
    }
    bop.setXRegisterTo(bop.getXValue() << 1);
}

void OpcodeTable::skipIfRegistersNotEqual(OPCODE command) {
    BinaryOperation bop(sysInfo->cpu.v, command);

    if (bop.getXValue() != bop.getYValue()) {
        sysInfo->cpu.ip += 2;
    }
}

void OpcodeTable::setI(OPCODE command) {
    OPCODE nnn = Opcode::getLastNQuadbits(command, 3);
    sysInfo->cpu.I = nnn;
}

void OpcodeTable::jumpWithOffset(OPCODE command) {
    OPCODE startAddress = sysInfo->cpu.v[0];
    OPCODE offset = Opcode::getLastNQuadbits(command, 3);

    sysInfo->cpu.ip = startAddress + offset;
}

void OpcodeTable::rand(OPCODE command) {
    UnaryOperation uop(sysInfo->cpu.v, command);
    unsigned int randomNumber = distrib(gen);

    uop.setXRegisterTo(randomNumber & uop.getNNValue());
}
