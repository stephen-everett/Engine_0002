#ifndef TEXTURERECT_H
#define TEXTURERECT_H
#include <SDL2/SDL.h>

struct TextureRect
{
    const char * texturePath;
    int textureIndex;
    SDL_Texture * texture;
    SDL_Rect dimensions;
};

#endif
