#ifndef ENTITY_H
#define ENTITY_H
#include "BusNode.h"

class Entity : public BusNode
{
    public:
        Entity();
        ~Entity();
        Entity(EventBus * bus);
        Entity(EventBus* bus, const char* path, int x, int y, int w, int h);
        void update();
        TextureRect * getTextureRect();
    protected:
        void onNotify(SDL_Event event);
    private:
        TextureRect  entityData;
};
#endif
