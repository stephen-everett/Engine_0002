#ifndef TEXTURERECT_H
#define TEXTURERECT_H
#include <SDL2/SDL.h>

struct TextureRect
{
    const char* tag;
    SDL_Texture * texture;
    SDL_Rect dimensions;
};

#endif
