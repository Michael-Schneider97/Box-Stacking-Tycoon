// game object header file
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL2/SDL.h"       // for rects/textures/renderer ptrs
#include <string>           // asset file path 
#include <memory>           // smart pointers used by this class
#include <utility>          // std::move

// a class for all game objects
// used to handle SDL rects, textures, drawing, and so on
class GameObject
{
    protected:
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture;   
        std::unique_ptr<SDL_Rect> textureRectangle;
        SDL_Renderer* gameRenderer;                     // this raw pointer will never be outlived by the memory block it will point to              
        std::string assetFilepath;
        bool drawBackground;
        SDL_Color baseColor;

    public:
        GameObject();
        GameObject(SDL_Renderer &renderer, std::string theFile, int width, int height, int positionX, int positionY);
        GameObject(std::string, SDL_Rect&);
        
        SDL_Rect* getRectangle();
        void draw();
        bool mouseOver(int, int);
    
    private:
        void setupTexture();
};

#endif