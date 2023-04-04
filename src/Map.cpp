#include "Map.h"

Map::Map(){}

Map::Map(EventBus * eventBus, Entity **allEntities) : BusNode(eventBus)
{
    this->allEntities = allEntities;
}

Map::~Map(){}

void Map::update(){}

void Map::loadMainMenu()
{
    printf("+++ in Map::loadMainMenu() +++\n");
    TextureRect * mainBackground = allEntities[MAIN_MENU]->getRect();
    TextureRect * startButton = allEntities[START_BUTTON]->getRect();
    TextureRect * mouse = allEntities[E_MOUSE]->getRect();
    sendEvent(RM_SET_TEXTURE, mainBackground,NULL);
    sendEvent(RM_SET_TEXTURE, startButton,NULL);
    sendEvent(RM_SET_TEXTURE, mouse, NULL);
    sendEvent(SYS_READY,NULL,NULL);
}

void Map::loadLevel()
{
    printf("--- Reached LoadLevel() ---\n");
    TextureRect * level1Background = allEntities[LEVEL_1]->getRect();
    sendEvent(RM_SET_TEXTURE, level1Background,NULL);
    sendEvent(SYS_READY,NULL,NULL);
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
        if(event.user.code == M_WIPE)
        {
            printf("--- Received M_WIPE ---\n");
            clearMap();
            //sendEvent(SYS_STAGE_SET);
        }
        if(event.user.code == M_LOAD_MAIN)
        {
            printf("--- Received M_LOAD_MAIN ---\n");
            loadMainMenu();
        }
        if(event.user.code == M_RECTFLUSHED)
        {
            sendEvent(SYS_STAGE_SET);
        }
        if(event.user.code == M_LOAD_LEVEL_1)
        {
            loadLevel();
        }
    }
}

// Delete entity pointers in backgrounds. Tell resource manager
// to flush it's rectangle vector
void Map::clearMap()
{
   sendEvent(RM_FLUSHRECT,NULL,NULL);
}




