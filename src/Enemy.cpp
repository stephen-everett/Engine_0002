#include "Enemy.h"
#include "EventEnums.h"

Enemy::Enemy()
{
    entityData.enabled = true;
    entityData.pathX = 5;
    entityData.pathY = 0;
    entityData.texturePath = PATH_TESTMODEL;
    entityData.dimensions.x = 50;
    entityData.dimensions.y = 50;
    entityData.dimensions.h = 50;
    entityData.dimensions.w = 50;
    entityData.textureIndex = INDX_ENEMY;
    entityData.isCollided = false;
    entityData.colliderTag = COLLIDER_ENEMY;
    
    entityData.drawRect.x = 0;
    entityData.drawRect.y = 0;
    entityData.drawRect.h = 50;
    entityData.drawRect.w = 50;
    
}

void Enemy::update()
{
    if(entityData.enabled == true)
    {
        entityData.dimensions.x += entityData.pathX;
        if(entityData.dimensions.x == WINDOW_WIDTH -50)
        {
            entityData.pathX = -5;
        }
        else if (entityData.dimensions.x == 0)
        {
            entityData.pathX = 5;
        }
    }
    printf("Hit Count: %i\n",entityData.collisionCount);
    if(entityData.collisionCount == 10)
    {
        entityData.drawRect.x += 50;
        entityData.collisionCount++;
    }
    if(entityData.collisionCount == 20)
    {
        entityData.drawRect.x +=50;
        entityData.collisionCount++;
    }
    if(entityData.collisionCount == 30)
    {
        entityData.drawRect.x +=50;
        entityData.collisionCount++;
    }
                

}

TextureRect* Enemy::getTextureRect()
{
    return &entityData;
}
