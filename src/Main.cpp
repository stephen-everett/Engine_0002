#include "BusNode.h"
#include "EventBus.h"
#include "RenderSystem.h"
#include "Structs.h"
#include "Map.h"
#include "ResourceManager.h"

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
            ResourceManager resourceManager(eventBus);
            Map mainMenu(eventBus);
            RenderSystem screen(eventBus);
            //sendEvent(LOAD_INITIAL,NULL,NULL);
            //Entity test(eventBus);
            Entity test2(eventBus, LEVEL_ONE_BACKGROUND_PATH,BACKGROUND_TEXTURE_INDEX,0,0,0,0);
            //sendEvent(LOAD_INITIAL,NULL,NULL);
            sendEvent(LOAD_ENTITY,NULL,NULL);
            //mainMenu.sendAssets();
            //screen.setDebug(true);
            //int count = 0;
            while(!quit)
            {
                eventBus->notify();
                //screen.draw();
            }
            //screen.close();
        }
    protected:
        void onNotify(SDL_Event event)
        {
            printf("System onNotify()\n");
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
            if(event.type == SDL_USEREVENT)
            {
                printf("---Received user event---\n");
               // printf("Custom Event Received: System Class onNotify\n");
                if(event.user.code == 0)
                {
                   // printf("Custom event code received System Class onNotify\n");
                }
                if(event.user.code == LOAD_LEVEL)
                {
                    //printf("LOAD_LEVEL code received System Class onNotify\n");
                }
                if(event.user.code == LOAD_INITIAL)
                {
                    printf("--- User event received: LOAD_INITIAL ---\n");
                }
                if(event.user.code == LOAD_ENTITY)
                {
                    printf("---User event received: LOAD_ENTITY ---\n");
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
