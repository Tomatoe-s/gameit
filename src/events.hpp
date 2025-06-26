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
std::unordered_map<EventType, std::vector<void (*)(void)>> event_map;
class EventManager {
public:
    
    void registerEvent(EventType type, void (*callback)(void)) {
        event_map[type].push_back(callback);
    }

    void triggerEvent(EventType type) {
        if (event_map.find(type) != event_map.end()) {
            for (auto& callback : event_map[type]) {
                callback();
            }
        }
    }

    void clearEvents() {
        event_map.clear();
    }
    bool hasEvent(EventType type) const {
        return event_map.find(type) != event_map.end() && !event_map.at(type).empty();
    }
};

}