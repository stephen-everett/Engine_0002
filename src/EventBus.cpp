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

void EventBus::addStaticReceiver(std::function<void (SDL_Event)> staticEventReceiver)
{
    staticReceivers.push_back(staticEventReceiver);
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
            if (event.user.code == FLUSH_RECEIVERS)
            {
                receivers.clear();
            }
        }
        for (auto it = staticReceivers.begin(); it != staticReceivers.end(); it++)
        {
            (*it)(event);
        }
        for (auto it = receivers.begin(); it != receivers.end(); it++)
        {
            (*it)(event);
        }
 
   

    }
}

