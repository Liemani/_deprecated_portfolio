#include <stdio.h>

#define MAX_LENGTH 100

int getLine(char* line) {
    int currentCharacter;
    int length = EOF;

    while ((currentCharacter = getchar()) != EOF) {
        if (currentCharacter != '\n') {
            line[++length] = currentCharacter;
        } else {
            line[++length] = '\0';

            break;
        }
    }

    if (currentCharacter == EOF) {
        line[length + 1] = '\0';
    }

    return length;
}

void copyString(char* destination, char* source) {
    int i;

    for (i = 0; source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }

    destination[i] = source[i];
}

int main() {
    char currentLine[MAX_LENGTH];
    int currentLineLength;

    char longestLine[MAX_LENGTH];
    int longestLineLength = 0;

    while ((currentLineLength = getLine(currentLine)) != EOF) {
        if (currentLineLength > longestLineLength) {
            copyString(longestLine, currentLine);
            longestLineLength = currentLineLength;
        }
    }

    printf("The longest line: \"%s\" \n", longestLine);
    printf("Length: %d \n", longestLineLength);

    return 0;
}
