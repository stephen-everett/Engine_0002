#include "Entity.h"

Entity::Entity(){}

Entity::~Entity()
{}

Entity::Entity(EventBus * eventBus) :BusNode(eventBus)
{
    empty = false;
}


Entity::Entity(EventBus * eventBus, const char* path,int index, int x, int y, int w, int h)
    :BusNode(eventBus)
{
    empty = false;
   entityData.texturePath = path;
   entityData.textureIndex = index;
   entityData.texture = NULL;
   entityData.dimensions.x = x;
   entityData.dimensions.y = y;
   entityData.dimensions.h = h;
   entityData.dimensions.w = w;

}

void Entity::update(){}

TextureRect* Entity::getRect()
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
            if(event.user.code == GL_LOAD_INITIAL)
            {
                printf("--- Received GL_LOAD_INITIAL ---\n");
                userEvent1 = *(Uint32*)event.user.data1;
            }
        }
    }
}
