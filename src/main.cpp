#include <SDL3/SDL.h>
#include <iostream>
#include "window.hpp"
#include "engine.hpp"
#include "events/Quit.hpp"

bool running = true;
Engine& getEngine() {
    static Engine engine("SDL3 Window", 800, 600);  // Initialized on first call
    return engine;
}
int main() {
    try {
        
 Engine& engine = getEngine();
        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                engine.triggerEvent(event);
              
            }
SDL_RenderClear(engine.getRenderer());    
            SDL_SetRenderDrawColor(engine.getRenderer(), 50, 50, 50, 255);
            float x = 0.0f, y = 0.0f;
            SDL_GetMouseState(&x, &y);
            SDL_SetRenderDrawColor(engine.getRenderer(), 255, 0, 0, 255);
            SDL_RenderLine(engine.getRenderer(), 0, 0, static_cast<int>(x), static_cast<int>(y));
            SDL_SetRenderDrawColor(engine.getRenderer(), 0, 255, 0,255);
            
            SDL_RenderPresent(engine.getRenderer());  

           
        }

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
