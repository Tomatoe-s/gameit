#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include "../engine.hpp" 
#include "../event_registry.hpp"
extern bool running;
class MouseHandler : public EventHandler {
public:
    bool handleEvent(const SDL_Event& event) override {
        std::cout << "Mouse event triggered: " << event.type << std::endl;
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