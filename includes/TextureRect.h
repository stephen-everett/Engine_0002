#ifndef TEXTURERECT_H
#define TEXTURERECT_H
#include <SDL2/SDL.h>

struct TextureRect
{
    //used by Render System
    const char * texturePath;
    double angle = 0;
    SDL_Texture * texture; // Shared with ResourceManager
    SDL_Rect dimensions;
    SDL_Rect drawRect;
    SDL_Point rotationPoint;
    bool enabled = true;

    //used for pathing
    int pathX;
    int pathY;

    // used by Resource Manager
    int textureIndex;
    
    // used by Collider System
    int colliderTag;
    bool isCollided = false;
    int collisionCount = 0;
    SDL_Rect colliderRect;

    TextureRect()
    {
        texturePath = NULL;
        textureIndex = 0;
        double angle = 0;
        texture = NULL;

    }
    TextureRect(const char* path, int index, int x, int y, int w, int h)
    {
        texturePath = path;
        textureIndex = index;
        texture = NULL;
        double angle = 0;
        dimensions.x = x;
        dimensions.y = y;
        dimensions.w = w;
        dimensions.h = h;
        rotationPoint.x = (w+x) / 2;
        rotationPoint.y = (y+h) / 2;
    }

    TextureRect(const char* path, int index, int x, int y, int w, int h,bool enabled)
    {
        texturePath = path;
        textureIndex = index;
        texture = NULL;
        double angle = 0;
        dimensions.x = x;
        dimensions.y = y;
        dimensions.w = w;
        dimensions.h = h;
        colliderRect.w = w;
        colliderRect.h = h;
        this->enabled = enabled;
        rotationPoint.x = (w+x) / 2;
        rotationPoint.y = (y+h) / 2;
    }
};

#endif
