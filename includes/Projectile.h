#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "TextureRect.h"

class Projectile
{
    public:
        Projectile();
        Projectile(const char* texturePath, int textureIndex,int x, int y, int w, int h, bool enabled);
        ~Projectile();
        TextureRect* getRect();
    private:
        TextureRect projectileData;
};

#endif
