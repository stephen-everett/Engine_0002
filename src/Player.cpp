#include "Player.h"
#include <cmath>

Player::Player()
    :Entity(PLAYER, eventBus, PATH_PLAYERMODEL, INDX_PLAYER, WINDOW_WIDTH/2-50, WINDOW_HEIGHT-50,50,50)
{}

Player::~Player()
{
    printf("Player destructing!\n");
    eventBus->removeReceiver(PLAYER);
}

Player::Player(EventBus* eventBus, Mouse* mouse,GameTime* clock)
    :Entity(PLAYER, eventBus, PATH_PLAYERMODEL, INDX_PLAYER, WINDOW_WIDTH/2-50, WINDOW_HEIGHT-150,100,100),
    locationFinder()
{
    this->clock = clock;
    this->mouse = mouse;
    SDL_ShowCursor(SDL_ENABLE);
    speedLimit = 7;
    speedUp = 0;
    speedDown = 0;
    speedLeft = 0;
    speedRight = 0;
    frameCounter = 0;
    rotationPointOffsetX = 0;
    rotationPointOffsetY = 0;
    for (int i = 0; i < 30; i++)
    {
        magazine.emplace_back(
                PATH_BULLET,
                INDX_BULLET,
                0,0,
                20,20,
                false);
    }
}

void Player::setSpeedLimit(int limit)
{
    speedLimit = limit;
}

void Player::fire()
{
   bool fired = false;
   bool firedLeft = false;
   for(auto it = magazine.begin(); it != magazine.end(); it++)
   {
       if(!fired)
       {
           if(it->enabled == false)
           {
               if(!firedLeft)
               {
                   
                   it->enabled = true;
                   //it->dimensions.x = entityData.dimensions.x + sin(angle);
                   //it->dimensions.y = entityData.dimensions.y + 2*cos(angle);
                   //it->dimensions.x = entityData.dimensions.x+10;
                   //it->dimensions.y = entityData.dimensions.y + 15;
                   it->dimensions.x = centerx - 28*cos(angle) -10;
                   it->dimensions.y = centery - 28*sin(angle) -10;
                   //it->rotationPoint.x = entityData.rotationPoint.x-10;
                   //it->rotationPoint.y = entityData.rotationPoint.y-20;
                   //it->colliderRect.x = centerx + 28*cos(angle)-5 ;//entityData.dimensions.x+sin(angle);
                   //it->colliderRect.y = centery + 28*sin(angle)-5 ;//entityData.dimensions.y+cos(angle);;
                   it->angle = entityData.angle;
                   it->pathX = 25*sin(angle);
                   it->pathY = 25*cos(angle);
                   
                   firedLeft = true;
               }
               else
               {
                   
                   it->enabled = true;
                   it->dimensions.x = centerx + 28*cos(angle) -5;//entityData.dimensions.x+75;
                   it->dimensions.y = centery + 28*sin(angle) -5;//entityData.dimensions.y + 15;
                   //it->rotationPoint.x = entityData.rotationPoint.x-80;
                   //it->rotationPoint.y = entityData.rotationPoint.y-15;
                   //it->colliderRect.x = entityData.dimensions.x+50;
                   //it->colliderRect.y = entityData.dimensions.y;
                   it->angle = entityData.angle;
                   it->pathX = 25*sin(angle);
                   it->pathY = 25*cos(angle);
                   fired = true;
                   

               }
           }
       }
   }
}

void Player::updatePositions()
{
    printf("Rotation Offset X: %i\n",rotationPointOffsetX);
    printf("Rotation Offset Y: %i\n", rotationPointOffsetY); 
    centerx = entityData.dimensions.x + (entityData.dimensions.w / 2);
    centery = entityData.dimensions.y + (entityData.dimensions.h)/ 2;

    deltaX = centerx - mousex;
    deltaY = centery - mousey;

    angle = atan2(-deltaX,deltaY);
    entityData.angle = (angle) * (180.0000000000/3.1416);

    double slope = tan(angle);

    entityData.rotationPoint.x = entityData.dimensions.w/2;
    entityData.rotationPoint.y = entityData.dimensions.h/2;

    //locationFinder.dimensions.x = centerx + 36*cos(angle-.369);
    //locationFinder.dimensions.y = centery + 36*sin(angle-.369);

    locationFinder.dimensions.x = centerx + 34*cos(angle-2.722);
    locationFinder.dimensions.y = centery + 34*sin(angle-2.722);

}

void Player::updateProjectiles()
{
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
}

void Player::update()
{
    updatePositions();
    calculateTrajectory();
    if(clock->isTime())
    {
        move();
        updateProjectiles();
       
        printf("Inside Second calculator\n");
    }
    else
    {
        printf("Not time yet\n");
    }
}

void Player::calculateTrajectory()
{
    trajectoryY = cos(angle);
    trajectoryX = sin(angle);
}

void Player::move()
{
    moveUp();
    moveDown();
    moveLeft();
    moveRight();
}

