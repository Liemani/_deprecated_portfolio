#include <stdio.h>

int main() {
    int inputCharacter;

    while((inputCharacter = getchar()) != EOF) {
        if (inputCharacter == '\t') {
            printf("\\t");
        } else if (inputCharacter == '\b') {
            printf("\\b");
        } else if (inputCharacter == '\\') {
            printf("\\\\");
        } else {
            putchar(inputCharacter);
        }
    }

    return 0;
}
