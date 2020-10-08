#include <stdio.h>

#define MAX_LINE_LENGTH 100





int readLine(char* line, int lineArrayLength) {
    int currentCharacter;
    int length;

    for (length = 0;
        length < lineArrayLength - 1
        && (currentCharacter = getchar()) != EOF
        && currentCharacter != '\n';
        ++length) {

        line[length] = currentCharacter;
    }

    if (currentCharacter == '\n') {
        line[length] = currentCharacter;
        ++length;
    }

    line[length] = '\0';

    return length;
}

// assum destination is big enough
void copyString(char* destination, char* source) {
    for (int i = 0; (destination[i] = source[i]) != '\0'; ++i);
}

// main function
int main() {
    char currentLine[MAX_LINE_LENGTH];
    int currentLineLength;

    char longestLine[MAX_LINE_LENGTH];
    int longestLineLength;



    longestLineLength = 0;



    while ((currentLineLength = readLine(currentLine, MAX_LINE_LENGTH)) != 0) {
        if (currentLineLength > longestLineLength) {
            copyString(longestLine, currentLine);
            longestLineLength = currentLineLength;
        }
    }

    printf("The longest line: \"%s\" \n", longestLine);
    printf("Length: %d \n", longestLineLength);

    return 0;
}
