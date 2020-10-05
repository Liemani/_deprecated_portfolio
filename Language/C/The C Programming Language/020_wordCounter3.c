#include <stdio.h>

#define OUT_WORD 0
#define IN_WORD 1

int main() {
    char state = OUT_WORD;
    int currentCharacter;
    int wordCount = 0;

    while ((currentCharacter = getchar()) != EOF) {
        if ( !(currentCharacter == ' ' || currentCharacter == '\n' || currentCharacter == '\t') ) {
            state = IN_WORD;
        } else if (state == IN_WORD) {
            state = OUT_WORD;
            ++wordCount;
        }
    }

    if (state) {
        ++wordCount;
    }

    printf("Word Count: %d \n", wordCount);

    return 0;
}