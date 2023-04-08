#ifndef SYSTEM_H
#define SYSTEM_H
#include "BusNode.h"
#include "Map.h"
#include "Mouse.h"


class System : public BusNode
{
    public:
        System();
        System(EventBus* eventBus);
        ~System();
        void update();
        void start();
    protected:
        void onNotify(SDL_Event event);
    private:
        int level;
        State state;
        bool quit;
        Mouse * mouse;
};



#endif
