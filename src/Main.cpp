#include "BusNode.h"
#include "EventBus.h"
#include "System.h"

int main(int argc, char* argv[])
{
    EventBus eventBus;
    System mainSystem(&eventBus);
    mainSystem.start();
    return 0;
}
