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
    // 3XNN 
    unsigned char registerIndex = Opcode::getXRegister(command);
    OPCODE registerValue = sysInfo->cpu.v[registerIndex];
    OPCODE value = Opcode::getLastNQuadbits(command, 2);

    skipNextInstructionIf(registerValue == value);
}

void OpcodeTable::skipIfRegisterNotEqualToConstant(OPCODE command) {
    unsigned char registerIndex = Opcode::getXRegister(command);
    OPCODE registerValue = sysInfo->cpu.v[registerIndex];
    OPCODE value = Opcode::getLastNQuadbits(command, 2);

    skipNextInstructionIf(registerValue != value);
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
    unsigned char registerIndex = Opcode::getXRegister(command);
    OPCODE constant = Opcode::getLastNQuadbits(command, 2);
    setRegister(registerIndex, constant);
}

void OpcodeTable::addConstantToRegister(OPCODE command) {
    unsigned char registerIndex = Opcode::getXRegister(command);
    OPCODE registerValue =
        sysInfo->cpu.v[registerIndex];
    OPCODE constant = Opcode::getLastNQuadbits(command, 2);
    setRegister(registerIndex, registerValue + constant);
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

void OpcodeTable::setRegister(unsigned char registerIndex, OPCODE value) {
    sysInfo->cpu.v[registerIndex] = value;
}
