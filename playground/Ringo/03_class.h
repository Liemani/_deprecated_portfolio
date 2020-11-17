#ifndef CLASS_H
#define CLASS_H

#include <string>

using std::string;

class Vehicle {
private:
    int wheelCount;
    
    double positionX;
    double positionY;

    double velocity;

public:
    Vehicle(int wheelCount = 4);
    string alert(int wheelCount, double velocity);

};

#endif