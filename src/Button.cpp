#include "Button.h"

Button::Button(){}

Button::Button(EventBus* eventBus, const char* path, int index, int x, int y, int w, int h)
    :Entity(eventBus, path, index, x, y, w, h)
{}

void Button::update(){}

void Button::onNotify(SDL_Event event)
{
}
