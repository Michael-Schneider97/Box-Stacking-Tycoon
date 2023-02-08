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
        std::unique_ptr<SDL_Texture> texture;
        std::unique_ptr<SDL_Rect> textureRectangle;
        std::shared_ptr<SDL_Renderer> gameRenderer;
        std::string assetFilepath;

    public:
        GameObject();
        GameObject(std::unique_ptr<SDL_Texture>, std::unique_ptr<SDL_Rect>, std::shared_ptr<SDL_Renderer>);

        void draw();
};

#endif