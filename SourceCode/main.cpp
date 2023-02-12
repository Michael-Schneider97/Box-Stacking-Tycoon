/*
 * File: main.cpp
 * Author: Michael Schneider
 * Date: February 5, 2023
 * Purpose: Contains main() entry point of this program
 */

#include <cstdlib>      // just wanted to be included
#include <iostream>     // cin cout
#include <fstream>      // used to load images from assets folder
#include <SDL2/SDL.h>   // its for.... yknow, sdl
#include <string>       // strings 
#include <vector>       // vectors used by menu class and stack / list systems
#include <memory>

void mainMenuFunction();

int main()
{
    // initialize sdl
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Loaded SDL Successfully\n";
    }
    
    // call handler which takes us to the menu
    mainMenuFunction();
    
    // put your things away         
    SDL_Quit();
    return 0;
}

// we bouta menu it up boiiii
void mainMenuFunction()
{
    // variables
    const std::string title = "Box Stacking Tycoon (Setup Display)";
    int screenWidth = 0, screenHeight = 0;

    // get window size
    SDL_DisplayMode displayMode;
    if(SDL_GetDesktopDisplayMode(0, &displayMode) != 0)
    {
        std::cout << "display mode call fail\n";
        return;
    }

    // create a window
    auto theWindow = 
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w, displayMode.h, SDL_WINDOW_RESIZABLE), SDL_DestroyWindow);
    SDL_MaximizeWindow(theWindow.get());

    // create a renderer
    auto theRenderer = 
    std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(theWindow.get(), -1, (SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC)), SDL_DestroyRenderer);
    SDL_GetRendererOutputSize(theRenderer.get(), &screenWidth, &screenHeight);

    int i = 0;
    while(i < 1000)
    {
        i++;
        SDL_RenderPresent(theRenderer.get());
    }

}

