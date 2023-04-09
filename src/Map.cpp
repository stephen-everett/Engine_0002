#include "Map.h"

Map::Map(){}

Map::Map(EventBus * eventBus,Mouse* mouse) : BusNode(MAP,eventBus)
{
    this->mouse = mouse;
}
Map::Map(EventBus* eventBus):BusNode(MAP,eventBus){}

Map::~Map()
{
    delete(mainMenu);
    mainMenu = NULL;
    delete(levelOne);
    levelOne = NULL;
    mouse = NULL;
    printf("Map being destructed!\n");
    eventBus->removeReceiver(MAP);
}

void Map::update(){}

void Map::loadMainMenu()
{
    // make sure to free at some point
    mainMenu = new MainMenu(eventBus, mouse);

    // Level has been created, let system know
    sendEvent(SYS_LEVEL_LOADED);
}

void Map::loadLevel()
{
    levelOne = new LevelOne(eventBus, mouse);
    sendEvent(SYS_LEVEL_LOADED);
}

void Map::onNotify(SDL_Event  event)
{
    printf("Map onNotify()\n");
    if (event.type == SDL_USEREVENT)
    {
        printf("---Received User Event ---\n");
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("---Received GL_LOAD_INITIAL event ---\n");
            userEvent1 = *(Uint32*)event.user.data1;
        }
        if(event.user.code == M_LOAD_MAIN)
        {
            printf("---Received M_LOAD_MAIN event ---\n");
            loadMainMenu();
        }
        if(event.user.code == M_RECTFLUSHED)
        {
            delete mainMenu;
            mainMenu = NULL;
            sendEvent(SYS_LEVEL_CLEARED);
        }
        if(event.user.code == M_LOAD_LEVEL_1)
        {
            loadLevel();
        }
    }
}




