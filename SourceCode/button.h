// the button class used by menus
#ifndef BUTTON_H
#define BUTTON_H

#include "gameObject.h"

class Button : public GameObject
{
    protected:
        bool clickable; 
        void (&buttonFunction)(SDL_Renderer *renderer, int &screenWdith, int &screenHeight);
    public:
        Button();
        void setClickable(bool);
        bool getClickable();
        void mouseHandler(int mouseX, int mouseY);
        void setClickExecution(void (&theButtonFunction)(SDL_Renderer *renderer, int &screenWidth, int &screenHeight));
};

#endif

// buttons
// calculate rect for location