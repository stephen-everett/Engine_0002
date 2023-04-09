#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Mouse.h"

class Player : public Entity
{
    public:
        Player();
        ~Player();
        Player(EventBus* eventBus, Mouse* mouse);
        void update();
    private:
        void onNotify(SDL_Event event);
        bool movingUp = false;
        bool movingDown = false;
        bool movingLeft = false;
        bool movingRight = false;
        Mouse* mouse;
        int mousex;
        int mousey;


};

#endif
