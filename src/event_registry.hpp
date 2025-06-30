#pragma once
class EventHandler {
public:
    virtual ~EventHandler() = default;
    virtual bool handleEvent(const SDL_Event& event) = 0;
    virtual SDL_EventType getEventType() const = 0;
};
class EventManager {
private:
    static std::unordered_map<SDL_EventType, std::unique_ptr<EventHandler>> handlers;
    
public:
    static void registerHandler(SDL_EventType type, std::unique_ptr<EventHandler> handler);
    static void processEvent(const SDL_Event& event);
    static void processEvents();
};

