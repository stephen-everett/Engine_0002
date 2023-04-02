#include "Button.h"

Button::Button(){}

Button::Button(EventBus* eventBus, const char* path, int index, int x, int y, int w, int h)
    :Entity(eventBus, path, index, x, y, w, h)
{}

void Button::update(){}

void Button::onNotify(SDL_Event event)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        printf("---MOUSE PRESSED---\n");
    }
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == LOAD_INITIAL)
        {
            userEvent1 = *(Uint32*)event.user.data1;
            sendEvent(LOAD_TEXTURE,&entityData,NULL);
            //userEvent1 = *(Uint32*)event.user.data1;
            //sendEvent(LOAD_TEXTURE, &entityData,NULL);
        }
    }
}
