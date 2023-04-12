#include "GameTime.h"

GameTime::GameTime()
{
    elapsedTime = 0;
    startTime = SDL_GetPerformanceCounter();
    endTime = 0;
    tickTime = elapsedTime + 0.08;
    deltaTime = 0;
    readyToUpdate = false;
}

GameTime::~GameTime(){}

void GameTime::update()
{
    calculateElapsedTime();
    if(elapsedTime > tickTime)
    {
        readyToUpdate = true;
        tickTime = elapsedTime + 0.016;
    }
    else
    {
        readyToUpdate = false;
    }
}

double GameTime::getElapsedTime()
{
    return elapsedTime;
}

bool GameTime::isTime()
{
    return readyToUpdate;
}

void GameTime::calculateElapsedTime()
{
    endTime = SDL_GetPerformanceCounter();
    elapsedTime += static_cast<double>((endTime - startTime) /
                        static_cast<double>(SDL_GetPerformanceFrequency()));
    startTime = SDL_GetPerformanceCounter();

}
