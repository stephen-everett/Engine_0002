#include "Projectile.h"

Projectile::Projectile(){}

Projectile::Projectile(const char* texturePath, int textureIndex, int x, int y, int w, int h, bool enabled)
{
    projectileData.texturePath = texturePath;
    projectileData. textureIndex = textureIndex;
    projectileData.dimensions.x = x;
    projectileData.dimensions.y = y;
    projectileData.dimensions.h = h;
    projectileData.dimensions.w = w;
    projectileData.enabled = enabled;
}

Projectile::~Projectile(){}

TextureRect* Projectile::getRect()
{
    return &projectileData;
}

