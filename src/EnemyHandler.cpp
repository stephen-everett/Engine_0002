#include "EnemyHandler.h"

EnemyHandler::EnemyHandler(){}

EnemyHandler::EnemyHandler(EventBus* eventBus,GameTime* clock):BusNode(ENEMY_HANDLER,eventBus)
{
    this->clock = clock;
    enemyList.emplace_back(Enemy());
}

EnemyHandler::~EnemyHandler()
{
    eventBus->removeReceiver(ENEMY_HANDLER);
}

void EnemyHandler::loadEnemies()
{
    for(auto it = enemyList.begin(); it != enemyList.end(); it++)
    {
        sendEvent(RM_SET_TEXTURE,it->getTextureRect(),NULL);
        sendEvent(CS_LOAD_COLLIDER, it->getTextureRect(),NULL);
    }
}

void EnemyHandler::update()
{
    if(clock->isTime())
    {
        for(auto it = enemyList.begin(); it != enemyList.end(); it++)
        {
            it->update();
        }
    }
}

void EnemyHandler::onNotify(SDL_Event event)
{
    switch(event.type)
    {
        case SDL_USEREVENT:
            switch(event.user.code)
            {
                case GL_LOAD_INITIAL:
                    userEvent1 = *(Uint32*)event.user.data1;
                    break;

                case UPDATE:
                    update();
                    break;

                case E_GET_TEXTURES:
                    loadEnemies();
                    break;
            }
            break;
        case SDL_KEYDOWN:
            break;
    }
}
