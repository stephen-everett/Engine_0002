#include "MainMenu.h"

MainMenu::MainMenu(){}

MainMenu::MainMenu(EventBus* eventBus,Mouse* mouse):BusNode(MAINMENU,eventBus),
    background(eventBus,
            PATH_MAINMENU_BACKGROUND,
            INDX_MAIN_MENU,
            0,0,
            WINDOW_WIDTH,WINDOW_HEIGHT),
    
    startButton(eventBus,
            mouse,
            PATH_BUTTON_START,
            INDX_START_BUTTON,
            200,200,
            300,100)
            
{
    printf("Main menu created!\n");
    this->mouse = mouse;
}
MainMenu::~MainMenu()
{
    printf("Main menu being destructed!\n");
    eventBus->removeReceiver(MAINMENU);
}
void MainMenu::update(){}

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
    }
}

