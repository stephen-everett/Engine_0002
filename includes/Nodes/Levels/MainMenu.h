#ifndef MAINMENU_H
#define MAINMENU_H
#include "BusNode.h"
#include "Entity.h"
#include "Button.h"
#include "Mouse.h"


class MainMenu : public BusNode
{
    public:
        MainMenu();
        MainMenu(EventBus* eventBus,Mouse* mouse);
        ~MainMenu();
        void update();
        void requestTextures();
    protected:
        void onNotify(SDL_Event event);
    private:
        std::vector<TextureRect> staticAssets;
        Mouse* mouse;
       // TextureRect background;
        Button startButton;

};
#endif
