// implementation file for game object class

#include "gameObject.h"

// default constructor
GameObject::GameObject()
{
    // we leave the pointers as empty and set them later
    assetFilepath = "";
    return;
}

// constructor using a premade texture and rect 
GameObject::GameObject(std::unique_ptr<SDL_Texture> theObjectTexture, std::unique_ptr<SDL_Rect> uniqueRect, std::shared_ptr<SDL_Renderer> theRenderer)
{
    // i dont really know how to use smart pointers...
    // question: is an exception possible here?
    texture = std::move(theObjectTexture);
    textureRectangle = std::move(uniqueRect);
    gameRenderer = theRenderer;
    return;
}

void GameObject::draw()
{
    // possible case for try/throw/catch here?
    if(texture && textureRectangle)
    {
        SDL_RenderCopy(gameRenderer.get(), texture.get(), NULL, textureRectangle.get());
    }
    return;
}