#include <stdio.h>

#define OUT_WORD 0
#define IN_WORD 1

int main() {
    int character;
    char state = 0;

    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\n' || character == '\t') {
            if (state == IN_WORD) {
                putchar('\n');
            }

            state = OUT_WORD;
        } else {
             if (state == OUT_WORD) {
                state = IN_WORD;
                putchar(character);
            } else {
                putchar(character);
            }
        }
    }

    return 0;
}
