#ifndef LEVELONE_H
#define LEVELONE_H
#include "BusNode.h"
#include "Entity.h"
#include "Button.h"
#include "Mouse.h"


class LevelOne : public BusNode
{
    public:
        LevelOne();
        LevelOne(EventBus* eventBus);
        ~LevelOne();
        void update();
       // void requestTextures();
    protected:
        void onNotify(SDL_Event event);
    private:
        //Mouse* mouse;
        Entity background;
        //Button startButton;

};
#endif
