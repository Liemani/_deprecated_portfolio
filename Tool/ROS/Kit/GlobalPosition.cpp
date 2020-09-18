#include "GlobalPosition.h"

GlobalPosition::GlobalPosition(double latitude, double longitude, double altitude) {
    this->latitude = latitude;
    this->longitude = longitude;
    this->altitude = altitude;
}

bool GlobalPosition::isReady() {
    // fix this later to containning (globalPosition(latitude, longitude), altitude)
    return latitude != 0.0 && longitude != 0.0 && altitude != 0.0;
}