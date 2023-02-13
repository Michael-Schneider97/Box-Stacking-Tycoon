// header for window class
#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include <memory>

class Window
{
    protected:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::unique_ptr<int> width, height;

    public:
        Window();
        Window(int, int);
};

#endif