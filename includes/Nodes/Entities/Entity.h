#ifndef ENTITY_H
#define ENTITY_H
#include "BusNode.h"

class Entity : public BusNode
{
    public:
        Entity();
        ~Entity();
        Entity(EventBus * eventBus);
        Entity(EventBus* eventBus, const char* path,int index, int x, int y, int w, int h);
        void update();
        TextureRect* getRect();
        TextureRect * getTextureRect();
    protected:
        void onNotify(SDL_Event event);
        TextureRect  entityData;
    private:
        bool empty;
};
#endif
