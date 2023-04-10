#include "ResourceManager.h"

ResourceManager::ResourceManager(){}

/* Instantiate ResourceManager. Set all elements in loadedTextures[] to NULL
 * if a texture has been used before, don't need to have RenderSystem create a 
 * new texture. One texture can be used by many Entities
 */
ResourceManager::ResourceManager(EventBus * eventBus) : 
    BusNode(RESOURCE_MANAGER,eventBus)
{
    for(int i = 0; i < TEXTURE_ARRAY_SIZE; i++)
    {
        loadedTextures[i] = NULL;
    }
}

void ResourceManager::update(){}

void ResourceManager::onNotify(SDL_Event event)
{
    printf("Resource Manager onNotify()\n");
    
    if(event.type == SDL_USEREVENT)
    {   
        /* set userEvent1 to the Systems userEvent1. Enable sending of 
        SDL_USEREVENTs
        */
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("---Received GL_LOAD_INITIAL event---\n");
            userEvent1 = *(Uint32*)event.user.data1;
        }
    
        /* Send reference to loadedRectangles to RenderSystem to use for drawing
         * textures to the screen
         */
        if(event.user.code == RM_SEND_RESOURCE_LINKS)
        {
            printf("--- Received RM_SEND_RESOURCE_LINKS ---\n");
            sendEvent(RS_LINK_RESOURCES,&loadedRectangles,NULL);
        }

        /* Given a TextureRect*, see if the texture has already been created
         * and saved in loadedTextures[]. If not, send the TextureRect* to 
         * RenderSystem to create texture
         */
        if(event.user.code == RM_SET_TEXTURE)
        {
            if(loadedTextures[((TextureRect*)event.user.data1)->textureIndex] == NULL)
            {
                printf("--- index was NULL ---\n");
                sendEvent(RS_CREATE_TEXTURE,event.user.data1,NULL);
            }
            else
            {
                printf("index was not null\n");

                ((TextureRect*)event.user.data1)->texture =
                    loadedTextures[((TextureRect*)event.user.data1)->textureIndex];

                loadedRectangles.push_back((TextureRect*)event.user.data1);
            }
        }
        
        /* Receive TextureRect* back from RenderSystem, add SDL_Rect that is 
         * inside TextureRect* to loadedRectangles. Save texture in 
         * Loaded Textures
         */
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
    printf("Size of loadedRectangles after flush: %i\n",(int)loadedRectangles.size());
}

