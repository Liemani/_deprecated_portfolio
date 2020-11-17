#include <stdio.h>

int main() {
    int spaceCount = 0;
    int character;

    character = getchar();

    while ((character = getchar()) != EOF)
        if (character == ' ' || character == '\t' || character == '\n')
            ++spaceCount;

    printf("Space Count: %d \n", spaceCount);

    return 0;
}
