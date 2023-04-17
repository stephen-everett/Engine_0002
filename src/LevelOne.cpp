#include "LevelOne.h"

LevelOne::LevelOne(){}
LevelOne::~LevelOne()
{
    printf("Level 1 being destructed!\n");
    eventBus->removeReceiver(LEVEL_1);
}
LevelOne::LevelOne(EventBus* eventBus, Mouse* mouse,GameTime* clock):BusNode(LEVEL_1,eventBus),
    player(eventBus, mouse,clock)
{
    this->clock = clock;
    this->mouse = mouse;
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
            0,-WINDOW_HEIGHT,
            WINDOW_WIDTH,
            WINDOW_HEIGHT);
    for(auto it = staticAssets.begin(); it != staticAssets.end(); it++)
    {
        it->drawRect.x = 0;
        it->drawRect.y = 0;
        it->drawRect.h = 1080;
        it->drawRect.w = 1920;
    }
    for(auto it = dynamicAssets.begin(); it != dynamicAssets.end(); it++)
    {
        it->drawRect.x = 0;
        it->drawRect.y = 0;
        it->drawRect.h = 480;
        it->drawRect.w = 640;
    }

}

void LevelOne::update()
{
    if(clock->isTime())
    {
        for(auto it = dynamicAssets.begin(); it != dynamicAssets.end(); it++)
        {
            if(it->dimensions.y > WINDOW_HEIGHT)
            {
                it->dimensions.y = -WINDOW_HEIGHT;
            }
            it->dimensions.y += 10;
        }
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
    if(event.type == SDL_MOUSEMOTION)
    {
        printf("Receieved mouse motion!\n");
    }
}


