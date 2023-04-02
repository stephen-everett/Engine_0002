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
    LOAD_LEVEL = 0,
    FLUSH_RECEIVERS,
    LOAD_TEXTURE,
    LOAD_ENTITY,
    LOAD_INITIAL,
    TEST_EVENT,
    TEST_RENDER,
    CREATE_TEXTURE,
    RM_INIT,
};

enum TextureIndex
{
    BACKGROUND_TEXTURE_INDEX = 0,
    PLAYER_TEXTURE_INDEX,
    ENEMY_ONE_TEXTURE_INDEX,
    ENEMY_TWO_TEXTURE_INDEX,
    TEXTURE_ARRAY_SIZE,
    START_BUTTON_INDEX,
    END
};



#endif
