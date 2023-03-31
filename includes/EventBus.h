#ifndef EVENTBUS_H
#define EVENTBUS_H

#include <functional>
#include <SDL2/SDL.h>
#include <vector>
#include "EventEnums.h"
#include "TextureRect.h"

class EventBus
{
    public:
        EventBus();
        ~EventBus();
        void addReceiver(std::function<void (SDL_Event)> eventReceiver);
        void addStaticReceiver(std::function<void (SDL_Event)> staticEventReceiver);
        void sendMessage(SDL_Event * event);
        void notify();
    private:
        SDL_Event event;
        std::vector<std::function<void (SDL_Event)>> staticReceivers;
        std::vector<std::function<void (SDL_Event)>> receivers;


};
#endif
