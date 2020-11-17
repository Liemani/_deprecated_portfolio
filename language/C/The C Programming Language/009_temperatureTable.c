#include <stdio.h>

int celsiusByFahrenheit(int fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main(void) {
    printf("Fah Cel \n");

    for (int fahrenheit = 0; fahrenheit <= 300; fahrenheit += 20) {
        printf("%3d %3d \n", fahrenheit, celsiusByFahrenheit(fahrenheit));
    }

    return 0;
}
