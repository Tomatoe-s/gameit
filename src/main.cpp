#include <SDL3/SDL.h>
#include <iostream>
#include "window.hpp"
#include "engine.hpp"
int main() {
    try {
        
        Engine Engine("SDL3 Window", 800, 600);

        bool running = true;
        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type){
                    case SDL_EVENT_QUIT:
                        running = false;
                        break;
                    case SDL_EVENT_WINDOW_RESIZED:
                        Engine.onResize(event.window.data1, event.window.data2);
                        break;

                }
            }
SDL_RenderClear(Engine.getRenderer());    
            SDL_SetRenderDrawColor(Engine.getRenderer(), 50, 50, 50, 255);
            float x = 0.0f, y = 0.0f;
            SDL_GetMouseState(&x, &y);
            SDL_SetRenderDrawColor(Engine.getRenderer(), 255, 0, 0, 255);
            SDL_RenderLine(Engine.getRenderer(), 0, 0, static_cast<int>(x), static_cast<int>(y));
            SDL_SetRenderDrawColor(Engine.getRenderer(), 0, 255, 0,255);
            
            SDL_RenderPresent(Engine.getRenderer());  

           
        }

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
