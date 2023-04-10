#include "CollisionSystem.h"

CollisionSystem::CollisionSystem(){}

CollisionSystem::CollisionSystem(EventBus * eventBus):
    BusNode(COLLISION_SYSTEM,eventBus){};

CollisionSystem::~CollisionSystem()
{
    playerColliders.clear();
    enemyColliders.clear();
    eventBus->removeReceiver(COLLISION_SYSTEM);
}

void CollisionSystem::loadCollider(TextureRect* collider)
{
    if(collider->colliderTag == COLLIDER_PLAYER)
    {
        playerColliders.push_back(collider);
    }
    else if (collider->colliderTag == COLLIDER_ENEMY)
    {
        enemyColliders.push_back(collider);
    }
}

void CollisionSystem::flushRect()
{
    playerColliders.clear();
    enemyColliders.clear();
}

void CollisionSystem::onNotify(SDL_Event event)
{
    printf("Collision System onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        printf("Collision System received user event\n");
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("Collision System received GL_LOAD_INITIAL\n");
            userEvent1 = *(Uint32*)event.user.data1;
            sendEvent(RS_LOAD_COLLIDERS, &playerColliders,&enemyColliders);
        }
        if(event.user.code == CS_LOAD_COLLIDER)
        {
            printf("Collision System received CS_LOAD_COLLIDER\n");
            loadCollider((TextureRect*)event.user.data1);
        }
        if(event.user.code == CS_FLUSHRECT)
        {
            printf("Collision System received CS_FLUSHRECT\n");
            flushRect();
        }
    }
}
