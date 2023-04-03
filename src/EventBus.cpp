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
        for (auto it = receivers.begin(); it != receivers.end(); it++)
        {
            (*it)(event);
        }
    }
}

