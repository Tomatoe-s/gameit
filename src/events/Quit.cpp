#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include "../engine.hpp" 
#include "EventRegistry.hpp"

extern bool running;
auto handler = [](const SDL_Event& event) {
    running = false;
    std::cout << "Quit event received. Exiting...\n";
};

EventRegistry reg(SDL_EVENT_QUIT, handler);
