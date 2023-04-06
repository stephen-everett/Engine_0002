#include "MainMenu.h"

MainMenu::MainMenu(){}

MainMenu::MainMenu(EventBus* eventBus):
        BusNode(eventBus),
        background(eventBus,
                BG_MAINMENU_PATH,INDX_MAIN_MENU,
                0,0,
                WINDOW_WIDTH,
                WINDOW_HEIGHT)
                
        /*
        startButton(eventBus,mouse,
                B_START_PATH,INDX_START_BUTTON,
                300,300,
                300,100)
                */

{
    /*
    sendEvent(MM_EVENT);
    sendEvent(RM_SET_TEXTURE,background.getRect(),NULL);
    */
}
void MainMenu::update(){}

void MainMenu::onNotify(SDL_Event event)
{
    printf("--- MainMenu onNotify ---\n");
}

