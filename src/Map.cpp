#include "Map.h"

Map::Map(){}

Map::Map(EventBus * eventBus) : BusNode(eventBus)
{
    //loadLevelAssets();
    //loadRectFromEntities();
    //createTexture("./assets/img/background-main.jpg");
}

Map::~Map(){}

void Map::update(){}

void Map::loadMainMenu()
{
    backgrounds.push_back(new Entity(eventBus, MAIN_MENU_BACKGROUND_PATH,BACKGROUND_TEXTURE_INDEX,0,0,WINDOW_WIDTH,WINDOW_HEIGHT));
    
    backgrounds.push_back(new Button(
                eventBus,
                B_START_PATH,
                0,
                (WINDOW_WIDTH/2)-150,
                (WINDOW_HEIGHT/2)-50,
                300,100));
                
}

void Map::onNotify(SDL_Event  event)
{
    printf("Map onNotify()\n");
    if (event.type == SDL_USEREVENT)
    {
        printf("---Received User Event ---\n");
        if(event.user.code == LOAD_INITIAL)
        {
            printf("---Received LOAD_INITIAL event ---\n");
            userEvent1 = *(Uint32*)event.user.data1;
            loadMainMenu();
        }
        if(event.user.code == LOAD_ENTITY)
        {
            printf("---Received LOAD_ENTITY event ---\n");
        }
        if(event.user.code == TEST_EVENT)
        {
            printf("---Received TEST_EVENT Map ---\n");
        }
        
        if(event.user.code == TEST_RENDER)
        {
            printf("--- Received TEST_RENDER RenderSystem---\n");
        }
    }
}




