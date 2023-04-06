#ifndef SYSTEM_H
#define SYSTEM_H
#include "BusNode.h"
#include "Map.h"


class System : public BusNode
{
    public:
        System();
        System(EventBus* eventBus);
        ~System();
        void update();
        void start();
        void setEntity();
    protected:
        void onNotify(SDL_Event event);
    private:
        int level;
        State state;
        bool quit;
        SDL_Event event;
        Entity * allEntities[NUMBER_OF_ENTITIES+1];
};



#endif
