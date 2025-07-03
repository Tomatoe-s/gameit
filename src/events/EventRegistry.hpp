#pragma once
#include <SDL3/SDL.h>
#include <functional>
#include "EventHandler.hpp"
struct EventRegistry {
    EventRegistry(Uint32 event, const events::EventHandler::HandlerFunc& handler){
        events::EventHandler::getInstance().registerHandler(event, handler);
    }
};
