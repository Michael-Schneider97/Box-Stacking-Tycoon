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

// constructor that uses a string and some ints 
GameObject::GameObject(std::string theFile, int width, int height, int positionX, int positionY)
{
    // setup the filepath
    assetFilepath = theFile;

    // setup the rect
    textureRectangle = std::make_unique<SDL_Rect>();
    textureRectangle.get()->h = height;
    textureRectangle.get()->w = width;
    textureRectangle.get()->x = positionX;
    textureRectangle.get()->y = positionY;

    // setup the texture
    setupTexture();
}

// put the object on the screen
void GameObject::draw()
{
    // possible case for try/throw/catch here?
    if(texture && textureRectangle)
    {
        SDL_RenderCopy(gameRenderer.get(), texture.get(), NULL, textureRectangle.get());
    }
    return;
}

// accessor functions
SDL_Rect* GameObject::getRectangle()
{
    return textureRectangle.get();
}

void GameObject::setupTexture()
{
    std::unique_ptr<SDL_Surface> tempSurface(SDL_LoadBMP(assetFilepath.c_str()), SDL_FreeSurface());
    if(tempSurface)
    {
        texture = std::make_unique(SDL_CreateTextureFromSurface(gameRenderer.get(), tempSurface.get()));
    }
}

// go over this entire file,
// adjust the unique_ptr usages