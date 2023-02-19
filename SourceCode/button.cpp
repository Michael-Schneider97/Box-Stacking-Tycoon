#include "button.h"

// default constructor
Button::Button() : GameObject(), clickable(true) // clickable is true by default
{

}

// mutator function for clickability
void Button::setClickable(bool theClickability)
{
    clickable = theClickability;
    return;
}

// mouse handler. Sets color on mouse over, use this in your game loop
void Button::mouseHandler(int mouseX, int mouseY)
{
    if(mouseOver(mouseX, mouseY) && clickable)
    {
        // set color to be a brighter red
        SDL_SetTextureColorMod(texture.get(), 255, 200, 200);

        // if user clicks, we execute a certain function, provided by the initialization (reconstruction)
    }
    else 
    {
        // set color back to normal
        SDL_SetTextureColorMod(texture.get(), 255, 255, 255);
    }
}

// set click execution. allows some action to be executed without cluttering your gameloop