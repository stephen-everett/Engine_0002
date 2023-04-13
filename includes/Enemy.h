#ifndef ENEMY_H
#define ENEMY_H
#include "TextureRect.h"

class Enemy
{
    public:
        Enemy();
        TextureRect* getTextureRect();
        void update();
    private:
        TextureRect entityData;
};

#endif
