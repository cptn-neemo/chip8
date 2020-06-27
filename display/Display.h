#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <functional>
#include "SDLPointer.h"

#ifndef __window_h
#define __window_h

template<typename T>
using SDLPointerDestructor =
    std::function<void(T*)>;

template<typename T>
using SDL_pointer = 
    std::unique_ptr<T, std::function<void(T*)>>;

class Display {
    public: 
        Display();
        ~Display();

    private:
        void initializeSDL();
        void initializeWindow();
        void initializeRenderer();
        SDL_Window *initializeSDLWindowPointer();
        SDL_Renderer *initializeSDLRendererPointer();

        template<typename T>
        void checkForSDLError(T*);

        SDLPointer<SDL_Window> display;
        SDLPointer<SDL_Renderer> renderer;
};

template<typename T>
void Display::checkForSDLError(T* rawPointer) {
    if (rawPointer == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        std::exit(1);
    }
}

#endif
