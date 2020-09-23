#ifndef CUSTOMMISSIONHANDLER_H
#define CUSTOMMISSIONHANDLER_H

#include <MissionHandler.h>





class CustomMissionHandler: public MissionHandler {
protected:
    void processCommand();
    void commandFunction();

public:
    CustomMissionHandler(int argc, char** argv, int* pCommand);
    
};

#endif