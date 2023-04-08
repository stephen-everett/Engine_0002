#include "Mouse.h"

Mouse::Mouse(){}

Mouse::Mouse(EventBus* eventBus): Entity(MOUSE,eventBus)
{
    entityData.texturePath = PATH_MOUSE_MODEL;
    entityData.textureIndex = INDX_MOUSE;
    entityData.dimensions.x = 0;
    entityData.dimensions.y = 0;
    entityData.dimensions.w = 50;
    entityData.dimensions.h = 50;
}

Mouse::~Mouse()
{
    printf("Mouse being destructed!\n");
    eventBus->removeReceiver(MOUSE);
}
void Mouse::update(){}

void Mouse::onNotify(SDL_Event event)
{
    printf("Mouse onNotify()\n");
    if(event.type == SDL_MOUSEMOTION)
    {
        SDL_GetMouseState(&entityData.dimensions.x, &entityData.dimensions.y);
    }
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == E_GET_TEXTURES)
        {
            requestTextures();
        }
        if(event.user.code == GL_LOAD_INITIAL)
        {
            userEvent1 = *(Uint32*)event.user.data1;
        }
    }
}

