#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include "../engine.hpp" 

Engine& getEngine();
extern bool running;

inline void quitEventHandler(SDL_Event event) {
    std::cout << "Quit event triggered\n";
    running = false;
}

struct QuitEventRegistrar {
    QuitEventRegistrar() {
        getEngine().registerEvent(SDL_EVENT_QUIT, quitEventHandler);
    }
};

static QuitEventRegistrar _quitEventRegistrar;
