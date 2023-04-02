#include "RenderSystem.h"
#include <SDL2/SDL_image.h>
//#include "Asset.h"
RenderSystem::RenderSystem(){}

RenderSystem::RenderSystem(EventBus * eventBus) : BusNode(eventBus)
{
    init();
    createWindow();
    createRenderer();
    draw();
    numberOfAssets = 0;
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
/*
bool RenderSystem::quitStatus()
{
    return quit;
}
*/

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

/*
void RenderSystem::eventQueue()
{
   while(SDL_PollEvent(&e))
   {
       if(e.type == SDL_QUIT)
       {
           quit = true;
       }
   }
}
*/

/*
void RenderSystem::loadAssets(std::vector<Asset*> *ass)
{
    allAssets = ass;
    if(allAssets == NULL)
    {
        printf("Problem loading asset vector!\n");
    }

    for(auto it = begin(*allAssets); it != end(*allAssets);++it)
    {
        loadAsset(*it);
    }
}

void RenderSystem::loadStaticAssets(std::vector<Asset*> *ass)
{
    allAssets = ass;
    if(allAssets == NULL)
    {
        printf("Problem loading asset vector!\n");
    }

    for(auto it = begin(*allAssets); it != end(*allAssets);++it)
    {
        loadStaticAsset(*it);
    }
    allAssets = NULL;
}

void RenderSystem::loadAsset(Asset * asset)
{
    surface = IMG_Load(asset->path);
    if (surface == NULL)
    {
        printf("Problem loading surface image! %s\n", SDL_GetError());
    }
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL)
    {
        printf("Problem creating texture! %s\n", SDL_GetError());
    }
    SDL_FreeSurface(surface);
    TextureRect textureStruct;
    textureStruct.texture = texture;
    textureStruct.tag = asset->tag;
    textureStruct.dimensions.x = asset->x;
    textureStruct.dimensions.y = asset->y;
    textureStruct.dimensions.h = asset->h;
    textureStruct.dimensions.w = asset->w;

    textures.push_back(textureStruct);

}

void RenderSystem::loadStaticAsset(Asset * asset)
{
    surface = IMG_Load(asset->path);
    if (surface == NULL)
    {
        printf("Problem loading surface image! %s\n", SDL_GetError());
    }
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL)
    {
        printf("Problem creating texture! %s\n", SDL_GetError());
    }
    SDL_FreeSurface(surface);
    TextureRect textureStruct;
    textureStruct.texture = texture;
    textureStruct.tag = asset->tag;
    textureStruct.dimensions.x = asset->x;
    textureStruct.dimensions.y = asset->y;
    textureStruct.dimensions.h = asset->h;
    textureStruct.dimensions.w = asset->w;

    staticTextures.push_back(textureStruct);

}

// Very Ineffecient. Need to improve. O(n^2)
void RenderSystem::update(std::vector<Asset*> *ass, const char* name)
{
    //printf("%s",textures[0].tag);
    for(auto it = begin(textures); it != end(textures); ++it)
    {
        if(it->tag == name)
        {
            for (auto jt = begin(*ass); jt != end(*ass); ++jt)
            {
                if ((*jt)->tag == name)
                {
                    it->dimensions.x = (*jt)->x;
                    it->dimensions.y = (*jt)->y;
                }
            }
        }
    }
}
*/
void RenderSystem::update(){};
void RenderSystem::draw()
{
    
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);

    for(auto it = loadedRectangles->begin(); it != loadedRectangles->end();++it)
    {
        texture = (*it)->texture;
        SDL_Rect rect = (*it)->dimensions;
        SDL_RenderCopy(renderer,texture,NULL,&rect);
    }

   /* 
    for(auto it = begin(staticTextures); it != end(staticTextures); ++it)
    {
        if (debug)
        {
            SDL_RenderDrawRect(renderer,&(*it)->dimensions);
        }

        SDL_RenderCopy(renderer,(*it)->texture,NULL,&(*it)->dimensions);
    }
    */
    /*
    for(auto it = begin(textures); it != end(textures); ++it)
    {
        if (debug)
        {
            SDL_RenderDrawRect(renderer,&*it->dimensions);
        }
        SDL_RenderCopy(renderer,*it->texture,NULL,&*it->dimensions);
    }
    */
   
    SDL_RenderPresent(renderer);
    int size = textures.size();
    //printf("%u\n",size);
    SDL_Delay(17);
}

