#include "Button.h"

Button::Button(){}

Button::~Button()
{
    printf("Button being destructed!\n");
    eventBus->removeReceiver(BUTTON);
}

Button::Button(EventBus* eventBus):Entity(BUTTON,eventBus){}

Button::Button(EventBus* eventBus,Entity* mouse, const char* path, int index, int x, int y, int w, int h)
    :Entity(BUTTON,eventBus, path, index, x, y, w, h)
{
    this->mouse = (Mouse*)mouse;
}

void Button::update(){}

void Button::onNotify(SDL_Event event)
{
    printf("Button onNotify()\n");
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(SDL_HasIntersection(&entityData.dimensions, &mouse->getRect()->dimensions))
        {
            printf("MOUSE BUTTON CLICK DETECTED\n");
            sendEvent(START_CLICKED);
        }
    }
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("Button GL_LOAD_INITIAL\n");
            userEvent1 = *(Uint32*)event.user.data1;
        }
        if(event.user.code == E_GET_TEXTURES)
        {
            printf("Button request textures\n");
            requestTextures();
        }
    }
}
