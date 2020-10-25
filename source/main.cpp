#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char **argv) {
    int width = 640, height = 360;

    if (SDL_Init(0) != 0) {
        std::cout << "failed to initialize sdl: " << SDL_GetError() << "\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "ray tracer",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        0
    );
    if (window == NULL) {
        std::cout << "failed to create window: " << SDL_GetError() << "\n";
        return -1;
    }

    bool quit = false;
    const uint8_t *keyboard_state = NULL;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_PumpEvents();
        keyboard_state = SDL_GetKeyboardState(NULL);
        if (keyboard_state[SDL_SCANCODE_ESCAPE]) {
            quit = true;
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}