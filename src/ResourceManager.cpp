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

void ResourceManager::setTexture(TextureRect* event)
{
    //sendEvent(RS_CREATE_TEXTURE,event,NULL);
    
    if(loadedTextures[event->textureIndex] == NULL)
    {
        printf("--- index was NULL ---\n");
        sendEvent(RS_CREATE_TEXTURE,event,NULL);
    }
    else
    {
        printf("index was not null\n");
        event->texture = loadedTextures[event->textureIndex];
        loadedRectangles.push_back(event);
    }
    
}

void ResourceManager::saveTexture(TextureRect* event)
{
    loadedTextures[event->textureIndex] = event->texture ;

    if(loadedTextures[event->textureIndex] == NULL)
    {
        printf("-- Index still NULL ---\n");
    }
    loadedRectangles.push_back(event);


}

void ResourceManager::onNotify(SDL_Event event)
{
    printf("Resource Manager onNotify()\n");
    switch(event.type)
    {
        case SDL_USEREVENT:
            switch(event.user.code)
            {
                case GL_LOAD_INITIAL:
                /* set userEvent1 to the Systems userEvent1. Enable sending of 
                 * SDL_USEREVENTs
                 */
                    printf("Resource Manager received GL_LOAD_INITIAL\n");
                    userEvent1 = *(Uint32*)event.user.data1;
                    break;

                case RM_SEND_RESOURCE_LINKS:
                /* Send reference to loadedRectangles to RenderSystem to use for drawing
                 * textures to the screen
                 */
                    printf("Resousrce Manager received RM_SEND_RESOURCE_LINKS\n");
                    sendEvent(RS_LINK_RESOURCES,&loadedRectangles,NULL);
                    break;

                case RM_SET_TEXTURE:
                /* Given a TextureRect*, see if the texture has already been created
                 * and saved in loadedTextures[]. If not, send the TextureRect* to 
                 * RenderSystem to create texture
                 */
                    setTexture((TextureRect*)event.user.data1);
                    break;

                case RM_SAVE_TEXTURE:
                /* Receive TextureRect* back from RenderSystem, add SDL_Rect that is 
                 * inside TextureRect* to loadedRectangles. Save texture in 
                 * Loaded Textures
                 */
                    saveTexture((TextureRect*)event.user.data1);
                    break;

                case RM_FLUSHRECT:
                    flushRect();
                    sendEvent(M_RECTFLUSHED);
                    break;
            }
            break;
    }
}

// may or may not be issue
void ResourceManager::flushRect()
{
    loadedRectangles.clear();
    printf("Size of loadedRectangles after flush: %i\n",(int)loadedRectangles.size());
}

