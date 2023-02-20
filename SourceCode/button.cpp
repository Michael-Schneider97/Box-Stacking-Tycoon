#include "button.h"


// default constructor
Button::Button() : GameObject(), quit(false), clickable(true) // clickable is true by default
{
    return;
}

// mutator function for clickability
void Button::setClickable(bool theClickability)
{
    clickable = theClickability;
    return;
}

// mouse handler. Sets color on mouse over, use this in your game loop
void Button::mouseHandler(int mouseX, int mouseY, SDL_Event &input, int &screenWidth, int &screenHeight)
{
    if(mouseOver(mouseX, mouseY) && clickable)
    {
        // set color to be a brighter red
        SDL_SetTextureColorMod(texture.get(), 255, 200, 200);

        // if user clicks, we execute a certain function, provided by the initialization (reconstruction)
        if(input.type == SDL_MOUSEBUTTONDOWN && input.button.button == SDL_BUTTON_LEFT)
        {
            if(!quit)
            {
                buttonFunction(gameRenderer, screenWidth, screenHeight, input);
                return;
            }
            else
            {
                input.type = SDL_QUIT;
                return;
            }
        }
    }
    else 
    {
        // set color back to normal
        SDL_SetTextureColorMod(texture.get(), 255, 255, 255);
    }

    return;
}

// set click execution. allows some action to be executed without cluttering your gameloop
void Button::setClickExecution(buttonFunctionMacro_)
{
    buttonFunction = someButtonFunction;
}

void Button::setQuitButton()
{
    quit = true;
}

bool Button::getQuitButton()
{
    return quit;
}