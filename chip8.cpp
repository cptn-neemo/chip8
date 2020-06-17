#include "chip8.h"

chip8::chip8(std::string programPath) {
    mem.fill(0);
    stack.fill(0);
    initDisplay();
    loadProgram(programPath);
    run();
}

void chip8::initDisplay() {
    display.fill(0);
}

void chip8::loadProgram(std::string &programPath) {
    std::cout << "Loading program " 
        << programPath 
        << " into memory..." 
        << std::endl;
    
    std::fstream fs(programPath, std::fstream::in | std::fstream::binary);

    if (fs.fail()) {
        throw std::invalid_argument("Could not open program.");
    }

    unsigned char byte;
    unsigned int memaddr = 0x0200;

    while (!fs.eof()) {
        fs.read((char*) &byte, 1);
        mem[memaddr++] = byte;
    }

    std::cout << std::hex << (int) mem[0x0200] << "-" << std::hex << mem[0x0201] << std::endl;
    std::cout << "Successfully loaded program." << std::endl;
}

unsigned short chip8::fetchOpcode(unsigned int memaddr) {
    return (mem[memaddr] << 8) | mem[memaddr + 1];
}

void chip8::run() {
}

int main() {
    chip8 c("test_opcode.ch8");
}
