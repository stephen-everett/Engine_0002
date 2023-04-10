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
        void fire();
    private:
        void onNotify(SDL_Event event);
        bool movingUp = false;
        bool movingDown = false;
        bool movingLeft = false;
        bool movingRight = false;
        Mouse* mouse;
        int mousex;
        int mousey;

        int centerx;
        int centery;

        int deltaX;
        int deltaY;

        double angle;

        int speedUp;
        int speedDown;
        int speedLeft;
        int speedRight;
        int frameCounter;

        std::vector<TextureRect> magazine;
        std::vector<TextureRect> fired;


};

#endif
