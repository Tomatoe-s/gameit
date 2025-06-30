#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include "../engine.hpp" 
#include "../event_registry.hpp"
#include <memory>

extern bool running;
class QuitHandler : public EventHandler {
public:
    bool handleEvent(const SDL_Event& event) override {
        running = false;
        return true;
    }
};
namespace {
    struct EventManagerRegistrar {
        HandlerRegistrar() {
            EventManager::registerHandler(SDL_MOUSEBUTTONDOWN, 
                std::make_unique<MouseHandler>());
        }
    };
    static HandlerRegistrar registerEvent; 
}