void Player::moveUp()
{
    if(movingUp)
    {
        printf("Moving Up!\n");
        speedUp++;
        if(speedUp > speedLimit)
        {
            speedUp = speedLimit;
        }
        printf("x location: %i " ,entityData.dimensions.x);
        printf("y location: %i " ,entityData.dimensions.y);
        printf("x step: %0.2f ", (speedUp * trajectoryX));
        printf("y step: %0.2f ", (speedUp * trajectoryY));
        double xStep = speedUp * trajectoryX;
        if (xStep > speedLimit)
        {
            xStep = speedLimit;
        }
        else if (xStep > 0.5 && xStep < 1)
        {
            xStep = 1;
        }
        double yStep = speedUp * trajectoryY;
        if(yStep > speedLimit)
        {
            yStep = speedLimit;
        }
        else if (yStep > 0.5 && yStep < 1)
        {
            yStep = 1;
        }
        entityData.dimensions.x +=  xStep;//(int)(speedUp * trajectoryX);
        entityData.dimensions.y -=  yStep;//(int)(speedUp * trajectoryY);

        printf("Entity angle: %.2f ",entityData.angle);
        printf("Radian angle: %.2f \n", angle);
        
    }
}

void Player::moveDown()
{
    if(movingDown)
    {
        printf("Moving Down!\n");
        speedDown++;
        if(speedDown > speedLimit)
        {
            speedDown = speedLimit;
        }
        entityData.dimensions.y += speedDown;
    }
}

void Player::moveLeft()
{
    if(movingLeft)
    {
        printf("Moving Left!\n");
        speedLeft++;
        if(speedLeft > speedLimit)
        {
            speedLeft = speedLimit;
        }
        entityData.dimensions.x -= speedLeft;
    }
}

void Player::moveRight()
{
    if(movingRight)
    {
        printf("Moving right!\n");
        speedRight++;
        if(speedRight > speedLimit)
        {
            speedRight = speedLimit;
        }
        entityData.dimensions.x += speedRight;
        printf("Speed Right: %i\n",speedRight);
    }
}

void Player::keyPressed(SDL_Keycode key)
{
    switch(key)
    {
        case SDLK_w:
            printf("Received W key!\n");
            movingUp = true;
            break;

        case SDLK_a:
            movingLeft = true;
            break;
        
        case SDLK_s:
            movingDown = true;
            break;
        
        case SDLK_d:
            movingRight = true;
            break;
        case SDLK_t:
            rotationPointOffsetY += 10;
            break;
        
        case SDLK_f:
            rotationPointOffsetX -= 10;
            break;
        
        case SDLK_g:
            rotationPointOffsetY -= 10;
            break;
        
        case SDLK_h:
            rotationPointOffsetX += 10;
            break;
    }
}

void Player::keyReleased(SDL_Keycode key)
{
    switch(key)
    {
        case SDLK_w:
            printf("Received W key!\n");
            movingUp = false;
            speedUp = 0;
            break;
        
        case SDLK_a:
            movingLeft = false;
            speedLeft = 0;
            break;
        
        case SDLK_s:
            movingDown = false;
            speedDown = 0;
            break; 
        case SDLK_d:
            movingRight = false;
            speedRight = 0;
            break;
    }
    
}

void Player::sendColliders()
{
    locationFinder.colliderTag = COLLIDER_PLAYER;
    locationFinder.enabled = true; 
    locationFinder.dimensions.h = 20;
    locationFinder.dimensions.w = 20;
    entityData.colliderTag = COLLIDER_PLAYER;
    sendEvent(CS_LOAD_COLLIDER,&locationFinder,NULL);
    sendEvent(CS_LOAD_COLLIDER,&entityData,NULL);
    for(auto it = magazine.begin(); it != magazine.end(); it++)
    {
        it->colliderTag = COLLIDER_PLAYER;
        sendEvent(CS_LOAD_COLLIDER,&(*it),NULL);
    }
}

void Player::requestTextures()
{
    Entity::requestTextures();
    for(auto it = magazine.begin(); it != magazine.end(); it++)
    {
        sendEvent(RM_SET_TEXTURE,&(*it),NULL);
    }
}

void Player::onNotify(SDL_Event event)
{
    printf("Player onNotify()\n");
    switch(event.type)
    {
        case SDL_USEREVENT:
            switch(event.user.code)
            {
                case GL_LOAD_INITIAL:
                    printf("Player received GL_LOAD_INITIAL\n");
                    userEvent1 = *(Uint32*)event.user.data1;
                    sendColliders();
                    break;

                case E_GET_TEXTURES:
                    printf("Player received E_GET_TEXTURES\n");
                    requestTextures();
                    break;

                case UPDATE:
                    printf("Player Received update!\n");
                    update();
                    break;
            }
            break;

        case SDL_KEYDOWN:
            keyPressed(event.key.keysym.sym);
            break;

        case SDL_KEYUP:
            keyReleased(event.key.keysym.sym);
            break;

        case SDL_MOUSEMOTION:
            printf("Player received mouse motion!\n");
            SDL_GetMouseState(&mousex,&mousey);
            break;

        case SDL_MOUSEBUTTONDOWN:
            fire();
            break;
    }
}

