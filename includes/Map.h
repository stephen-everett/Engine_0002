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
        Map(EventBus * eventBus);
        ~Map();
        void update();
        void loadMainMenu();
    protected:
        void onNotify(SDL_Event  message);
        std::vector<Entity*> backgrounds;
    private:

};

#endif
