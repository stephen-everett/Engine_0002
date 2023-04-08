#ifndef MAP_H
#define MAP_H
#include "BusNode.h"
#include "Structs.h"
#include "TextureRect.h"
#include <SDL2/SDL_image.h>
#include "Entity.h"
#include "Button.h"
#include "MainMenu.h"
#include "Mouse.h"
#include "LevelOne.h"

class Map : public BusNode
{
    public:
        Map();
        Map(EventBus * eventBus, Mouse* mouse);
        Map(EventBus* eventBus);
        ~Map();
        void update();
        void loadMainMenu();
        void loadLevel();
    protected:
        void clearMap();
        void onNotify(SDL_Event  message);
        BusNode* holder;
        Mouse* mouse;
        MainMenu * mainMenu = NULL;
        LevelOne * levelOne = NULL;
        Entity * placeHolder;
    private:

};

#endif
