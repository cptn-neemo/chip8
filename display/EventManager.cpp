#include "EventManager.h"

std::vector<SDL_Event> EventManager::getEvents() {
    std::vector<SDL_Event> events;
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (isRegisteredKeyEvent(event) && isRegisteredEventType(event))
            events.push_back(event);
    }

    return events;
}

bool EventManager::isRegisteredKeyEvent(SDL_Event& event) {
    return registeredKeys.find(event.key.keysym.sym) != registeredKeys.end();
}

bool EventManager::isRegisteredEventType(SDL_Event& event) {
    return registeredEvents.find(static_cast<SDL_EventType>(event.type)) 
        != registeredEvents.end();
}