void RenderSystem::setDebug(bool state)
{
    debug = state;
}

void RenderSystem::onNotify(SDL_Event event)
{
    printf("Render System onNotify()\n");
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == LOAD_LEVEL)
        {
            /*
            printf("Render System received code: LOAD_LEVEL\n");
            loadStaticAssets((std::vector<TextureRect*>*)event.user.data1);
            //testLoad((std::vector<int>*)event.user.data1);
            testLoad2((std::vector<int*>*)event.user.data2);
            */
            
        }
        if(event.user.code == LOAD_TEXTURE)
        {
            printf("--- Received LOAD_TEXTURE RenderSystem---\n");
        }
        if(event.user.code == LOAD_INITIAL)
        {
            printf("--- Received LOAD_INITIAL RenderSystem---\n");
            userEvent1 = *(Uint32*)event.user.data1;
        }
        if(event.user.code == TEST_EVENT)
        {
            printf("--- Received TEST_EVENT RenderSystem---\n");
        }
        if(event.user.code == TEST_RENDER)
        {
            printf("--- Received TEST_RENDER RenderSystem---\n");
        }
        if(event.user.code == LOAD_TEXTURE)
        {
            printf("--- Received LOAD_TEXTURE ---\n");
        }
        if(event.user.code == CREATE_TEXTURE)
        {
            printf("--- Received CREATE_TEXTURE RenderSystem ---\n");
            createTexture((TextureRect*)event.user.data1);
        }
        if(event.user.code == RM_INIT)
        {
            printf("---Received RM_INIT---\n");
            loadedTextures = (SDL_Texture*)event.user.data1;
            loadedRectangles = (std::vector<TextureRect*>*)event.user.data2;
        }   
    }
}

void RenderSystem::createTexture(TextureRect* givenRect)
{
    surface = IMG_Load(givenRect->texturePath);
    givenRect->texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
}

void RenderSystem::testLoad2(std::vector<int*>*x)
{
    printf("Called testload2\n");
    if(*(x->front()) == 0)
    {
        printf("Got X from testLoad2!\n");
    }
    else
    {
        printf("Problem with testLoad2!\n");
    }
}

void RenderSystem::testLoad(std::vector<int>* x)
{
    if (x->front() == 0)
    {
        printf("Received X!\n");
    }
    else
    {
        printf("Problem with testLoad()\n");
    }
}
void RenderSystem::loadStaticAssets(std::vector<TextureRect*>* staticAssVec)
{
    /*
    TextureRect * test = staticAssVec->front(); 
    SDL_Rect testSDLRect = test->dimensions;
    int x = testSDLRect.x;
    if (x == 0)
    {
        printf("Got X from structure!\n");
    }
    if((staticAssVec->front())->dimensions.x == 0)
    {
        printf("Got X directly from structure!\n");
    }
   
    for( auto it = staticAssVec->begin(); it != staticAssVec->end(); ++it )
    {
        printf("Iterating through structure!\n");
        surface = IMG_Load((*it)->tag);
        (*it)->texture = SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);
        staticTextures.push_back(*it);
        int size = staticTextures.size();
        printf("Size of staticTextures after loop: %i\n",size);


    }
    */
 
    /*
    printf("Passed the asset to loadStaticAssets successfully\n");
    TextureRect * temp = staticAssVec->front();
    surface = IMG_Load(temp.tag);
    if(surface == NULL)
    {
        printf("Problem loading surface\n");
    }
    else
    {
        temp.texture = SDL_CreateTextureFromSurface(renderer,surface);
        if (temp.texture == NULL)
        {
            printf("problem loading texture\n");
        }
    }
    SDL_FreeSurface(surface);
    surface = NULL;


    staticTextures.push_back(temp);
    */
}
