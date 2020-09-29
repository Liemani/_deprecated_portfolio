#include <stdio.h>

float celsiusByFahrenheit(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main(void) {
    printf("  Fah    Cel \n");

    for (float fahrenheit = 0; fahrenheit <= 300; fahrenheit += 20.0) {
        printf("%6.1f %6.1f \n", fahrenheit, celsiusByFahrenheit(fahrenheit));
    }

    return 0;
}
