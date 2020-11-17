#include <stdio.h>

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20.0

float fahrenheitByCelsius(float celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

int main(void) {
    printf("  Cel    Fah \n");

    for (float celsius = UPPER; celsius >= LOWER; celsius -= STEP) {
        printf("%6.1f %6.1f \n", celsius, fahrenheitByCelsius(celsius));
    }

    return 0;
}
