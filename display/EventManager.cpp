#include "EventManager.h"


std::vector<SDL_Event> EventManager::getEvents() {
    std::vector<SDL_Event> events;
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            events.push_back(event);
        }
    }

    return events;
}

bool EventManager::isRegisteredKey(SDL_Event) {
    return false;
}
