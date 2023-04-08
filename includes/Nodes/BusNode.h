#ifndef BUSNODE_H
#define BUSNODE_H
#include "EventBus.h"

class BusNode
{
    public:
        BusNode();
        BusNode(int tag,EventBus * eventBus);
        virtual void update();
        EventBus * getBus();
        void setBus(EventBus * bus);
        void initializeEvents();
        void sendEvent(int code, void* data1, void* data2);
        void sendEvent(int code);
    protected:
        EventBus * eventBus;
        std::function<void (SDL_Event)> getNotifyFunc();
        void send(SDL_Event * message);
        virtual void onNotify(SDL_Event event);
        Uint32 userEvent1;
};
       
#endif
