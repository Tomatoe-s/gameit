#include <SDL3/SDL.h>
#include <iostream>
#include "window.cpp"

int main() {
    try {
        Window Window("SDL3 Window", 800, 600);

        bool running = true;
        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) {
                   running = false;
                }
            }

            SDL_SetRenderDrawColor(Window.getRenderer(), 50, 50, 50, 255);
            SDL_RenderClear(Window.getRenderer());    // ✅ Use renderer
            SDL_RenderPresent(Window.getRenderer());  // ✅ Use renderer

            SDL_Delay(16); // ~60 FPS
        }

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
