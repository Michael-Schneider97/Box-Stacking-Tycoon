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
        // hand the ptrs the sdl destructors
        std::unique_ptr<SDL_Texture> texture;
        std::unique_ptr<SDL_Rect> textureRectangle;
        std::shared_ptr<SDL_Renderer> gameRenderer;
        std::string assetFilepath;

    public:
        GameObject();
        GameObject(std::unique_ptr<SDL_Texture>, std::unique_ptr<SDL_Rect>, std::shared_ptr<SDL_Renderer>);
        GameObject(std::string, int, int, int, int);
        GameObject(std::string, SDL_Rect&);
        
        SDL_Rect* GameObject::getRectangle();
        void draw();
    
    private:
        void GameObject::setupTexture();
};

#endif

// how objects are made
// we take a string referencing a file
// we use that to create a surface
// we convert the surface to a texture
// we destroy the surface
// we pass a reference to that texture as well as one to the corresponding rect we use
