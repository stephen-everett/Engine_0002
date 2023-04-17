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
    :Entity(PLAYER, eventBus, PATH_PLAYERMODEL, INDX_PLAYER, WINDOW_WIDTH/2-50, WINDOW_HEIGHT-150,47,56),
    locationFinder()
{
    entityData.colliderTag = COLLIDER_PLAYER;
    this->clock = clock;
    this->mouse = mouse;
    SDL_ShowCursor(SDL_ENABLE);
    speedLimit = 7;
    speedUp = 0;
    speedDown = 0;
    speedLeft = 0;
    speedRight = 0;
    frameCounter = 0;

    rightFrame = 0;
    leftFrame = 0;
    upFrame = 0;
    deltaTime = clock->getElapsedTime(); 

    rotationPointOffsetX = 0;
    rotationPointOffsetY = 0;
    weapons.emplace_back(&entityData,POSITION_LEFT);
    weapons.emplace_back(&entityData,POSITION_RIGHT);
}

void Player::setSpeedLimit(int limit)
{
    speedLimit = limit;
}

void Player::fire()
{
    weapons[0].fire();
    weapons[1].fire();
}

void Player::updatePositions()
{
    printf("Rotation Offset X: %i\n",rotationPointOffsetX);
    printf("Rotation Offset Y: %i\n", rotationPointOffsetY); 
    entityData.centerx = entityData.dimensions.x + (entityData.dimensions.w / 2);
    entityData.centery = entityData.dimensions.y + (entityData.dimensions.h)/ 2;

    deltaX = entityData.centerx - mousex;
    deltaY = entityData.centery - mousey;

    entityData.angleRads = atan2(-deltaX,deltaY);
    entityData.angle = (entityData.angleRads) * (180.0000000000/3.1416);

    double slope = tan(angle);

    entityData.rotationPoint.x = entityData.dimensions.w/2;
    entityData.rotationPoint.y = entityData.dimensions.h/2;


    //locationFinder.dimensions.x = entityData.centerx + 34*cos(angle-2.722);
    //locationFinder.dimensions.y = entityData.centery + 34*sin(angle-2.722);

}

void Player::updateProjectiles()
{
       weapons[0].update();
       weapons[1].update();
}

void Player::update()
{
    if(entityData.texture == NULL)
    {
        printf("No player texture found!\n");
    }
    updatePositions();
    calculateTrajectory();
    if(clock->isTime())
    {
        move();
        updateProjectiles();
    }
       
}

void Player::calculateTrajectory()
{
    trajectoryY = cos(entityData.angleRads);
    trajectoryX = sin(entityData.angleRads);
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
        if(upFrame < 2)
        {
            if(deltaTime < clock->getElapsedTime())
            {
                entityData.drawRect.x += 47;
                deltaTime = clock->getElapsedTime() +0.25;
                upFrame++;
            }
        }
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
void Player::sendColliders()
{

    entityData.colliderTag = COLLIDER_PLAYER;
    sendEvent(CS_LOAD_COLLIDER,&entityData,NULL);

    std::vector<TextureRect>* temp = weapons[0].getRenderData();
    for(auto it = temp->begin(); it != temp->end(); it++)
    {
        sendEvent(CS_LOAD_COLLIDER,&(*it),NULL);
    }
    temp = weapons[1].getRenderData();
    for(auto it = temp->begin(); it != temp->end(); it++)
    {
        sendEvent(CS_LOAD_COLLIDER,&(*it),NULL);
    }
}

void Player::requestTextures()
{
    Entity::requestTextures();
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
            if(!movingUp)
            {
                entityData.drawRect.x = 0;
                entityData.drawRect.y = 0;
                movingUp = true;

            }
            break;

        case SDLK_a:
            if(!movingLeft)
            {
                movingLeft = true;
                entityData.drawRect.x = 0;
                entityData.drawRect.y = (2*entityData.dimensions.h);
            }
            break;
        
        case SDLK_s:
            movingDown = true;
            break;
        
        case SDLK_d:
            if(!movingRight)
            {
                movingRight = true;
                entityData.drawRect.x = 0;
                entityData.drawRect.y = entityData.dimensions.h;
            }
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
        case SDLK_l:
            sendEvent(RM_SET_TEXTURE,&entityData,NULL);
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
            entityData.drawRect.x = 0;
            entityData.drawRect.y = 0;
            upFrame = 0;
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

