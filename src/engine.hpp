#pragma once

#include "events/EventHandler.hpp"
#include "window.hpp"
#include "utilities.hpp"


class Engine : public Window {
public:
    Engine(const std::string& title, int width, int height)
        : Window(title, width, height) {
        // You can register events here if you like
    }

    void triggerEvent(const SDL_Event& data) {
        events::EventHandler::getInstance().callHandler(data);
    }

    void registerEvent(Uint32 type, events::EventHandler::HandlerFunc callback) {
        events::EventHandler::getInstance().registerHandler(type, callback);
    }
};
