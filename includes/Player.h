#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Mouse.h"
#include "Structs.h"
#include "Weapon.h"

class Player : public Entity
{
    public:
        Player();
        ~Player();
        Player(EventBus* eventBus, Mouse* mouse,GameTime* clock);
        void update();
        void fire();
        void sendColliders();
        void move();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
    private:
        void updatePositions();
        void updateProjectiles();
        void calculateTrajectory();
        void setSpeedLimit(int limit);
        void keyPressed(SDL_Keycode key);
        void keyReleased(SDL_Keycode key);
        void onNotify(SDL_Event event);
        void requestTextures();
        bool movingUp = false;
        bool movingDown = false;
        bool movingLeft = false;
        bool movingRight = false;
        Mouse* mouse;
        int mousex;
        int mousey;

        GameTime* clock;


        TextureRect locationFinder;

        int centerx;
        int centery;

        int deltaX;
        int deltaY;

        double angle;
        double trajectoryX;
        double trajectoryY;

        int speedLimit;
        int speedUp;
        int speedDown;
        int speedLeft;
        int speedRight;
        int frameCounter;

        int rotationPointOffsetX;
        int rotationPointOffsetY;

        int leftFrame;
        int rightFrame;
        int upFrame;

        double deltaTime;

        movingState moving;

        std::vector<TextureRect> magazine;
        std::vector<Weapon> weapons;



};

#endif
