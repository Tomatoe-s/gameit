#pragma once

#include "events.hpp"
#include "window.hpp"
#include "utilities.hpp"

class Engine : public Window, private events::EventManager {

    public:
    Engine(const std::string& title, int width, int height) : Window(title, width, height) {
        // Initialize the event manager if needed
    }
void Engine::triggerEvent(SDL_Event data) {
    EventManager::triggerEvent(data); // Call the base class version

}
void registerEvent(Uint32 type, void (*callback)(SDL_Event)){
    EventManager::registerEvent(type, callback); // Call the base class version
};

};

Engine& getEngine();
inline void registerEvent(uint32_t type, void (*callback)(SDL_Event));