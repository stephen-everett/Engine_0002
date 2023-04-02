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
            printf("---SYSTEM INITIALIZING EVENTS---\n");
            initializeEvents();
            printf("---SENDING LOAD-INITIAL----\n");
            sendEvent(LOAD_INITIAL,&userEvent1,NULL);
            printf("---SENDING LOAD_ENTITY---\n");
            sendEvent(LOAD_ENTITY,NULL,NULL);
            printf("---Value of uint32: %i ---\n", userEvent1);
            setEntity();
            while(!quit)
            {
                eventBus->notify();
                screen.draw();
            }
        }
        void setEntity()
        {
            test.push_back(new Entity(eventBus));
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
                if(event.user.code == LOAD_LEVEL)
                {
                    printf("---Received LOAD_LEVEL System---\n");
                }
                if(event.user.code == LOAD_INITIAL)
                {
                    printf("--- User event received: LOAD_INITIAL ---\n");
                }
                if(event.user.code == LOAD_ENTITY)
                {
                    printf("---User event received: LOAD_ENTITY ---\n");
                }
                if(event.user.code == TEST_EVENT)
                {
                    printf("--- User event received: TEST_EVENT System ---\n");
                }


            }
        }

    private:
       
        bool quit = false;
        SDL_Event event;
        std::vector<Entity*> test;
       


};



int main(int argc, char* argv[])
{
    EventBus eventBus;
    System mainSystem(&eventBus);
    mainSystem.start();
    return 0;
}
