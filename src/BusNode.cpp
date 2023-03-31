#include "BusNode.h"

BusNode::BusNode(){}
BusNode::BusNode(EventBus * eventBus)
{
    this->eventBus = eventBus;
    this->eventBus->addStaticReceiver(this->getNotifyFunc());
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
