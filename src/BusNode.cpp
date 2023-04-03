#include "BusNode.h"

BusNode::BusNode(){}
BusNode::BusNode(EventBus * eventBus)
{
    this->eventBus = eventBus;
    this->eventBus->addReceiver(this->getNotifyFunc());
}

std::function<void (SDL_Event)> BusNode::getNotifyFunc()
{
    auto eventListener = [=](SDL_Event event) -> void 
    {
        this->onNotify(event);
    };
    return eventListener;
}

void BusNode::send(SDL_Event * event)
{
    eventBus->sendMessage(event);
}

void BusNode::onNotify(SDL_Event event)
{
    printf("Forgot to implement onNotify\n");
}

void BusNode::update()
{
    printf("Forgot to implement update\n");
}

EventBus * BusNode::getBus()
{
    return eventBus;
}

void BusNode::setBus(EventBus * bus)
{
    eventBus = bus;
}

void BusNode::initializeEvents()
{
    userEvent1 = SDL_RegisterEvents(1);
}


void BusNode::sendEvent(int code, void* data1, void* data2)
{
    SDL_Event myEvent;
    SDL_memset(&myEvent,0,sizeof(myEvent));
    myEvent.type = userEvent1;
    myEvent.user.code = code;
    myEvent.user.data1 = data1;
    myEvent.user.data2 = data2;
    SDL_PushEvent(&myEvent);
}

void BusNode::sendEvent(int code)
{
    SDL_Event myEvent;
    SDL_memset(&myEvent,0,sizeof(myEvent));
    myEvent.type = userEvent1;
    myEvent.user.code = code;
    myEvent.user.data1 = NULL;
    myEvent.user.data2 = NULL;
    SDL_PushEvent(&myEvent);
}

