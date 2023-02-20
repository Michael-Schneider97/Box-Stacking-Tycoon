// the menu class, which uses SDL2 to create a framework for a menu based system 

#include "menu.h"
#include <iostream>

// defualt constructor
Menu::Menu() : GameObject()
{
    assetFilepath = "";
}

// parameterized constructor
// takes arguments to load texture and create rect using gameobj constructor
Menu::Menu(SDL_Renderer *renderer, std::string filePath, int width, int height, int x, int y) : GameObject(renderer, filePath, width, height, x, y)
{
    assetFilepath = filePath;
    return;
}

// constructor that just stores the background as a solid color
Menu::Menu(SDL_Renderer *renderer, int width, int height, int x, int y, SDL_Color color) : GameObject(renderer, "", width, height, x, y)
{
    return;
}

// automatic button & title placement
void Menu::autoGenerate(int screenWidth, int screenHeight)
{
    // used to calculate rect widths and heights
    int titleWidthPercent, titleAspect, titleWidth, titleHeight, titleBuffer;

    titleWidthPercent = 20;
    titleAspect = 3;

    titleWidth = screenWidth * titleWidthPercent / 100;
    titleHeight = titleWidth / titleAspect;
    titleBuffer = titleHeight;

    title.getRectangle()->y = titleBuffer;
    title.getRectangle()->w = titleWidth;
    title.getRectangle()->h = titleHeight;
    title.getRectangle()->x = (screenWidth / 2) - (titleWidth / 2);

}

// redefined draw
void Menu::draw()
{
    GameObject::draw();
    
    title.draw();
    
    for(long unsigned int i = 0; i < buttonList.size(); i++)
    {
        buttonList[i].draw();
    }
    return;
}

// button stuff
void Menu::addTitle(SDL_Renderer *renderer, std::string theFile, int width, int height, int positionX, int positionY)
{
    title.initialize(renderer, theFile, width, height, positionX, positionY);
    return;
}

void Menu::addTitle(SDL_Renderer *renderer, std::string theFile)
{
    title.initialize(renderer, theFile); 
    return;
}

void Menu::addButton(SDL_Renderer *renderer, std::string theFile, buttonFunctionMacro_)
{
    Button button;
    button.initialize(renderer, theFile);
    button.setClickExecution(someButtonFunction);
    buttonList.push_back(button);
    return;
}

void Menu::addButton(SDL_Renderer *renderer, std::string theFile, bool isQuit)
{
    Button button;
    button.initialize(renderer, theFile);
    button.setQuitButton();
    buttonList.push_back(button);
    return;
}