#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H
#include "BusNode.h"


class CollisionSystem: public BusNode
{
    public:
        CollisionSystem();
        CollisionSystem(EventBus* eventBus);
        ~CollisionSystem();
    protected:
        void onNotify(SDL_Event event);
        void flushRect();
        void loadCollider(TextureRect* collider);
        void update();
    private:
        std::vector<TextureRect* > playerColliders;
        std::vector<TextureRect* > enemyColliders;
};


#endif
