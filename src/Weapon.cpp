#include "Weapon.h"
#include "EventEnums.h"

Weapon::Weapon(TextureRect* attachedTo, WeaponPosition position)
{
    this->attachedTo = attachedTo;
    this->position = position;
    offset = 0.0;

    for(int i = 0; i < 100; i++)
    {
        magazine.emplace_back
            (PATH_BULLET,
             INDX_BULLET,
             0,0,
             20,20,
             false);
        magazine[i].colliderTag = this->attachedTo->colliderTag;
    }
    circleSize = 20;
    switch(position)
    {
        case POSITION_LEFT:
            placeLeft();
            break;
        case POSITION_RIGHT:
            placeRight();
            break;
    }
}

Weapon::Weapon(){}

Weapon::~Weapon(){}

void Weapon::update()
{
   updateMountPosition();
   updateProjectilePosition();
}

void Weapon::placeLeft()
{
    circleSin = (circleSize-offset)*sin(attachedTo->angleRads);
    circleCos = (circleSize-offset)*cos(attachedTo->angleRads);
    
    mountPointX = attachedTo->centerx + circleCos;
    mountPointY = attachedTo->centery + circleSin;
}

void Weapon::placeRight()
{
    placeLeft();
    /*
    circleSin = (circleSize-20)*sin(attachedTo->angleRads);
    circleCos = (circleSize-20)*cos(attachedTo->angleRads);

    int offsetSin = circleSize*sin(attachedTo->angleRads +offset);
    int offsetCos = circleSize*cos(attachedTo->angleRads +offset);
    printf("Current offset: %.4f\n",offset);
    
    mountPointX = attachedTo->centerx + offsetCos-10;
    mountPointY = attachedTo->centery + offsetSin;
*/
}

void Weapon::increaseOffset()
{
    offset += 0.1;
}

void Weapon::decreaseOffset()
{
    offset -= 0.1;
}

void Weapon::updateMountPosition()
{
    switch(position)
    {
        case POSITION_LEFT:
            placeLeft();
            break;
        case POSITION_RIGHT:
            placeRight();
            break;
    }
}

void Weapon::updateProjectilePosition()
{
    /*
    for(auto it = magazine.begin(); it != magazine.end(); it++)
    {

        if(it->dimensions.x < 0 || it->dimensions.x > WINDOW_WIDTH)
        {
            it->enabled = false;
        }
        if(it->dimensions.y < 0 || it->dimensions.y > WINDOW_HEIGHT)
        {
            it->enabled = false;
        }
        if(it->enabled)
        {
            it->dimensions.x += it->pathX;
            it->dimensions.y -= it->pathY;
        }
    }
    */
}

void Weapon::fire()
{
    bool fired = false;
    auto it = magazine.begin();
    while(!fired && it != magazine.end())
    {
        if(it->enabled == false)
        {
            it->enabled = true;
            it->dimensions.x = mountPointX;//attachedTo->centerx - 20*cos(attachedTo->angleRads);
            it->dimensions.y = mountPointY;//attachedTo->centery - 20*sin(attachedTo->angleRads);
            it->angle = attachedTo->angle;
            it->pathX = circleSin;//20*sin(attachedTo->angleRads);
            it->pathY = circleCos;//20*cos(attachedTo->angleRads);
            fired = true;
        }
        it++;
    }
}

void Weapon::setProjectiles(TextureRect* newProjectile){}

TextureRect* Weapon::getProjectileData()
{
    return &projectileData;
}

std::vector<TextureRect>* Weapon::getRenderData()
{
    return &magazine;
}
