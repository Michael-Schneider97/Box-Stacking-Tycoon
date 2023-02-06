// game object header file
#include "SDL2/SDL.h"
#include <string>
#include <memory>


#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

class gameObject
{
    protected:
        std::unique_ptr<SDL_Rect> collisionRectangle;
        std::unique_ptr<SDL_Texture> texture;
        std::unique_ptr<SDL_Rect> textureRectangle;
        std::shared_ptr<SDL_Renderer> gameRenderer;
        std::string assetFilepath;

    public:
        gameObject();
        
        void setAssetFilePath(std::string);
        void setCollisionRectangle(SDL_Rect&);
        void setTextureRectangle(SDL_Rect&);
        void setTexture(SDL_Texture&);
        void setGameRenderer(SDL_Renderer&);

    // possible implementation:
    // single function takes a string, 2 rects, 
};

#endif