#include <stdio.h>

int main() {
    int lineCount = 0;
    int character;

    while ((character = getchar()) != EOF)
        if (character == '\n')
            ++lineCount;

    printf("Line Count: %d \n", lineCount);

    return 0;
}