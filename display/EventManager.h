#include <SDL2/SDL.h>
#include <vector>
#include <map>

#ifndef __event_manager_h
#define __event_manager_h

class EventManager {
    public:
 //       EventManager(std::vector<SDLKey>& keys) : registeredKeys(keys) {  }
        std::vector<SDL_Event> getEvents();
    private:
        bool isRegisteredKey(SDL_Event);

};

#endif
