#include "ResourceManager.h"

ResourceManager::ResourceManager(){}

ResourceManager::ResourceManager(EventBus * bus) : BusNode(bus)
{
    for(int i = 0; i < TEXTURE_ARRAY_SIZE; i++)
    {
        loadedTextures[i] = NULL;
    }
}

/* Sends Rectangle passed by Entity to RenderSystem to create a texture
 * pointer to texture and pointer to rectangle in loadedTextures
 * and loadedRectangles. Render system has pointer to these data structures
 */
void ResourceManager::createTexture(TextureRect * givenRect)
{
}

void ResourceManager::loadRect(TextureRect* givenRect){}

void ResourceManager::update(){}

void ResourceManager::onNotify(SDL_Event event)
{
    printf("Resource Manager onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("---Received GL_LOAD_INITIAL event---\n");
            userEvent1 = *(Uint32*)event.user.data1;
        }
        if(event.user.code == RM_SEND_RESOURCE_LINKS)
        {
            printf("--- Received RM_SEND_RESOURCE_LINKS ---\n");
            sendEvent(RS_LINK_RESOURCES,&loadedRectangles,NULL);
        }
        if(event.user.code == RM_SET_TEXTURE)
        {
            if(loadedTextures[((TextureRect*)event.user.data1)->textureIndex] == NULL)
            {
                printf("--- index was NULL ---\n");
                sendEvent(RS_CREATE_TEXTURE,event.user.data1,NULL);
            }
            else
            {
                ((TextureRect*)event.user.data1)->texture =
                    loadedTextures[((TextureRect*)event.user.data1)->textureIndex];
                loadedRectangles.push_back((TextureRect*)event.user.data1);
            }
        }
        if(event.user.code == RM_SAVE_TEXTURE)
        {
            loadedTextures[((TextureRect*)event.user.data1)->textureIndex] =
                ((TextureRect*)event.user.data1)->texture ;
            if(loadedTextures[((TextureRect*)event.user.data1)->textureIndex] == NULL)
            {
                printf("-- Index still NULL ---\n");
            }

            loadedRectangles.push_back((TextureRect*)event.user.data1);
        }
        if(event.user.code == RM_FLUSHRECT)
        {
            flushRect();
            sendEvent(M_RECTFLUSHED);
        }
    }
}

// may or may not be issue
void ResourceManager::flushRect()
{
    loadedRectangles.clear();
}

void ResourceManager::addTexture(TextureRect* rectangle)
{
    loadedRectangles.push_back(rectangle);
    if(loadedTextures[rectangle->textureIndex] == NULL)
    {
        loadedTextures[rectangle->textureIndex] = rectangle->texture;
    }
}

