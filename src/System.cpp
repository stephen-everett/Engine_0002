#include "System.h"
#include "ResourceManager.h"
#include "RenderSystem.h"

System::System(){}

System::System(EventBus* eventBus):BusNode(SYSTEM,eventBus)
{
    mouse = new Mouse(eventBus);
}

System::~System()
{
    printf("System being destructed!\n");
    delete mouse;
    mouse = NULL;
    eventBus->removeReceiver(SYSTEM);
}

void System::update(){}
    
void System::start()
{
    /* Initialize all objects passing eventBus
     * pointer. 
     * Map mainMenu will create and manage Entities
     */

    ResourceManager resourceManager(eventBus);
    Map mainMenu(eventBus, mouse);
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
        if(state == SET_STAGE)
        {
            if(level == 0)
            {
                sendEvent(M_LOAD_MAIN);
                level = 99;
            }
            if(level == 1)
            {
                sendEvent(M_LOAD_LEVEL_1);
                level = 99;
            }
        }
        if (state == READY)
        {
            sendEvent(E_GET_TEXTURES);
            state = IDLE;
        }
        screen.draw();
    }
    
}

 void System::onNotify(SDL_Event event)
{
    printf("System onNotify()\n");
    if(event.type == SDL_QUIT)
    {
        quit = true;
    }

    if(event.type == SDL_USEREVENT)
    {
        // If level is created, it needs userEvent to send messages
        if(event.user.code == SYS_LEVEL_LOADED)
        {
            sendEvent(GL_LOAD_INITIAL, &userEvent1,NULL);
        }
        if(event.user.code == SYS_READY)
        {
            state = READY;
            sendEvent(RM_SEND_RESOURCE_LINKS);
        }
        if(event.user.code == START_CLICKED)
        {
            sendEvent(RS_NULL_VECTOR);
        }
        if(event.user.code == SYS_LEVEL_CLEARED)
        {
            state = SET_STAGE;
            level = 1;
        }
    }
        /*
        if(event.user.code == SYS_STAGE_SET)
        {
            printf("-- STATE IS SYS_STAGE_SET ---\n");
            state = LOAD_MAIN_MENU;
        }
        if(event.user.code == SYS_READY)
        {
            state = READY;
        }
        if(event.user.code == MM_EVENT)
        {
            printf("--- System received event from MainMenu() inside Map() ---\n");
        }
        if(event.user.code == SYS_REQUEST_INIT)
        {
            sendEvent(GL_LOAD_INITIAL,&userEvent1,NULL);
        }
        
        
    }
    else if (event.type == SDL_KEYDOWN || event.user.code == START_CLICKED)
    {
        if (event.key.keysym.sym == SDLK_k || event.user.code == START_CLICKED)
        {
            state = SET_STAGE;
            level = 1;
        }
    }
    */
}

