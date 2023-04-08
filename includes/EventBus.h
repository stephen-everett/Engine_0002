#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <functional>
#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include "EventEnums.h"
#include "TextureRect.h"

class EventBus
{
    public:
        EventBus();
        ~EventBus();
        void addReceiver(int tag,std::function<void (SDL_Event)> eventReceiver);
        void removeReceiver(int tag);
        void sendMessage(SDL_Event * event);
        void notify();
    private:
        SDL_Event event;
        std::map<int, std::function<void (SDL_Event)>> receivers;


};
#endif

