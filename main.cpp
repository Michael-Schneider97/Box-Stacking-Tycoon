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