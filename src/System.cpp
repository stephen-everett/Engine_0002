#include "System.h"
#include "ResourceManager.h"
#include "RenderSystem.h"
#include "CollisionSystem.h"

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
    CollisionSystem collisionSystem(eventBus);
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
        sendEvent(UPDATE);
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
            level = 1;
        }
        if(event.user.code == SYS_LOAD_MAIN)
        {
            sendEvent(RS_NULL_VECTOR);
            level = 0;
        }
        if(event.user.code == SYS_LEVEL_CLEARED)
        {
            state = SET_STAGE;
        }
    }
}

