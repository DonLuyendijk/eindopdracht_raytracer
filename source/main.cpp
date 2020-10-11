#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char **argv) {
    if (SDL_Init(0) != 0) {
        std::cout << "failed to initialize sdl\n";
        return -1;
    }
    
    std::cout << "hello world\n";
    
    return 0;
}