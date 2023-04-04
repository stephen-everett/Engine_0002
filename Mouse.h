#ifndef MOUSE_H
#define MOUSE_H
#include "Entity.h"

class Mouse : Entity
{
    Mouse();
    Mouse(EventBus * eventBus);
    ~Mouse();
};
#endif
