#include "RenderSystem.h"
#include <SDL2/SDL_image.h>
//#include "Asset.h"
RenderSystem::RenderSystem(){}

RenderSystem::RenderSystem(EventBus * eventBus) : BusNode(RENDER_SYSTEM,eventBus)
{
    init();
    createWindow();
    createRenderer();
}

RenderSystem::~RenderSystem()
{
    printf("RenderSystem destructing!");
    SDL_Quit();
}
void RenderSystem::init()
{
   if((SDL_INIT_VIDEO) < 0)
   {
       printf("Could not initialize video subsystem! %s\n",SDL_GetError());
   }
}

void RenderSystem::close()
{
    SDL_Quit();
}

void RenderSystem::createWindow()
{
    window = SDL_CreateWindow(WINDOWNAME,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,0);
    if( window == NULL)
    {
        printf("Could not create window! %s\n", SDL_GetError());
    }
}

void RenderSystem::createRenderer()
{
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! %s\n",SDL_GetError());
    }
}

void RenderSystem::createTexture(TextureRect* givenRect)
{
    surface = IMG_Load(givenRect->texturePath);
    givenRect->texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    sendEvent(RM_SAVE_TEXTURE,givenRect,NULL);
}

void RenderSystem::update(){};

void RenderSystem::draw()
{
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);

    if (loadedRectangles != NULL)
    {
        int temp = loadedRectangles->size();
        printf("--- Size of loadedRectangles in RS::draw() : %i\n",temp);
        for(auto it = loadedRectangles->begin(); it != loadedRectangles->end();++it)
        {
            bool enabled = (*it)->enabled;
            texture = (*it)->texture;
            SDL_Rect rect = (*it)->dimensions;
            int angle = (*it)->angle;
            if(enabled)
            {
                SDL_RenderCopyEx(renderer,texture,NULL,&rect,angle,&(*it)->rotationPoint,SDL_FLIP_NONE);
                //SDL_RenderDrawRect(renderer, &rect);
                //SDL_RenderDrawLine(renderer,rect.x + (rect.w/2), rect.y, rect.x+(rect.w/2),rect.y+rect.h);
                //SDL_RenderDrawLine(renderer, rect.x,rect.y+(rect.h/2),rect.x+rect.w,rect.y+(rect.h/2));
               // SDL_RenderCopy(renderer,texture,NULL,&rect);
            }
        }
    }
/*
    if (playerColliders != NULL)
    {
        int temp = playerColliders->size();
        printf("--- Size of playerColliders in RS::draw() : %i\n",temp);
        for(auto it = playerColliders->begin(); it != playerColliders->end();++it)
        {
            bool enabled = (*it)->enabled;
            SDL_Rect rect = (*it)->dimensions;
            if(enabled)
            {
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
    if (enemyColliders != NULL)
    {
        int temp = enemyColliders->size();
        printf("--- Size of enemyColliders in RS::draw() : %i\n",temp);
        for(auto it = enemyColliders->begin(); it != enemyColliders->end();++it)
        {
            bool enabled = (*it)->enabled;
            SDL_Rect rect = (*it)->dimensions;
            if(enabled)
            {
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
    */
 
    SDL_RenderPresent(renderer);
    SDL_Delay(17);
}

void RenderSystem::onNotify(SDL_Event event)
{
    printf("Render System onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("--- Received GL_LOAD_INITIAL RenderSystem---\n");
            userEvent1 = *(Uint32*)event.user.data1;
        }
        if(event.user.code == RS_LINK_RESOURCES)
        {
           loadedRectangles = (std::vector<TextureRect*>*)event.user.data1;
           int testSize = loadedRectangles->size();
           printf("--- Size of loadedRectangles: %i\n ---",testSize);
        }
        if(event.user.code == RS_CREATE_TEXTURE)
        {
            createTexture((TextureRect*)event.user.data1);
        }
        if(event.user.code == RS_NULL_VECTOR)
        {
            loadedRectangles = NULL;
            playerColliders = NULL;
            enemyColliders = NULL;
            sendEvent(RM_FLUSHRECT);
            sendEvent(CS_FLUSHRECT);
        }
        if(event.user.code == RS_LOAD_COLLIDERS)
        {
            playerColliders = (std::vector<TextureRect*>*)event.user.data1;
            enemyColliders = (std::vector<TextureRect*>*)event.user.data2;
        }
    }
}


