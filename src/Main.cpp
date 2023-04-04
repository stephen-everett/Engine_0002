#include "BusNode.h"
#include "EventBus.h"
#include "RenderSystem.h"
#include "Structs.h"
#include "Map.h"
#include "ResourceManager.h"
#include "Mouse.h"

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
            /* Initialize all objects passing eventBus
             * pointer. 
             * Map mainMenu will create and manage Entities
             */

            setEntity(); 
            ResourceManager resourceManager(eventBus);
            Map mainMenu(eventBus,allEntities);
            RenderSystem screen(eventBus);
            
            /* System calls SDL_RegisterEvent() and stores 
             * Uint32 return value in userEvent1. userEvent1
             * Will be used by the rest of the objects to be
             * able to send user defined SDL Events
             * Defined in BusNode
             */
            printf("---SYSTEM INITIALIZING EVENTS---\n");
            initializeEvents();

            /* Send reference to userEvent1. Objects
             * load any initial data they need upon
             * receiving GL_LOAD_INITIAL
             */
            printf("---SENDING LOAD-INITIAL----\n");
            sendEvent(GL_LOAD_INITIAL,&userEvent1,NULL);

            /* Create an Entity object in System.
             * Program crashes when trying to create
             * Entities in Map() without this here
             */

            // Beginning state
            state = SET_STAGE;
            level = 0;
            // Main loop
            while(!quit)
            {
                eventBus->notify();
                if (state == SET_STAGE)
                {
                    printf("--- STATE IS SET_STAGE --- \n");
                    sendEvent(RM_SEND_RESOURCE_LINKS);
                    state = IDLE;
                }
                else if (state == LOAD_MAIN_MENU && level == 0)
                {
                    printf("--- STATE IS LOAD_MAIN_MENU---\n");
                    sendEvent(M_LOAD_MAIN);
                    state = IDLE;
                }
                else if (state == LOAD_MAIN_MENU && level == 1)
                {
                    sendEvent(M_LOAD_LEVEL_1);
                    state = IDLE;
                }
                else if (state == READY)
                {
                    screen.draw();
                }
                else if(state == IDLE)
                {
                    printf("--- STATE IDLE ---\n");
                }
            }
        }
        void setEntity()
        {
            //test.push_back(new Entity(eventBus));
            allEntities[MAIN_MENU] = new Entity(
                    eventBus,
                    MAIN_MENU_BACKGROUND_PATH,
                    INDX_MAIN_MENU,
                    0,0,
                    WINDOW_WIDTH,WINDOW_HEIGHT);
            allEntities[START_BUTTON] = new Button(
                    eventBus,
                    B_START_PATH,
                    START_BUTTON_INDEX,
                    200,200,
                    300,100
                    );
            allEntities[LEVEL_1] = new Entity(
                    eventBus,
                    LEVEL_ONE_BACKGROUND_PATH,
                    INDX_LEVEL1_BG,
                    0,0,
                    WINDOW_WIDTH,WINDOW_HEIGHT
                    );
            allEntities[E_MOUSE] = new Mouse(eventBus);
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
                if(event.user.code == SYS_STAGE_SET)
                {
                    printf("-- STATE IS SYS_STAGE_SET ---\n");
                    state = LOAD_MAIN_MENU;
                }
                if(event.user.code == SYS_READY)
                {
                    state = READY;
                }
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_k)
                {
                    state = SET_STAGE;
                    level = 1;
                }
            }
        }

    private:
        int level;
        State state; 
        bool quit = false;
        SDL_Event event;
        Entity* allEntities[NUMBER_OF_ENTITIES+1]; 


};



int main(int argc, char* argv[])
{
    EventBus eventBus;
    System mainSystem(&eventBus);
    mainSystem.start();
    return 0;
}
