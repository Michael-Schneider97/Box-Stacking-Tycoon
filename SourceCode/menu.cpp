// the menu class, which uses SDL2 to create a framework for a menu based system 

#include "menu.h"

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
    
}

// automatic button & title placement
void Menu::autoGenerate()
{

}

// redefined draw
void Menu::draw()
{
    GameObject::draw();
    
    title.draw();
    
    for(int i = 0; i < buttonList.size(); i++)
    {
        buttonList[i].draw();
    }
    return;
}

// button stuff
void Menu::addTitle()
{
    title.getRectangle()->h = 10;
}

void Menu::addButton()
{

}