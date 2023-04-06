#ifndef MAINMENU_H
#define MAINMENU_H
#include "BusNode.h"
#include "Entity.h"
#include "Button.h"


class MainMenu : public BusNode
{
    public:
        MainMenu();
        MainMenu(EventBus* eventBus);
        ~MainMenu();
        void update();
       // void requestTextures();
    protected:
        void onNotify(SDL_Event event);
    private:
        Entity background;
      //Button startButton;

};
#endif
