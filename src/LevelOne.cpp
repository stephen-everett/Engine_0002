#include "LevelOne.h"

LevelOne::LevelOne(){}
LevelOne::~LevelOne()
{
    printf("Level 1 being destructed!\n");
    eventBus->removeReceiver(LEVEL_1);
}
LevelOne::LevelOne(EventBus* eventBus):BusNode(LEVEL_1,eventBus),
    player(eventBus)
{
    // background
    staticAssets.emplace_back(
            PATH_LEVEL1_BACKGROUND,
            INDX_LEVEL1_BG,
            0,0,
            WINDOW_WIDTH,
            WINDOW_HEIGHT);

    // starry effect
    dynamicAssets.emplace_back(
            PATH_STARS,
            INDX_STARS,
            0,0,
            WINDOW_WIDTH,
            WINDOW_HEIGHT);

    dynamicAssets.emplace_back(
            PATH_STARS,
            INDX_STARS,
            0,-480,
            WINDOW_WIDTH,
            WINDOW_HEIGHT);
}

void LevelOne::update()
{
    for(auto it = dynamicAssets.begin(); it != dynamicAssets.end(); it++)
    {
        if(it->dimensions.y > 480)
        {
            it->dimensions.y = -479;
        }
        it->dimensions.y += 10;
    }
}

void LevelOne::requestTextures()
{
    for(auto it = staticAssets.begin(); it != staticAssets.end(); it++)
    {
        sendEvent(RM_SET_TEXTURE,&(*it),NULL);
    }
    
    for(auto it = dynamicAssets.begin(); it != dynamicAssets.end();it++)
    {
        sendEvent(RM_SET_TEXTURE,&(*it),NULL);
    }
    
}

void LevelOne::onNotify(SDL_Event event)
{
    printf("LevelOne onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("LevelOne received GL_LOAD_INITIAL\n");
            userEvent1 = *(Uint32*)event.user.data1;
            sendEvent(SYS_READY);
        }
        if(event.user.code == E_GET_TEXTURES)
        {
            requestTextures();
        }
        if(event.user.code == UPDATE)
        {
            printf("UPDATE RECEIVED\n");
            update();
        }
    }
}


