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
#include "OpcodeTable.h"
#include "display/Display.h"
#include "display/EventManager.h"
#include "types.h"
#include "SystemInformation.h"

#ifndef __chip_8
#define __chip_8

class OpcodeTable;

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

        SystemInformation sysInfo;
        OpcodeTable op{&sysInfo};
        Display window;
        EventManager eventManager;
};

#endif
