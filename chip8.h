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
#include "display/KeyConverter.h"
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
        void handleEvents();

        SystemInformation sysInfo;
        OpcodeTable op{&sysInfo};
        Display window;
        EventManager eventManager;

        bool quitFlag{false};

        std::unordered_set<SDL_Keycode> registeredKeys {
            SDLK_1,
            SDLK_2,
            SDLK_3,
            SDLK_4,
            SDLK_q,
            SDLK_w,
            SDLK_e,
            SDLK_r,
            SDLK_a,
            SDLK_s,
            SDLK_d,
            SDLK_f,
            SDLK_z,
            SDLK_x,
            SDLK_c,
            SDLK_v,
            SDLK_ESCAPE
        };

        std::unordered_set<SDL_EventType> registeredEvents {
            SDL_KEYDOWN,
            SDL_KEYUP,
            SDL_QUIT
        };

};

#endif
