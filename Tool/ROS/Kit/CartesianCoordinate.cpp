#include "CartesianCoordinate.h"

CartesianCoordinate::CartesianCoordinate(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

bool CartesianCoordinate::isReady() {
    return x != 0.0 && y != 0.0 && z != 0.0;
}


