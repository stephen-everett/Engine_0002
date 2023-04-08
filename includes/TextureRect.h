#ifndef TEXTURERECT_H
#define TEXTURERECT_H
#include <SDL2/SDL.h>

struct TextureRect
{
    const char * texturePath;
    int textureIndex;
    SDL_Texture * texture;
    SDL_Rect dimensions;

    TextureRect(){}
    TextureRect(const char* path, int index, int x, int y, int w, int h)
    {
        texturePath = path;
        textureIndex = index;
        texture = NULL;
        dimensions.x = x;
        dimensions.y = y;
        dimensions.w = w;
        dimensions.h = h;
    }
};

#endif
