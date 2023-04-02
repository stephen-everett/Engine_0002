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
   sendEvent(CREATE_TEXTURE, givenRect, NULL);
   loadedTextures[givenRect->textureIndex] = givenRect->texture;
   loadedRectangles.push_back(givenRect);
}

void ResourceManager::loadRect(TextureRect* givenRect){}

void ResourceManager::update(){}

void ResourceManager::onNotify(SDL_Event event)
{
    printf("Resource Manager onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        printf("---Received User Event---\n");
        if(event.user.code == LOAD_ENTITY)
        {
            printf("---Received LOAD_ENTITY event ---\n");
        }
        if(event.user.code == LOAD_INITIAL)
        {
            printf("---Received LOAD_INITIAL event---\n");
            userEvent1 = *(Uint32*)event.user.data1;
            sendEvent(RM_INIT, &loadedTextures,&loadedRectangles);
        }
        if(event.user.code == TEST_EVENT)
        {
            printf("--- Received TEST_EVENT ResourceManager ---\n");
        }
        if(event.user.code == TEST_RENDER)
        {
            printf("--- Received TEST_RENDER Resource Manager---\n");
        }
        if(event.user.code == LOAD_TEXTURE)
        {
            printf("--- Received LOAD_TEXTURE Resource Manager---\n");
            printf("--- %s\n ---",((TextureRect*)event.user.data1)->texturePath);
            createTexture((TextureRect*)event.user.data1);

        }
    }
}

