#include <stdio.h>

int main() {
    int character;

    int digitCountArray[10] = {0};
    int blankCount = 0;
    int tabCount = 0;
    int newLineCount = 0;
    int otherCharacterCount = 0;

    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            ++blankCount;
        } else if (character == '\t') {
            ++tabCount;
        } else if (character == '\n') {
            ++newLineCount;
        } else if (character >= '0' && character <= '9') {
            ++digitCountArray[character - '0'];
        } else {
            ++otherCharacterCount;
        }
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d count: %d \n", i, digitCountArray[i]);
    }

    printf("Blank count: %d \n", blankCount);
    printf("Tab count: %d \n", tabCount);
    printf("New line count: %d \n", newLineCount);
    printf("Other character count: %d \n", otherCharacterCount);

    return 0;
}
