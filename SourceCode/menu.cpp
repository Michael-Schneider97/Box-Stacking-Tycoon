// the menu class, which uses SDL2 to create a framework for a menu based system 

#include "menu.h"

// defualt constructor
Menu::Menu() : GameObject()
{
    assetFilepath = "";
}

// parameterized constructor
Menu::Menu(std::string filePath, int width, int height, int x, int y) : GameObject(filepath, width, height, x, y)
{
    assetFilepath = filePath;
}

// constructor that just stores the background as a solid color
Menu::Menu(int width, int height, int x, int y) : GameObject("", width, height, x, y)
{
    
}

// automatic button & title placement
void autoGenerateMenu()
{

}

// redefined draw
void draw()
{

}

// button stuff
void setupTitle()
{

}

void addButton()
{

}