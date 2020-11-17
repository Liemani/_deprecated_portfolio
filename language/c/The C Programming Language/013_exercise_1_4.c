#include <stdio.h>

float fahrenheitByCelsius(float celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

int main(void) {
    printf("  Cel    Fah \n");

    for (float celsius = 0; celsius <= 300; celsius += 20.0) {
        printf("%6.1f %6.1f \n", celsius, fahrenheitByCelsius(celsius));
    }

    return 0;
}
