#ifndef BUTTON_H
#define BUTTON_H
#include "Entity.h"

class Button: public Entity
{
    public:
        Button();
        Button(EventBus * eventBus, const char* path, int index, int x, int y, int w, int h);
        ~Button();
        void update();
    private:
        void onNotify(SDL_Event event);

};

#endif
