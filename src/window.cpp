#include <SDL3/SDL.h>
#include <string>
#include <stdexcept>

class Window {
public:
    Window(const std::string& title, int width, int height) {

    SDL_Init(SDL_INIT_VIDEO);
    

        // Assign directly to the class member
    if (SDL_CreateWindowAndRenderer(title.c_str(), width, height, SDL_WINDOW_RESIZABLE, &window_, &renderer_) != 1) {

        throw std::runtime_error("Failed to create window");
    }
        
    }

    ~Window() {
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }
    
    SDL_Window* getWindow() const {
        return window_;
    }
    SDL_Renderer* getRenderer() const {
        return renderer_;
    }

private:
SDL_Renderer* renderer_;
    SDL_Window* window_;
};
