#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include "../engine.hpp" 
#include "EventRegistry.hpp"
extern bool running;
void handler(const SDL_Event& event) {
        std::cout << "Mouse button down at (" 
                  << event.button.x << ", " 
                  << event.button.y << ")\n";
    
}
EventRegistry rega(SDL_EVENT_MOUSE_BUTTON_DOWN, handler);
