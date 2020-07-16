#include <SDL2/SDL.h>
#include <vector>
#include <unordered_set>

#ifndef __event_manager_h
#define __event_manager_h

class EventManager {
    public:
        EventManager() = default;
        EventManager(
            std::unordered_set<SDL_Keycode>& keys,
            std::unordered_set<SDL_EventType>& eventTypes 
        ) : registeredKeys(keys), registeredEvents(eventTypes) {  }

        std::vector<SDL_Event> getEvents();
    private:
        bool isRegisteredKeyEvent(SDL_Event&);
        bool isRegisteredEventType(SDL_Event&);
        std::unordered_set<SDL_Keycode>& registeredKeys;
        std::unordered_set<SDL_EventType>& registeredEvents;
};

#endif
