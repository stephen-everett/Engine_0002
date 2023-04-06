#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <vector>
#include <SDL2/SDL.h>
#include "Asset.h"
#include "TextureRect.h"
#include "EventBus.h"
#include "BusNode.h"
#include "Structs.h"

class RenderSystem : BusNode
{
    public:
        RenderSystem();
        RenderSystem(EventBus * eventBus);
        void init();
        void close();
        void createWindow();
        void createRenderer();
        void createTexture(TextureRect* givenRect);
        void update();
        void draw();
    protected:
        void onNotify(SDL_Event event);
    private:
        SDL_Window * window = NULL;
        SDL_Renderer * renderer = NULL;
        SDL_Surface * surface = NULL;
        SDL_Texture * texture = NULL;
        SDL_Texture * loadedTextures = NULL;
        std::vector<TextureRect*>* loadedRectangles = NULL;

};

#endif
