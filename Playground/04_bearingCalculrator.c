#include <stdio.h>
#include <math.h>

#define PI 3.141592

typedef struct GlobalPosition {
    double latitude;
    double longitude;
} GlobalPosition;

int main(void) {
	GlobalPosition targetPosition = {};

	const double latitude = 8.46696;
	const double longitude = -17.03663;

	targetPosition.latitude = 42.7994186;
	targetPosition.longitude = 20.228995;

	double latitudeA_rad = latitude / 180 * PI;
	double latitudeB_rad = targetPosition.latitude / 180 * PI;
	double deltaLongitude_rad = (targetPosition.longitude / 180 * PI) - (longitude / 180 * PI);

	double X = cos(latitudeB_rad) * sin(deltaLongitude_rad);
	double Y = cos(latitudeA_rad) * sin(latitudeB_rad) - sin(latitudeA_rad) * cos(latitudeB_rad) * cos(deltaLongitude_rad);

	double bearing = atan2(X, Y) / PI * 180;

	printf("bearing: %.6f \n", bearing);

	return 0;
}
