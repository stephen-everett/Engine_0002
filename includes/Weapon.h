#ifndef WEAPON_H
#define WEAPON_H
#include "TextureRect.h"
#include "Projectile.h"
#include "EventEnums.h"
#include <vector>

class Weapon
{
    public:
        Weapon();
        Weapon(TextureRect* attachPoint, WeaponPosition position);
        ~Weapon();
        void update();
        void fire();
        void setProjectiles(TextureRect* newProjectile);
        TextureRect* getProjectileData();
        std::vector<TextureRect>* getRenderData();
        void increaseOffset();
        void decreaseOffset();
        
    private:
        void updateMountPosition();
        void updateProjectilePosition();
        void placeLeft();
        void placeRight();
        //std::vector<Projectile> magazine;
        WeaponPosition position;
        int mountPointX;
        int mountPointY;

        int circleSize;

        double circleSin;
        double circleCos;

        double offset;

        std::vector<TextureRect> magazine;
        std::vector<TextureRect*> bulletData;
        TextureRect projectileData;
        TextureRect *attachedTo;
};

#endif
