#ifndef GAMETIME_H
#define GAMETIME_H
#include <SDL2/SDL.h>

class GameTime
{
    public:
        GameTime();
        ~GameTime();
        void update();
        double getElapsedTime();
        bool isTime();
    private:
        void calculateElapsedTime();
        double elapsedTime;
        double tickTime;
        uint64_t startTime;
        uint64_t endTime;
        double deltaTime;
        bool readyToUpdate;

        
};
#endif
