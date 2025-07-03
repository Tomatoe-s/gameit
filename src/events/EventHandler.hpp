#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>
#include <functional>
#include <iostream>

namespace events {

class EventHandler {
public:
    using HandlerFunc = std::function<void(const SDL_Event&)>;

    static EventHandler& getInstance();

    void registerHandler(Uint32 type, HandlerFunc handler);
    void callHandler(const SDL_Event& event);

private:
    std::unordered_map<Uint32, HandlerFunc> _eventHandlers;
    EventHandler() = default;
};

} 
