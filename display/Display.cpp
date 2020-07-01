#include "Display.h"

Display::Display() {
    initializeSDL();
    initializeWindow();
    initializeRenderer();
}

Display::~Display() {
    SDL_Quit();
}

void Display::initializeSDL() {
    int sdlInitCode = SDL_Init(SDL_INIT_VIDEO);
    if (sdlInitCode != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }
}

void Display::initializeWindow() { 
    SDL_Window *rawDisplayPointer = initializeSDLWindowPointer();
    display = SDLPointer<SDL_Window>(rawDisplayPointer, &SDL_DestroyWindow);
}

SDL_Window* Display::initializeSDLWindowPointer() {
    SDL_Window *window = SDL_CreateWindow("Hello, World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    checkForSDLError(window);
    return window;
}

void Display::initializeRenderer() {
    SDL_Renderer *rawRendererPointer = initializeSDLRendererPointer();
    renderer = SDLPointer<SDL_Renderer>(rawRendererPointer, &SDL_DestroyRenderer);
}

SDL_Renderer* Display::initializeSDLRendererPointer() {
    SDL_Renderer *rawRendererPointer = SDL_CreateRenderer(
        display, 
        -1,
        SDL_RENDERER_ACCELERATED
    );
    checkForSDLError(rawRendererPointer);
    return rawRendererPointer;
}
