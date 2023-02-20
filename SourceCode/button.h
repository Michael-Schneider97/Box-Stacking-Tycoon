// the button class used by menus
#ifndef BUTTON_H
#define BUTTON_H

#include "gameObject.h"
// macro used to allow flexible adjustment of function paradigm for games and UI
#define buttonFunctionMacro_ void (&someButtonFunction)(SDL_Renderer *theGameRenderer, int &screenWidth, int &screenHeight, SDL_Event &input)

class Button : public GameObject
{
    protected:
        bool clickable; 
        void (*buttonFunction)(SDL_Renderer *renderer, int &screenWdith, int &screenHeight, SDL_Event &input);
        bool quit;
        // note: should we use a unique ptr or will this not really create a memory leak
    public:
        Button();
        void setClickable(bool);
        bool getClickable();
        void setQuitButton();
        bool getQuitButton();
        void mouseHandler(int mouseX, int mouseY, SDL_Event &input, int &screenWidth, int &screenHeight);
        void setClickExecution(buttonFunctionMacro_);
};

#endif

// buttons
// calculate rect for location