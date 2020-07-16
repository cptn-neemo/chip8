#include "chip8.h"

chip8::chip8(std::string programPath) {
    sysInfo.mem.fill(0);
    sysInfo.stack.fill(0);
    initDisplay();
    loadProgram(programPath);
    run();
}

chip8::~chip8() {
    SDL_Quit();
}

void chip8::initDisplay() {
    sysInfo.display.fill(0);
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
        sysInfo.mem[memaddr++] = byte;
    }

    std::cout << "Successfully loaded program." << std::endl;
}

unsigned short chip8::fetchOpcode(unsigned int memaddr) {
    return (sysInfo.mem[memaddr] << 8) | sysInfo.mem[memaddr + 1];
}

void chip8::run() {
    while (true) {
        std::vector<SDL_Event> events = eventManager.getEvents();

        if (events.size() > 0) {
            for (SDL_Event& ev : events) {
                if (ev.type == SDL_KEYDOWN)
                    std::cout << "key down" << std::endl;
                else
                    std::cout << "key up" << std::endl;

                if (ev.type == SDL_QUIT)
                    break;
            }
        }
    }
}

int main() {
    chip8 c("test_opcode.ch8");
}
