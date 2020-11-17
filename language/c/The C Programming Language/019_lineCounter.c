#include <stdio.h>

int main() {
    int lineCount;
    int character;

    for (lineCount = 0; (character = getchar()) != EOF;)
        if (character == '\n')
            ++lineCount;

    printf("Line Count: %d \n", lineCount);

    return 0;
}