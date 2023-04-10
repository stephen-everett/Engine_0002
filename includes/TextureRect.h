#ifndef TEXTURERECT_H
#define TEXTURERECT_H
#include <SDL2/SDL.h>

struct TextureRect
{
    const char * texturePath;
    int textureIndex;
    double angle = 0;
    SDL_Texture * texture;
    SDL_Rect dimensions;
    SDL_Rect drawRect;
    bool enabled = true;
    int pathX;
    int pathY;

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
        this->enabled = enabled;
    }
};

#endif
