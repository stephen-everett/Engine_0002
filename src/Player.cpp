#include "Player.h"
#include <cmath>

Player::Player()
    :Entity(PLAYER, eventBus, PATH_PLAYERMODEL, INDX_PLAYER, WINDOW_WIDTH/2-25, WINDOW_HEIGHT-75,50,50)
{}

Player::~Player()
{
    printf("Player destructing!\n");
    eventBus->removeReceiver(PLAYER);
}

Player::Player(EventBus* eventBus, Mouse* mouse)
    :Entity(PLAYER, eventBus, PATH_PLAYERMODEL, INDX_PLAYER, WINDOW_WIDTH/2-25, WINDOW_HEIGHT-75,50,50)
{
    this->mouse = mouse;
    SDL_ShowCursor(SDL_ENABLE);
}

void Player::update()
{
    if(movingUp)
    {
        printf("movingUp!\n");
        entityData.dimensions.y -= 10;
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
    int centerx = entityData.dimensions.x + (entityData.dimensions.w / 2);
    int centery = entityData.dimensions.y + (entityData.dimensions.y)/ 2;
    int deltaX = centerx - mousex;
    int deltaY = centery - mousey;
    entityData.angle = ((atan2(-deltaX,deltaY)) * (180/3.1416));
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
}

