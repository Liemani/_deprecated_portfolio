#ifndef POSITION_H
#define POSITION_H

struct GlobalPosition {
    double latitude;
    double longitude;
    double altitude;

    GlobalPosition(double latitude = 0.0, double longitude = 0.0, double altitude = 0.0);
};

#endif