// implementation file for game object class

#include "gameObject.h"

// default constructor
GameObject::GameObject()
{
    // we leave the pointers as empty and set them later
    assetFilepath = "";
    return;
}

// premade texture constructor (same collision hitbox)
GameObject::GameObject(std::unique_ptr<SDL_Texture> theObjectTexture, std::unique_ptr<SDL_Rect> uniqueRect, std::shared_ptr<SDL_Renderer> theRenderer)
{
    // i dont really know how to use smart pointers...
    // question: is an exception possible here?
    texture = std::move(theObjectTexture);
    textureRectangle = std::move(uniqueRect);
    gameRenderer = theRenderer;
    return;
}


// menu is a game object
// each button is a game object
// a game object has a collision box,
//                     visual box,
//                     string filepath,
//                     reference to the renderer
//                     texture reference