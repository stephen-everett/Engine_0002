#ifndef MAP_H
#define MAP_H
#include "BusNode.h"
#include "Structs.h"
#include "TextureRect.h"
#include <SDL2/SDL_image.h>
#include "Entity.h"

class Map : public BusNode
{
    public:
        Map();
        Map(EventBus * eventBus);
        ~Map();
        void update();
        void loadMainMenu();
        void loadLevelAssets();
        void createTexture(const char* path);
        void sendAssets();
        void loadRectFromEntities();
        void closeMap();
    protected:
        void onNotify(SDL_Event  message);
    private:
        int x = 0;
        int * test = &x;
        std::vector<int> testVector;
        std::vector<int*> testVector2;
        std::vector<Entity*> entities;
        std::vector<TextureRect*> backgrounds;
        std::vector<dynamicAsset> effects;
        SDL_Event event;

};

#endif
