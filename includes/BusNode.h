#ifndef BUSNODE_H
#define BUSNODE_H
#include "EventBus.h"

class BusNode
{
    public:
        BusNode();
        BusNode(EventBus * eventBus);
        virtual void update();
        EventBus * getBus();
        void setBus(EventBus * bus);
    protected:
        EventBus * eventBus;
        std::function<void (SDL_Event)> getNotifyFunc();
        void send(SDL_Event * message);
        virtual void onNotify(SDL_Event event);
};
#endif
