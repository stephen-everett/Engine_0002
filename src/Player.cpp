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

Player::Player(EventBus* eventBus, Mouse* mouse)
    :Entity(PLAYER, eventBus, PATH_PLAYERMODEL, INDX_PLAYER, WINDOW_WIDTH/2-50, WINDOW_HEIGHT-150,100,100)
{
    this->mouse = mouse;
    SDL_ShowCursor(SDL_ENABLE);
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
                   it->dimensions.x = entityData.dimensions.x+10;
                   it->dimensions.y = entityData.dimensions.y + 15;
                   it->rotationPoint.x = entityData.rotationPoint.x-10;
                   it->rotationPoint.y = entityData.rotationPoint.y-20;
                   it->colliderRect.x = entityData.dimensions.x;
                   it->colliderRect.y = entityData.dimensions.y;
                   it->angle = entityData.angle;
                   it->pathX = 25*sin(angle);
                   it->pathY = 25*cos(angle);
                   
                   firedLeft = true;
               }
               else
               {
                   it->enabled = true;
                   it->dimensions.x = entityData.dimensions.x+75;
                   it->dimensions.y = entityData.dimensions.y + 15;
                   it->rotationPoint.x = entityData.rotationPoint.x-80;
                   it->rotationPoint.y = entityData.rotationPoint.y-15;
                   it->colliderRect.x = entityData.dimensions.x+50;
                   it->colliderRect.y = entityData.dimensions.y;
                   it->angle = entityData.angle;
                   it->pathX = 25*sin(angle);
                   it->pathY = 25*cos(angle);
                   fired = true;

               }
           }
       }
   }
}

void Player::update()
{
    printf("Rotation Offset X: %i\n",rotationPointOffsetX);
    printf("Rotation Offset Y: %i\n", rotationPointOffsetY); 
    centerx = entityData.dimensions.x + (entityData.dimensions.w / 2);
    centery = entityData.dimensions.y + (entityData.dimensions.y)/ 2;

    deltaX = centerx - mousex;
    deltaY = centery - mousey;

    angle = atan2(-deltaX,deltaY);
    entityData.angle = (angle) * (180.0000000000/3.1416);

    double slope = tan(angle);

    entityData.rotationPoint.x = entityData.dimensions.w/2;
    entityData.rotationPoint.y = entityData.dimensions.h/2;
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

    if(frameCounter == 7)
    {
        frameCounter = 0;
    }
    frameCounter++;

    if(movingUp)
    {
        if(frameCounter == 7)
        {
            speedUp++;
        }
        if(speedUp > 7)
        {
            speedUp = 7;
        }
        int y = speedUp * cos(angle);
        int x = speedUp * sin(angle);
        entityData.dimensions.x += x;
        entityData.dimensions.y -= y;
        /*
        printf("movingUp!\n");
        if (speedUp > 10)
        {
            speedUp = 10;
        }
        entityData.dimensions.y -= speedUp;
        speedUp++;
        */
        printf("Slope: %.2f ",slope);
        printf("Entity angle: %.2f ",entityData.angle);
        printf("Radian angle: %.2f \n", angle);
        //entityData.dimensions.y -= 10*slope;
        //entityData.dimensions.x += 10*slope;
        
    }
    if(movingDown)
    {
        
        if(frameCounter == 7)
        {
            speedDown++;
        }
        if(speedDown > 7)
        {
            speedDown = 7;
        }
        entityData.dimensions.y += speedDown;
    }
    if(movingLeft)
    {
        if(frameCounter == 7)
        {
            speedLeft++;
        }
        if(speedLeft > 7)
        {
            speedLeft = 7;
        }
        entityData.dimensions.x -= speedLeft;
    }
    if(movingRight)
    {
        if(frameCounter == 7)
        {
            speedRight++;
        }
        if(speedRight > 7)
        {
            speedRight = 7;
        }
        entityData.dimensions.x += speedRight;
    }
    //entityData.angle = (atan2((mousey - entityData.dimensions.y), (mousex - entityData.dimensions.x)))*(180/3.14);
}

void Player::sendColliders()
{
    entityData.colliderTag = COLLIDER_PLAYER;
    sendEvent(CS_LOAD_COLLIDER,&entityData,NULL);
    for(auto it = magazine.begin(); it != magazine.end(); it++)
    {
        sendEvent(CS_LOAD_COLLIDER,&(*it),NULL);
    }
}

void Player::onNotify(SDL_Event event)
{
    printf("Player onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("Button GL_LOAD_INITIAL\n");
            userEvent1 = *(Uint32*)event.user.data1;
            sendColliders();
        }
        if(event.user.code == E_GET_TEXTURES)
        {
            printf("Button request textures\n");
            requestTextures();
            for(auto it = magazine.begin(); it != magazine.end(); it++)
            {
                sendEvent(RM_SET_TEXTURE,&(*it),NULL);
            }
        }
    }
    if(event.type == SDL_KEYDOWN)
    {
        printf("Player received keydown event\n");
        if(event.key.keysym.sym == SDLK_w)
        {
            printf("Received W key!\n");
            movingUp = true;
        }
        if(event.key.keysym.sym == SDLK_a)
        {
            movingLeft = true;
        }
        if(event.key.keysym.sym == SDLK_s)
        {
            movingDown = true;
        }
        if(event.key.keysym.sym == SDLK_d)
        {
            movingRight = true;
        }
        if(event.key.keysym.sym == SDLK_t)
        {
            rotationPointOffsetY += 10;
        }
        if(event.key.keysym.sym == SDLK_f)
        {
            rotationPointOffsetX -= 10;
        }
        if(event.key.keysym.sym == SDLK_g)
        {
            rotationPointOffsetY -= 10;
        }
        if(event.key.keysym.sym == SDLK_h)
        {
            rotationPointOffsetX += 10;
        }
    }
    if(event.type == SDL_KEYUP)
    {
        if(event.key.keysym.sym == SDLK_w)
        {
            printf("Received W key!\n");
            movingUp = false;
            speedUp = 0;
        }
        if(event.key.keysym.sym == SDLK_a)
        {
            movingLeft = false;
            speedLeft = 0;
        }
        if(event.key.keysym.sym == SDLK_s)
        {
            movingDown = false;
            speedDown = 0;
        }
        if(event.key.keysym.sym == SDLK_d)
        {
            movingRight = false;
            speedRight = 0;
        }

    }
    if(event.user.code == UPDATE)
    {
        printf("Received update!\n");
        update();
    }
    if(event.type == SDL_MOUSEMOTION)
    {
        printf("Player received mouse motion!\n");
       SDL_GetMouseState(&mousex,&mousey);
    }
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        fire();
    }
}

