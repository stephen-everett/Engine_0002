#include "BusNode.h"
#include "EventBus.h"
#include "System.h"

double GlobalTime = 0.0;
int main(int argc, char* argv[])
{
    EventBus eventBus;
    System mainSystem(&eventBus);
    mainSystem.start();
    return 0;
}
