#include "EventBus.h"
#include "BusNode.h"
#include "Structs.h"

EventBus::EventBus()
{}
EventBus::~EventBus(){}

void EventBus::addReceiver(std::function<void (SDL_Event)> eventReceiver)
{
    receivers.push_back(eventReceiver);
}

void EventBus::sendMessage(SDL_Event * passedEvent)
{
    SDL_PushEvent(passedEvent);
}

void EventBus::notify()
{
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_USEREVENT)
        {
            printf("---Event Bus Received User Event---\n");
            if(event.user.code == LOAD_INITIAL)
            {
                printf("---User code received: LOAD_INITIAL ---\n");
            }
            if(event.user.code == LOAD_ENTITY)
            {
                printf("---User code received: LOAD_ENTITY ---\n");
            }
        }
        for (auto it = receivers.begin(); it != receivers.end(); it++)
        {
            (*it)(event);
        }
 
   

    }
}

