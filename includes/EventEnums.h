#ifndef EVENTENUMS_H
#define EVENTENUMS_H


// Define path for image assets
#define PATH_LEVEL1_BACKGROUND "./assets/img/background-main.jpg"
#define PATH_BUTTON_START "./assets/img/StartButton.png"
#define PATH_MAINMENU_BACKGROUND "./assets/img/menu.png"
#define PATH_PLAYERMODEL "./assets/img/Jet3-1.png"
#define PATH_ENEMY_MODEL1 "./assets/img/Jet.png"
#define PATH_ENEMY_MODEL2 "./assets/img/Jet2.png"
#define PATH_ENEMY_MODEL3 "./assets/img/Jet3.png"
#define PATH_MOUSE_MODEL "./assets/img/cursor.png"
#define PATH_MAIN_TITLE "./assets/img/Title.png"
#define PATH_STARS  "./assets/img/stars.png"

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
    RS_NULL_VECTOR,
    M_LOAD_MAIN,
    M_RECTFLUSHED,
    M_LOAD_LEVEL_1,
    SYS_STAGE_SET,
    SYS_LEVEL_LOADED,
    SYS_READY,
    SYS_LEVEL_CLEARED,
    E_GET_TEXTURES,
    START_CLICKED,
    UPDATE
};

enum TextureIndex
{
    INDX_MAIN_MENU = 0,
    INDX_LEVEL1_BG,
    INDX_PLAYER,
    ENEMY_ONE_TEXTURE_INDEX,
    ENEMY_TWO_TEXTURE_INDEX,
    INDX_START_BUTTON,
    INDX_TITLE,
    INDX_MOUSE,
    INDX_STARS,
    END,
    TEXTURE_ARRAY_SIZE
};

enum State
{
    SET_STAGE,
    LOAD_MAIN_MENU,
    READY,
    STANDBY,
    GO,
    IDLE
};
/*
enum EntityIndex
{
    MAIN_MENU = 0,
    START_BUTTON,
    LEVEL_1,
    E_MOUSE,
    TITLE,
    NUMBER_OF_ENTITIES,
};
*/
enum TypeEnums
{
    ENTITY=0,
    SYSTEM=100,
    RESOURCE_MANAGER=200,
    RENDER_SYSTEM=300,
    MAINMENU=400,
    BUTTON=500,
    MAP=600,
    MOUSE=700,
    LEVEL_1 = 800,
    PLAYER = 900,
};
#endif
