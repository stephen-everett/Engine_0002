#include "System.h"
#include "ResourceManager.h"
#include "RenderSystem.h"
#include "CollisionSystem.h"
#include "math.h"

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
    double elapsedTime = 0;
    int count = 0;
    extern double GlobalTime;
    // Main loop
    while(!quit)
    {
        uint64_t startTime = SDL_GetPerformanceCounter();
        eventBus->notify();
        switch(state)
        {
            case SET_STAGE:
                switch(level)
                {
                    case 0:
                        sendEvent(M_LOAD_MAIN);
                        level = 99;
                        break;
                    case 1:
                        sendEvent(M_LOAD_LEVEL_1);
                        level = 99;
                        break;
                }
                break;

            case READY:
                sendEvent(E_GET_TEXTURES);
                state = IDLE;
                break;
        }
        screen.draw();
        sendEvent(UPDATE);
        uint64_t endTime = SDL_GetPerformanceCounter();
        elapsedTime += static_cast<double>((endTime - startTime) /
                            static_cast<double>(SDL_GetPerformanceFrequency()));
        GlobalTime = elapsedTime;
        printf("Time: %0.2f\n",elapsedTime);
        if(fmod(elapsedTime, 1.0) == 0.0)
        {
            printf("tick\n");
        }
        count++;
        int FPS = count / elapsedTime;
        printf("Frames per second: %i\n", FPS);

    }
    
}

 void System::onNotify(SDL_Event event)
{
    printf("System onNotify()\n");
    switch (event.type)
    {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_USEREVENT:
            switch(event.user.code)
            {
                // If level is created, it needs userEvent to send messages
                case SYS_LEVEL_LOADED:
                    sendEvent(GL_LOAD_INITIAL,&userEvent1,NULL);
                    break;

                case SYS_READY:
                    state = READY;
                    sendEvent(RM_SEND_RESOURCE_LINKS);
                    break;
                               
                case START_CLICKED:
                    sendEvent(RS_NULL_VECTOR);
                    level = 1;
                    break;

                case SYS_LOAD_MAIN:
                    sendEvent(RS_NULL_VECTOR);
                    level = 0;
                    break;

                case SYS_LEVEL_CLEARED:
                    state = SET_STAGE;
                    break;
            }

    }
}

