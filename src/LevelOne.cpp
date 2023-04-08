#include "LevelOne.h"

LevelOne::LevelOne(){}
LevelOne::~LevelOne()
{
    printf("Level 1 being destructed!\n");
    eventBus->removeReceiver(LEVEL_1);
}
LevelOne::LevelOne(EventBus* eventBus):BusNode(LEVEL_1,eventBus),
    background(eventBus,LEVEL_ONE_BACKGROUND_PATH,
            INDX_LEVEL1_BG,
            0,0,
            WINDOW_WIDTH,WINDOW_HEIGHT)
{}

void LevelOne::update(){}

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
    }
}


