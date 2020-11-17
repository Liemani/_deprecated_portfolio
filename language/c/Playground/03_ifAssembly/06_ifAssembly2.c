#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

char isSpace(char character) {
    return character == ' '
        || character == '\t'
        || character == '\n';
}

int main() {
    char isInWord = OUT_WORD;
    int inputCharacter;
    int wordCount = 0;

    while ((inputCharacter = getchar()) != EOF) {
        if (!isInWord && !isSpace(inputCharacter)) {
            isInWord = IN_WORD;
        } else if (isInWord && isSpace(inputCharacter)) {
            ++wordCount;
            isInWord = OUT_WORD;
        }
    }

    printf("Word Count: %d \n", wordCount);

    return 0;
}
