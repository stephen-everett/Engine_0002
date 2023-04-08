#ifndef MAP_H
#define MAP_H
#include "BusNode.h"
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
        Mouse* mouse = NULL;
        MainMenu * mainMenu = NULL;
        LevelOne * levelOne = NULL;
    private:

};

#endif
