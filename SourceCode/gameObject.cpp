// Note: Inclusion of SDL_image will allow refactoring of the setup texture function to be a bit more optimized
#include "gameObject.h"

// default constructor
GameObject::GameObject() : texture(nullptr, SDL_DestroyTexture)
{
    // we leave the pointers as empty and set them later
    assetFilepath = "";
    return;
}

// constructor that uses a string and some ints 
GameObject::GameObject(std::string theFile, int width, int height, int positionX, int positionY) : texture(nullptr, SDL_DestroyTexture)
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
    // initialize 
    auto tempSurface = // we pass the SDL delete function and a function that returns a pointer
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>(SDL_LoadBMP(assetFilepath.c_str()), SDL_FreeSurface);

    if(tempSurface.get())
    {
        auto tempTexture = // we convert the temp surface to a texture
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>(SDL_CreateTextureFromSurface(gameRenderer.get(), tempSurface.get()), SDL_DestroyTexture);
        // smart pointer takes ownership of the texture
        texture = std::move(tempTexture);
        return;
    }

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