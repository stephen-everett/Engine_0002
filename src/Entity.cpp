#include "Entity.h"

Entity::Entity(){}

Entity::~Entity(){}

Entity::Entity(EventBus * eventBus) :BusNode(eventBus)
{
    empty = true;
}


Entity::Entity(EventBus * eventBus, const char* path,int index, int x, int y, int w, int h)
    :BusNode(eventBus)
{
    //printf("---CREATING ENTITY---\n");
   entityData.texturePath = path;
   entityData.textureIndex = index;
   entityData.dimensions.x = x;
   entityData.dimensions.y = y;
   entityData.dimensions.h = h;
   entityData.dimensions.w = w;
   //printf("------------SENDING LOAD_ENTITY---------\n");
   //sendEvent(LOAD_ENTITY,&entityData,NULL);
   //printf("---SENDING TEST LOAD_INITIAL EVENT---\n");
   //sendEvent(LOAD_INITIAL,NULL,NULL);
}

void Entity::update(){}

TextureRect * Entity::getTextureRect()
{
    return &entityData;
}

void Entity::onNotify(SDL_Event event)
{
    if(!empty)
    {
        printf("Entity on notify\n");
    }
    if(event.type == SDL_USEREVENT)
    {
        printf("-----Entity received user event-----\n");
        if(event.user.code == LOAD_INITIAL)
        {
            printf("------Received LOAD_INITIAL event-----\n");
        }
        if(event.user.code == LOAD_ENTITY)
        {
            printf("-----Received LOAD_ENTITY event-------\n");
        }
    }
}
