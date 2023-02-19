// Note: Inclusion of SDL_image will allow refactoring of the setup texture function to be a bit more optimized
#include "gameObject.h"
#include <iostream>

// default constructor
GameObject::GameObject() : texture(nullptr, SDL_DestroyTexture), baseColor {0, 0, 0, 255}, drawBackground {false}, gameRenderer {NULL}
{
    assetFilepath = "";
    return;
}

// constructor that uses a string and some ints 
GameObject::GameObject(SDL_Renderer *renderer, std::string theFile, int width, int height, int positionX, int positionY) : texture(nullptr, SDL_DestroyTexture)
{
    initialize(renderer, theFile, width, height, positionX, positionY);
    return;
}

// Initializers. Used for cases where constructors cant easily be called or when an object needs to be updated in some way
void GameObject::initialize(SDL_Renderer *renderer, std::string theFile, int width, int height, int positionX, int positionY) 
{
    // file path
    assetFilepath = theFile;

    // rect
    textureRectangle = std::make_unique<SDL_Rect>();
    textureRectangle.get()->h = height;
    textureRectangle.get()->w = width;
    textureRectangle.get()->x = positionX;
    textureRectangle.get()->y = positionY;

    // renderer
    gameRenderer = renderer;

    // setup the texture
    setupTexture();

    return;
}

void GameObject::initialize(SDL_Renderer *renderer, std::string theFile)
{
    // file path
    assetFilepath = theFile;

    // rect
    textureRectangle = std::make_unique<SDL_Rect>();

    // renderer
    gameRenderer = renderer;

    // texture
    setupTexture();

    return;
}

// put the object on the screen
void GameObject::draw()
{
    // possible case for try/throw/catch here?
    if(texture && textureRectangle && gameRenderer)
    {
        SDL_RenderCopy(gameRenderer, texture.get(), NULL, textureRectangle.get());
    }

    // use some color as background
    else if (textureRectangle && gameRenderer)
    {
        SDL_SetRenderDrawColor(gameRenderer, baseColor.r, baseColor.g, baseColor.b, baseColor.a);
        std::cout << "null texture detected\n";
    }

    else 
    {
        std::cout << "Draw error\n";
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
    // initialize 
    auto tempSurface = // we pass the SDL delete function and a function that returns a pointer
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>(SDL_LoadBMP(assetFilepath.c_str()), SDL_FreeSurface);

    if(tempSurface.get())
    {
        drawBackground = true;
        auto tempTexture = // we convert the temp surface to a texture
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>(SDL_CreateTextureFromSurface(gameRenderer, tempSurface.get()), SDL_DestroyTexture);
        // smart pointer takes ownership of the texture
        texture = std::move(tempTexture);
        return;
    }

    drawBackground = false;
    return;
}

// utilities
// returns true if mouse is inside the rect of the game object
bool GameObject::mouseOver(int mouseX, int mouseY)
{
    return (
            mouseX >= textureRectangle.get()->x && mouseX <= textureRectangle.get()->x + textureRectangle.get()->w && 
            mouseY >= textureRectangle.get()->y && mouseY <= textureRectangle.get()->y + textureRectangle.get()->h
        );
}