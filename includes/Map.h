#ifndef MAP_H
#define MAP_H
#include "BusNode.h"
#include "Structs.h"
#include "TextureRect.h"
#include <SDL2/SDL_image.h>
#include "Entity.h"
#include "Button.h"

class Map : public BusNode
{
    public:
        Map();
        Map(EventBus * eventBus, Entity** allEntities);
        ~Map();
        void update();
        void loadMainMenu();
        void loadLevel();
    protected:
        void clearMap();
        void onNotify(SDL_Event  message);
        Entity** allEntities;
    private:

};

#endif
