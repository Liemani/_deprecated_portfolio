#ifndef CARTESIANCOORDINATE_H
#define CARTESIANCOORDINATE_H

struct CartesianCoordinate {
    double x;
    double y;
    double z;

    CartesianCoordinate(double x = 0.0, double y = 0.0, double z = 0.0);
};

#endif