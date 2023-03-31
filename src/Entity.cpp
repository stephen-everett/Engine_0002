#include "Entity.h"

Entity::Entity(){}

Entity::~Entity(){}

Entity::Entity(EventBus * bus)
{
    this->eventBus = eventBus;
    this->eventBus->addStaticReceiver(this->getNotifyFunc());

}


Entity::Entity(EventBus * bus, const char* path, int x, int y, int w, int h)
{
    this->eventBus = bus;
    this->eventBus->addReceiver(this->getNotifyFunc());
    entityData.tag = path;
    entityData.dimensions.x = x;
    entityData.dimensions.y = y;
    entityData.dimensions.w = w;
    entityData.dimensions.h = h;
}

void Entity::update(){}

TextureRect * Entity::getTextureRect()
{
    return &entityData;
}

void Entity::onNotify(SDL_Event event)
{
    printf("Entity on notify\n");
}
