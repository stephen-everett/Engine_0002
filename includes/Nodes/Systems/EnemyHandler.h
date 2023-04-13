#ifndef ENEMYHANDLER_H
#define ENEMYHANDLER_H
#include "BusNode.h"
#include "Enemy.h"
#include "GameTime.h"

class EnemyHandler : public BusNode
{
    public:
        EnemyHandler();
        EnemyHandler(EventBus* eventBus,GameTime* clock);
        ~EnemyHandler();
        void onNotify(SDL_Event event);
        void update();
        void loadEnemies();
    private:
        GameTime* clock;
        std::vector<Enemy> enemyList;
};
#endif
