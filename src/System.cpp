#include "System.h"
#include "ResourceManager.h"
#include "RenderSystem.h"

System::System(){}

System::System(EventBus* eventBus):BusNode(eventBus){}

System::~System(){}

void System::update(){}
    
void System::start()
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
void System::setEntity()
{
    //test.push_back(new Entity(eventBus));
    allEntities[E_MOUSE] = new Mouse(eventBus);

    allEntities[MAIN_MENU] = new Entity(
            eventBus,
            BG_MAINMENU_PATH,
            INDX_MAIN_MENU,
            0,0,
            WINDOW_WIDTH,WINDOW_HEIGHT);

    allEntities[START_BUTTON] = new Button(
            eventBus,allEntities[E_MOUSE],
            B_START_PATH,
            INDX_START_BUTTON,
            (WINDOW_WIDTH/2)-150,(WINDOW_HEIGHT/2)-50,
            300,100
            );
            

    allEntities[TITLE] = new Entity(
            eventBus,
            M_TITLE,
            INDX_TITLE,
            0,0,
            640,200
            );

    allEntities[LEVEL_1] = new Entity(
            eventBus,
            LEVEL_ONE_BACKGROUND_PATH,
            INDX_LEVEL1_BG,
            0,0,
            WINDOW_WIDTH,WINDOW_HEIGHT
            );
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
}

