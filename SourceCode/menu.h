// header file for the menu class

#ifndef MENU_H
#define MENU_H

#include "gameObject.h"
#include "button.h"
#include <vector>           // used to store the buttons

class Menu : public GameObject
{
    protected:
        GameObject title;
        std::vector<Button> buttonList;

    public:
        Menu();
        Menu(SDL_Renderer *renderer, std::string filePath, int width, int height, int x, int y);
        Menu(SDL_Renderer *renderer, int width, int height, int x, int y, SDL_Color color);
        void draw();
        void generateRectangles();
        void addTitle(SDL_Renderer *renderer, std::string theFile);
        void addTitle(SDL_Renderer *renderer, std::string theFile, int width, int height, int positionX, int positionY);
        void addButton(SDL_Renderer *renderer, std::string theFile);
        void autoGenerate(int screenWidth, int screenHeight);
};

#endif

// constructor that takes a rect as an argument
// background is setup using game object class
// redefined draw() function which draws all sub objects