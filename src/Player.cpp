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
   for(auto it = magazine.begin(); it != magazine.end(); it++)
   {
       if(!fired)
       {
           if(it->enabled == false)
           {
               it->enabled = true;
               it->dimensions.x = entityData.dimensions.x + (entityData.dimensions.w/2-10);
               it->dimensions.y = entityData.dimensions.y;
               it->pathX = 25*sin(angle);
               it->pathY = 25*cos(angle);
               fired = true;
           }
       }
   }
}

void Player::update()
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

    if(frameCounter == 10)
    {
        frameCounter = 0;
    }
    frameCounter++;
    centerx = entityData.dimensions.x + (entityData.dimensions.w / 2);
    centery = entityData.dimensions.y + (entityData.dimensions.y)/ 2;
    deltaX = centerx - mousex;
    deltaY = centery - mousey;
  //  entityData.dimensions.y = WINDOW_HEIGHT/2-50;
    angle = atan2(-deltaX,deltaY);
    entityData.angle = (angle) * (180.0000000000/3.1416);
    //entityData.angle = 90;
    double slope = tan(angle);
    if(movingUp)
    {
        if(frameCounter == 10)
        {
            speedUp++;
        }
        if(speedUp > 5)
        {
            speedUp = 5;
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
        entityData.dimensions.y += 10;
    }
    if(movingLeft)
    {
        entityData.dimensions.x -= 10;
    }
    if(movingRight)
    {
        entityData.dimensions.x += 10;
    }
    //entityData.angle = (atan2((mousey - entityData.dimensions.y), (mousex - entityData.dimensions.x)))*(180/3.14);
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
        }
        if(event.key.keysym.sym == SDLK_s)
        {
            movingDown = false;
        }
        if(event.key.keysym.sym == SDLK_d)
        {
            movingRight = false;
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

