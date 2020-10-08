#include <stdio.h>

int main() {
    int x = 10;
    int y = (x++, ++x);
    printf("(x++, ++x): %d \n", y);

    return 0;
}