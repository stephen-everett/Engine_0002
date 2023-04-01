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
    Entity* mainBackground = new Entity(eventBus,MAIN_MENU_BACKGROUND_PATH,BACKGROUND_TEXTURE_INDEX,0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
    entities.push_back(mainBackground);
}

void Map::loadLevelAssets()
{
    Entity* test = new Entity(eventBus);
}

void Map::createTexture(const char* path)
{
    /*
    TextureRect textureRectangle;
    textureRectangle.tag = path;
    textureRectangle.texture = NULL;
    textureRectangle.dimensions.x = 0;
    textureRectangle.dimensions.y = 0;
    textureRectangle.dimensions.h = 480;
    textureRectangle.dimensions.w = 640;
    backgrounds.push_back(textureRectangle);
    */
}

void Map::onNotify(SDL_Event  message)
{
    printf("Map onNotify()\n");
    if (message.type == SDL_USEREVENT)
    {
        printf("---Received User Event ---\n");
        if(message.user.code == LOAD_INITIAL)
        {
            printf("---Received LOAD_INITIAL event ---\n");
            loadMainMenu();
        }
        if(message.user.code == LOAD_ENTITY)
        {
            printf("---Received LOAD_ENTITY event ---\n");
        }
    }
}

void Map::sendAssets()
{
    /*
    testVector.push_back(x);
    testVector2.push_back(test);
    if (testVector.front() == 0)
    {
        printf("problem not here\n");
    }

    Uint32 sendAssetEvent = SDL_RegisterEvents(1);
    if(sendAssetEvent != ((Uint32)-1))
    {
        SDL_memset(&event,0,sizeof(event));
        event.type = sendAssetEvent;
        event.user.code = LOAD_LEVEL;
        event.user.data1 = &backgrounds;
        event.user.data2 = &testVector2;
        SDL_PushEvent(&event);
    }
    */
}

void Map::loadRectFromEntities()
{
    /*
    for (auto it = entities.begin(); it != entities.end(); ++it)
    {
       backgrounds.push_back((*it)->getTextureRect());
    }
    int size = backgrounds.size();
    printf("----------BACKGROUNDS SIZE: %i",size);
    if(backgrounds.front() == NULL)
    {
        printf("Problem loading backgrounds\n");
    }
    else
    {
        printf("Backgrounds appear to be loading fine\n");
    }
    */
}

void Map::closeMap()
{
    /*
    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        delete(*it);
    }
    entities.clear();

    Uint32 sendAssetEvent = SDL_RegisterEvents(1);
    if(sendAssetEvent != ((Uint32)-1))
    {
        SDL_memset(&event,0,sizeof(event));
        event.type = sendAssetEvent;
        event.user.code = FLUSH_RECEIVERS;
        event.user.data1 = NULL;
        event.user.data2 = NULL;
        SDL_PushEvent(&event);
    }
    */

}


