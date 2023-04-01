#include "ResourceManager.h"

ResourceManager::ResourceManager(){}

ResourceManager::ResourceManager(EventBus * bus) : BusNode(bus)
{
    for(int i = 0; i < TEXTURE_ARRAY_SIZE; i++)
    {
        loadedTextures[i] = NULL;
    }
}

void ResourceManager::createTexture(TextureRect * givenRect)
{
   sendEvent(LOAD_TEXTURE, givenRect, NULL);
}

void ResourceManager::loadRect(TextureRect* givenRect){}

void ResourceManager::update(){}
/*
void ResourceManager::onNotify(SDL_Event event)
{
    printf("Resource Manager onNotify()\n");
}
*/
void ResourceManager::onNotify(SDL_Event event)
{
    printf("Resource Manager onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        printf("---Received User Event---\n");
        if(event.user.code == LOAD_ENTITY)
        {
            printf("---Received LOAD_ENTITY event ---\n");
            //createTexture((TextureRect*)event.user.data1);
        }
        if(event.user.code == LOAD_INITIAL)
        {
            printf("---Received LOAD_INITIAL event---\n");
        }
    }
}

