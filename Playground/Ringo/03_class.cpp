#include <string>

#include "03_class.h"

using std::string;

Vehicle::Vehicle(int wheelCount) {
    this->wheelCount = wheelCount;
    this->velocity = 0;
}

string Vehicle::alert(int wheelCount, double velocity) {
    cout << wheelCount;
}

string Vehicle::alert(/*Vehicle* this*/) {
    cout << this->wheelCount;
}
