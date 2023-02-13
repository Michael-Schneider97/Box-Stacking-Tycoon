// the button class used by menus
#ifndef BUTTON_H
#define BUTTON_H

#include "gameObject.h"

class Button : public GameObject
{
    protected:
        bool clickable; 
    public:
        Button();
        void setClickable(bool);
        bool getClickable();
};

#endif

// buttons
// calculate rect for location