// game object header file
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL2/SDL.h"       // for rects/textures/renderer ptrs
#include <string>           // asset file path 
#include <memory>           // smart pointers used by this class

class GameObject
{
    protected:
        std::unique_ptr<SDL_Rect> collisionRectangle;
        std::unique_ptr<SDL_Texture> texture;
        std::unique_ptr<SDL_Rect> textureRectangle;
        std::shared_ptr<SDL_Renderer> gameRenderer;
        std::string assetFilepath;

    public:
        GameObject();
        GameObject(std::string, SDL_Rect&, SDL_Rect&, SDL_Texture&, SDL_Renderer&);
        
        void setAssetFilePath(std::string);
        void setCollisionRectangle(SDL_Rect&);
        void setTextureRectangle(SDL_Rect&);
        void setTexture(SDL_Texture&);
        void setGameRenderer(SDL_Renderer&);

    // possible implementation:
    // single function takes a string, 2 rects, 
};

#endif