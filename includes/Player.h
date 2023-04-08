#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player : public Entity
{
    public:
        Player();
        ~Player();
        Player(EventBus* eventBus);
        void update();
    private:
        void onNotify(SDL_Event event);
        bool movingUp = false;
        bool movingDown = false;
        bool movingLeft = false;
        bool movingRight = false;


};

#endif
