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
   entityData.texturePath = path;
   entityData.textureIndex = index;
   entityData.texture = NULL;
   entityData.dimensions.x = x;
   entityData.dimensions.y = y;
   entityData.dimensions.h = h;
   entityData.dimensions.w = w;
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
        if(event.type == SDL_USEREVENT)
        {
            printf("-----Entity received user event-----\n");
            if(event.user.code == LOAD_INITIAL)
            {
                printf("------Received LOAD_INITIAL event-----\n");
                userEvent1 = *(Uint32*)event.user.data1;
                sendEvent(LOAD_TEXTURE,&entityData,NULL);
            }
            if(event.user.code == LOAD_ENTITY)
            {
                printf("-----Received LOAD_ENTITY event-------\n");
            }
        }
    }
}
