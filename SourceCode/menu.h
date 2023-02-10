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
        int buttonSpacing;
        int titleSpacing;

    public:
        Menu();
        void draw();
        void generateRectangles();
};

#endif

// constructor that takes a rect as an argument
// background is setup using game object class
// redefined draw() function which draws all sub objects