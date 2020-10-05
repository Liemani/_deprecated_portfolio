#include <stdio.h>

int main() {
    long characterCount;

    for (characterCount = 0; getchar() != EOF; ++characterCount);

    printf("Character Count: %ld \n", characterCount);

    return 0;
}