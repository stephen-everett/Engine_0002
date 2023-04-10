#include "MainMenu.h"

MainMenu::MainMenu(){}

MainMenu::MainMenu(EventBus* eventBus,Mouse* mouse):BusNode(MAINMENU,eventBus),
    startButton(eventBus,
            mouse,
            PATH_BUTTON_START,
            INDX_START_BUTTON,
            WINDOW_WIDTH/2-150, 
            WINDOW_HEIGHT/2-50,
            300,100)
            
{
    SDL_ShowCursor(SDL_DISABLE);
   // Background 
    staticAssets.emplace_back(
            PATH_MAINMENU_BACKGROUND,
            INDX_MAIN_MENU,
            0,0,
            WINDOW_WIDTH,
            WINDOW_HEIGHT);

    // Title
    staticAssets.emplace_back(
            PATH_MAIN_TITLE,
            INDX_TITLE,
            WINDOW_WIDTH/2-320,0,
            640,
            200);

    printf("Main menu created!\n");
    this->mouse = mouse;
}
MainMenu::~MainMenu()
{
    printf("Main menu being destructed!\n");
    eventBus->removeReceiver(MAINMENU);
}
void MainMenu::update(){}

void MainMenu::requestTextures()
{
    for (auto it = staticAssets.begin(); it != staticAssets.end(); it++)
    {
        sendEvent(RM_SET_TEXTURE, &(*it), NULL);
    }
}

void MainMenu::onNotify(SDL_Event event)
{
    printf("--- MainMenu onNotify ---\n");
    if(event.type == SDL_USEREVENT)
    {
        if(event.user.code == GL_LOAD_INITIAL)
        {
            printf("Main menu received GL_LOAD_INITIAL\n");
            userEvent1 = *(Uint32*)event.user.data1;
            sendEvent(SYS_READY);
        }
        if(event.user.code == E_GET_TEXTURES)
        {
            requestTextures();
        }
    }
}

