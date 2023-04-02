#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <vector>
#include <SDL2/SDL.h>
#include "Asset.h"
#include "TextureRect.h"
#include "EventBus.h"
#include "BusNode.h"
        void onNotify(SDL_Event event);
#include "Structs.h"

class RenderSystem : BusNode
{
    public:
        RenderSystem();
        RenderSystem(EventBus * eventBus);
        void init();
        void close();
        //bool quitStatus();
        void createWindow();
        void createRenderer();
        //void eventQueue();
        //void loadAssets(std::vector<Asset*> *ass);
        void testLoad(std::vector<int>* x);
        void testLoad2(std::vector<int*>* x);
        void createTexture(TextureRect* givenRect);
        void loadStaticAssets(std::vector<TextureRect*>* staticAssVec);
       // void loadStaticAssets(std::vector<Asset*> *ass);
       // void loadAsset(Asset * asset);
        //void loadStaticAsset(Asset * asset);
        //void update(std::vector<Asset*> *ass, const char* name);
        void update();
        void draw();
        void setDebug(bool state);
    protected:
        void onNotify(SDL_Event event);
    private:
        bool debug = false;
        bool quit = false;
        SDL_Window * window = NULL;
        SDL_Renderer * renderer = NULL;
        SDL_Surface * surface = NULL;
        SDL_Texture * texture = NULL;
        SDL_Event e;
        TextureRect MapTextureRect;
        std::vector<Asset*> *allAssets = NULL;
        std::vector<TextureRect> textures;
        std::vector<TextureRect*> staticTextures;
        SDL_Texture * loadedTextures;
        std::vector<TextureRect*>* loadedRectangles;

        int numberOfAssets;
};

#endif
