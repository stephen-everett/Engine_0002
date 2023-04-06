#include "Button.h"

Button::Button(){}

Button::~Button(){}

Button::Button(EventBus* eventBus,Entity* mouse, const char* path, int index, int x, int y, int w, int h)
    :Entity(eventBus, path, index, x, y, w, h)
{
    this->mouse = (Mouse*)mouse;
}

void Button::update(){}

void Button::onNotify(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(SDL_HasIntersection(&entityData.dimensions, &mouse->getRect()->dimensions))
        {
            printf("MOUSE BUTTON CLICK DETECTED\n");
            sendEvent(START_CLICKED);
        }
    }
}
