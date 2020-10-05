#include <stdio.h>

int power(int base, int n) {
    int result;
    
    for (result = 1; n > 0; --n) {
        result *= base;
    }

    return result;
}

int main() {
    printf("power(2, 5): %d \n", power(2, 5));

    return 0;
}