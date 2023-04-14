#include "LevelOne.h"

LevelOne::LevelOne(){}
LevelOne::~LevelOne()
{
    printf("Level 1 being destructed!\n");
    eventBus->removeReceiver(LEVEL_1);
}
LevelOne::LevelOne(EventBus* eventBus, Mouse* mouse,GameTime* clock):BusNode(LEVEL_1,eventBus),
    player(eventBus, mouse,clock), colliderTester(ENTITY,eventBus,PATH_COLLIDERTESTER,INDX_COLLIDERTESTER,WINDOW_WIDTH/2,WINDOW_HEIGHT/2,50,50),
    enemies(eventBus,clock)
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
            0,-480,
            WINDOW_WIDTH,
            WINDOW_HEIGHT);
}

void LevelOne::update()
{
    if(clock->isTime())
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
    if(colliderTester.getTextureRect()->isCollided)
    {
        printf("Collision Detected! Number of collisions: %i\n",colliderTester.getTextureRect()->collisionCount);
    }
    else
    {
        printf("Collision not detected! Number of collisoins: %i\n",colliderTester.getTextureRect()->collisionCount);
    }
}

void LevelOne::requestTextures()
{
    TextureRect* temp = mouse->getTextureRect();
    sendEvent(RM_SET_TEXTURE,mouse->getTextureRect(),NULL);
    for(auto it = staticAssets.begin(); it != staticAssets.end(); it++)
    {
        sendEvent(RM_SET_TEXTURE,&(*it),NULL);
    }
    
    for(auto it = dynamicAssets.begin(); it != dynamicAssets.end();it++)
    {
        sendEvent(RM_SET_TEXTURE,&(*it),NULL);
    }
    sendEvent(RM_SET_TEXTURE,colliderTester.getTextureRect(),NULL);
    colliderTester.setCollision(COLLIDER_ENEMY);
    sendEvent(CS_LOAD_COLLIDER,colliderTester.getTextureRect(),NULL);
    
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


