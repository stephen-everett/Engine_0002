#include "Mouse.h"

Mouse::Mouse(){}

Mouse::Mouse(EventBus* eventBus): Entity(eventBus)
{
    entityData.texturePath = P_MOUSE_MODEL;
    entityData.textureIndex = INDX_MOUSE;
    entityData.dimensions.x = 0;
    entityData.dimensions.y = 0;
    entityData.dimensions.w = 50;
    entityData.dimensions.h = 50;
}

void Mouse::update(){}

void Mouse::onNotify(SDL_Event event)
{
    if(event.type == SDL_MOUSEMOTION)
    {
        SDL_GetMouseState(&entityData.dimensions.x, &entityData.dimensions.y);
    }
}

