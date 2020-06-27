/**
 * Max Huddleston
 *
 * Main chip8 header file
 */

#include <iostream>
#include <fstream>
#include <ios>
#include <exception>
#include <array>

#include "cpu.h"
#include "opcode.h"
#include "display/Display.h"

#ifndef __chip_8
#define __chip_8

using mem_t = std::array<unsigned char, 4096>;
using stack_t = std::array<unsigned char, 16>;
using display_t = std::array<unsigned char, 64*32>;
using keys_t = std::array<bool, 16>;
using OpcodeTable = std::array<void(*)(cpu_t&, mem_t&, stack_t&, display_t&, keys_t&), 35>;

class chip8 {
    public:
        /**
         * Initialize the chip8 emulator
         *
         * @param programPath the path to the chip8 program
         */
        chip8(std::string programPath);


        /**
         * Run the chip8 emulator
         */
        void run();

        /**
         * Quit SDL
         */
        ~chip8();

    private:
        void initDisplay();
        void loadProgram(std::string &programPath);
        unsigned short fetchOpcode(unsigned int memaddr);

        cpu_t cpu; 
        mem_t mem; 
        stack_t stack;
        display_t display;
        keys_t keys;
        OpcodeTable op;
        Display window;
};

#endif
