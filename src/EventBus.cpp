#include "EventBus.h"
#include "BusNode.h"
#include "Structs.h"

EventBus::EventBus()
{}
EventBus::~EventBus(){}

void EventBus::addReceiver(int tag,std::function<void (SDL_Event)> eventReceiver)
{
    receivers.insert(std::pair<int,std::function<void (SDL_Event)>>(tag,eventReceiver));
}

void EventBus::removeReceiver(int tag)
{
    receivers.erase(tag);
}

void EventBus::sendMessage(SDL_Event * passedEvent)
{
    SDL_PushEvent(passedEvent);
}

void EventBus::notify()
{
    while(SDL_PollEvent(&event))
    {
        for (auto it = receivers.begin(); it != receivers.end(); it++)
        {
            it->second(event);
        }
    }
}

