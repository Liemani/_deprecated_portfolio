#include <stdio.h>
#include <math.h>

#define PI 3.141592
#define RADIUS_OF_EARTH 6371



typedef struct GlobalPosition {
    double latitude;
    double longitude;
} GlobalPosition;



int main(void) {
	GlobalPosition targetPosition = {};

	double latitudeA_rad;
	double longitudeA_rad;

	double latitudeB_rad;
	double longitudeB_rad;

	double deltaLatitude_rad;
	double deltaLongitude_rad;



	double a;
	double distance;



	double X;
	double Y;

	double bearing_rad;



	double latitude = 41.507483;
	double longitude = -99.436554;

	targetPosition.latitude = 38.504048;
	targetPosition.longitude = -98.315949;
	


	latitudeA_rad = latitude / 180 * PI;
	longitudeA_rad = longitude / 180 * PI;

	latitudeB_rad = targetPosition.latitude / 180 * PI;
	longitudeB_rad = targetPosition.longitude / 180 * PI;

	deltaLatitude_rad = latitudeB_rad - latitudeA_rad;
	deltaLongitude_rad = longitudeB_rad - longitudeA_rad;



	a = pow(sin(deltaLatitude_rad / 2), 2) + cos(latitudeA_rad) * cos(latitudeB_rad) * pow(sin(deltaLongitude_rad / 2), 2);
	distance = RADIUS_OF_EARTH * (2 * atan2(sqrt(a), sqrt(1 - a)));

	printf("distance: %0.6f \n", distance);
}

