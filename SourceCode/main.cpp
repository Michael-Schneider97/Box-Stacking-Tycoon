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
#include "menu.h"

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
    // start by figuring out the display stuff
    // we need to know whether the user wants fullscreen, windowless, or some size
    // once we know we create the window and setup stuff with it
    const int initialWidth = 800,
              initialHeight = 600;

    const std::string title = "Box Stacking Tycoon (Setup Display)";

    // create a window
    auto theWindow = 
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, initialWidth, initialHeight, NULL), SDL_DestroyWindow);
    
    // create a renderer
    auto theRenderer = 
    std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(theWindow.get(), -1, (SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC)));

    // create a menu 
    Menu graphicMenu(initialWidth, initialHeight, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    graphicMenu.setupTitle();
    graphicMenu.addButton();
    graphicMenu.addButton();
    graphicMenu.addButton();

}

