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
    // variables
    // strings used for filepaths
    const std::string title = "Box Stacking Tycoon (Setup Display)",
                      menuBackground = "../Assets/mainMenuBackground.bmp",
                      mainMenuPlayButton = "../Assets/assets/menus/main/playBoxesButton.bmp",
                      mainMenuStatsButton = "../Assets/assets/menus/main/statsButton.bmp",
                      mainMenuQuitButton = "../Assets/assets/menus/main/quitButton.bmp",
                      titleFileLocation = "../Assets/mainMenuTitle.bmp";
    
    int screenWidth = 0, screenHeight = 0, mousePositionX = 0, mousePositionY = 0;
    bool quit = false;
    SDL_Color black = {0, 0, 0, 255};
    SDL_Event userInput;

    // get screen size
    SDL_DisplayMode displayMode;
    if(SDL_GetDesktopDisplayMode(0, &displayMode) != 0)
    {
        std::cout << "display mode call fail\n";
        return;
    }

    // create a window
    auto theWindow = 
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w, displayMode.h, SDL_WINDOW_RESIZABLE), SDL_DestroyWindow);
    // For some reason the above function call does not really center the window, so the next one moves it to where it actually should go
    // Yes, I know this is hacky but hey, it works
    SDL_MaximizeWindow(theWindow.get());
    SDL_GetDesktopDisplayMode(0, &displayMode);

    // create a renderer
    auto theRenderer = 
    std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(theWindow.get(), -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)), SDL_DestroyRenderer);
    SDL_GetRendererOutputSize(theRenderer.get(), &screenWidth, &screenHeight);

    // create the menu
    Menu mainMenu(theRenderer.get(), menuBackground, screenWidth, screenHeight, 0, 0);

    // title and buttons
    mainMenu.addTitle(theRenderer.get(), titleFileLocation);
    mainMenu.addButton(theRenderer.get(), mainMenuPlayButton);
    mainMenu.addButton(theRenderer.get(), mainMenuStatsButton);
    mainMenu.addButton(theRenderer.get(), mainMenuQuitButton);
    mainMenu.autoGenerate(screenWidth, screenHeight);

    //mainMenu.addButton();
    //mainMenu.addButton();
    
    do
    {
        SDL_GetMouseState(&mousePositionX, &mousePositionY);
        mainMenu.draw();
        SDL_RenderPresent(theRenderer.get());
        while(SDL_PollEvent(&userInput))
        {
            if(userInput.type == SDL_QUIT)
            {
                quit = true;
            }
        }

    } while (!quit);
}

