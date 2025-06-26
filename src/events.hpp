#pragma once
#include <unordered_map>
#include <vector>
namespace events {
enum class EventType {
    Mouse_Motion,
    Mouse_Button_Down,
    Mouse_Button_Up,
    Mouse_Wheel,
    Key_Down,
    Key_Up,
    Text_Input,
    Text_Editing,
    Window_Resize,
    Window_Close,
    Window_Focus_Gained,
    Window_Focus_Lost,
    Window_Minimized,
    Window_Maximized,
    Window_Restore,
    Window_Move,
    Window_Enter,
    Window_Leave,
    Quit,
    User_Event,
    Touch_Finger_Down,
    Touch_Finger_Up,
    Touch_Finger_Motion,
    Pen_Proximity,
    Pen_Touch,
    Pen_Leave,
    Pen_Button_Down,
    Pen_Button_Up

};
class EventManager {
    public:
    EventManager() = default;
    ~EventManager() {
        clearEvents();
    }
    void registerEvent(Uint32 type, void (*callback)(SDL_Event)) {
        std::cout << "Registering event type: " << type << std::endl;
        event_map[type].push_back(callback);
    }

    void triggerEvent(SDL_Event data) {
        std::cout << "Event triggered: " << data.type << std::endl;
        // Check if the event type exists in the map and call all registered callbacks
        if (event_map.find(data.type) != event_map.end()) {
            std::cout << "Callbacks found for event type: " << data.type << std::endl;
            for (auto& callback : event_map[data.type]) {
                std::cout << "Calling callback for event type: " << data.type << std::endl;
                callback(data);
            }
        }
    }

    private:
    
    void clearEvents() {
        event_map.clear();
    }
    bool hasEvent(SDL_Event type) const {
        return event_map.find(type.type) != event_map.end() && !event_map.at(type.type).empty();
    }
    std::unordered_map<Uint32, std::vector<void (*)(SDL_Event)>> event_map;

};

}