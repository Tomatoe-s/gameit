#include "events/EventHandler.hpp"

namespace events {

EventHandler& EventHandler::getInstance() {
    static EventHandler instance;
    return instance;
}

void EventHandler::registerHandler(Uint32 type, HandlerFunc handler) {
    _eventHandlers[type] = handler;
}


void EventHandler::callHandler(const SDL_Event& event) {
    auto it = _eventHandlers.find(event.type);
    if (it != _eventHandlers.end()) {
        it->second(event);
    } 
    
}

} // namespace events
