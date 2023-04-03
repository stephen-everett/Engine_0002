#ifndef EVENTENUMS_H
#define EVENTENUMS_H


// Define path for image assets
#define LEVEL_ONE_BACKGROUND_PATH "./assets/img/background-main.jpg"
#define B_START_PATH "./assets/img/StartButton.png"
#define MAIN_MENU_BACKGROUND_PATH "./assets/img/menu.png"
#define PLAYER_MODEL_PATH "./assets/img/Jet3-1.png"
#define ENEMY_MODEL1_PATH "./assets/img/Jet.png"
#define ENEMY_MODEL2_PATH "./assets/img/Jet2.png"
#define ENEMY_MODEL3_Path "./assets/img/Jet3.png"

#define WINDOWNAME "Game"
#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 640

enum UserEvent
{
    GL_LOAD_INITIAL,
    RM_SEND_RESOURCE_LINKS,
    RM_SET_TEXTURE,
    RM_SAVE_TEXTURE,
    RM_FLUSHRECT,
    RS_LINK_RESOURCES,
    RS_CREATE_TEXTURE,
    M_WIPE,
    M_LOAD_MAIN,
    M_RECTFLUSHED,
    M_LOAD_LEVEL_1,
    SYS_STAGE_SET,
    SYS_READY
};

enum TextureIndex
{
    INDX_MAIN_MENU = 0,
    INDX_LEVEL1_BG,
    PLAYER_TEXTURE_INDEX,
    ENEMY_ONE_TEXTURE_INDEX,
    ENEMY_TWO_TEXTURE_INDEX,
    START_BUTTON_INDEX,
    END,
    TEXTURE_ARRAY_SIZE
};

enum State
{
    SET_STAGE,
    LOAD_MAIN_MENU,
    READY,
    IDLE
};

enum EntityIndex
{
    MAIN_MENU = 0,
    START_BUTTON,
    LEVEL_1,
    NUMBER_OF_ENTITIES,
};
#endif
