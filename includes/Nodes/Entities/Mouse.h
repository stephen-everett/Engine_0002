#ifndef MOUSE_H
#define MOUSE_H
#include "Entity.h"

class Mouse : public Entity
{
    public:
        Mouse();
        Mouse(EventBus * eventBus);
        ~Mouse();

        void update();
    protected:
        void onNotify(SDL_Event event);
};
#endif
