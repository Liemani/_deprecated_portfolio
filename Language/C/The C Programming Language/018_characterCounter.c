#include <stdio.h>

int main() {
    int count = 0;

    while (getchar() != EOF) {
        ++count;
    }

    printf("Count: %d \n", count);

    return 0;
}