#include "Entity.h"

Entity::Entity(){}

Entity::~Entity()
{
    printf("Entity being destructed!\n");
    eventBus->removeReceiver(ENTITY);
}
Entity::Entity(int tag,EventBus * eventBus) :BusNode(tag,eventBus){}
Entity::Entity(EventBus * eventBus) :BusNode(ENTITY,eventBus)
{
    empty = false;
}

Entity::Entity(int tag,EventBus * eventBus, const char* path,int index, int x, int y, int w, int h)
    :BusNode(tag,eventBus)
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
Entity::Entity(EventBus * eventBus, const char* path,int index, int x, int y, int w, int h)
    :BusNode(ENTITY,eventBus)
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
void Entity::requestTextures()
{
   sendEvent(RM_SET_TEXTURE,&entityData,NULL); 
}

void Entity::setCollision(int collisionStatus)
{
    entityData.colliderTag = collisionStatus;
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
            if(event.user.code == E_GET_TEXTURES)
            {
                printf("Entity request textures\n");
                requestTextures();
            }
        }
    }
}

TextureRect* Entity::getTextureRect()
{
    return &entityData;
}
