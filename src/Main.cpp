#include "BusNode.h"
#include "EventBus.h"
#include "RenderSystem.h"
#include "Structs.h"
#include "Map.h"

class System : public BusNode
{
    public:
        System(){};
        System(EventBus * eventBus)
            :BusNode(eventBus)
        {}
        ~System(){};
        void upate(){};
        void start()
        {
            Map mainMenu(eventBus);
            RenderSystem screen(eventBus);
            mainMenu.sendAssets();
            screen.setDebug(true);
            int count = 0;
            while(!quit)
            {
                /*
                if (count > 100)
                {
                    mainMenu.closeMap();
                }
                */
                count++;
                eventBus->notify();
                screen.draw();
            }
            screen.close();
        }
    protected:
        void onNotify(SDL_Event event)
        {
            printf("System on notify\n");
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
            if(event.type == SDL_USEREVENT)
            {
               // printf("Custom Event Received: System Class onNotify\n");
                if(event.user.code == 0)
                {
                   // printf("Custom event code received System Class onNotify\n");
                }
                if(event.user.code == LOAD_LEVEL)
                {
                    //printf("LOAD_LEVEL code received System Class onNotify\n");
                }
            }
        }

    private:
       
        bool quit = false;
        SDL_Event event;
       


};



int main(int argc, char* argv[])
{
    EventBus eventBus;
    System mainSystem(&eventBus);
    mainSystem.start();
    return 0;
}
