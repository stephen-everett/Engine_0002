#ifndef LEVELONE_H
#define LEVELONE_H
#include "BusNode.h"
#include "Entity.h"
#include "Button.h"
#include "Mouse.h"
#include "Player.h"
#include "GameTime.h"


class LevelOne : public BusNode
{
    public:
        LevelOne();
        LevelOne(EventBus* eventBus, Mouse* mouse, GameTime* clock);
        ~LevelOne();
        void update();
        void requestTextures();
    protected:
        void onNotify(SDL_Event event);
    private:
        GameTime* clock;
        Mouse* mouse;
        Player player;
        std::vector<TextureRect> staticAssets;
        std::vector<TextureRect> dynamicAssets;
        Entity colliderTester;
        //Button startButton;

};
#endif
