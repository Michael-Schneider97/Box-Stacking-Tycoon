// game object header file
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL2/SDL.h"       // for rects/textures/renderer ptrs
#include <string>           // asset file path 
#include <memory>           // smart pointers used by this class
#include <utility>          // std::move

class GameObject
{
    protected:
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture;    // passing SDL destructor to the pointer
        std::unique_ptr<SDL_Rect> textureRectangle;
        SDL_Renderer &gameRenderer;                             // this could be a raw ptr or reference since it wont be deleted before this object is
        std::string assetFilepath;
        bool drawBackground;
        SDL_Color baseColor;

    public:
        GameObject();
        GameObject(std::string, int, int, int, int);
        GameObject(std::string, SDL_Rect&);
        
        SDL_Rect* getRectangle();
        void draw();
        bool mouseOver(int, int);
    
    private:
        void setupTexture();
};

#endif

// how objects are made
// we take a string referencing a file
// we use that to create a surface
// we convert the surface to a texture
// we destroy the surface
// we pass a reference to that texture as well as one to the corresponding rect we use
