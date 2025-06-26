#pragma once

#include "events.hpp"
#include "window.hpp"
#include "utilities.hpp"
class Engine : public Window, private events::EventManager {

    public:
    Engine(const std::string& title, int width, int height) : Window(title, width, height) {
        // Initialize the event manager if needed
    }
    registerEvent(SDL_Event event,void (*callback)(void));
    

};