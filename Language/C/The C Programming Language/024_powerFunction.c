#include <stdio.h>

int power(int base, int n) {
    int result = 1;
    
    for (int i = 0; i < n; ++i) {
        result *= base;
    }

    return result;
}

int main() {
    printf("power(2, 5): %d \n", power(2, 5));

    return 0;
}