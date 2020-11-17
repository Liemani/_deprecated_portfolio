#include <stdio.h>

#define LINE_LENGTH_LIMIT 30

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

int readALine(char* line, int lineArrayLength) {
    int length;
    int currentCharacter;

    length = 0;

    while (TRUE) {
        currentCharacter = getchar();
        if (currentCharacter == EOF) break;

        if (length < lineArrayLength - 1) {
            line[length] = currentCharacter;
        } else if (length == lineArrayLength - 1) {
            line[length] = '\0';
        }

        ++length;

        if (currentCharacter == '\n') {
            break;
        }
    }

    return length;
}

int copyPaste(char* destination, char* source) {
    for (int i = 0; (destination[i] = source[i]) != '\0'; ++i);
}

int main() {
    char currentLine[LINE_LENGTH_LIMIT];
    int currentLineLength;

    char longestLine[LINE_LENGTH_LIMIT];
    int longestLineLength;



    longestLineLength = 0;



    while (TRUE) {
        currentLineLength = readALine(currentLine, LINE_LENGTH_LIMIT);
        if (currentLineLength == 0) break;

        if (currentLineLength > longestLineLength) {
            longestLineLength = currentLineLength;
            copyPaste(longestLine, currentLine);
        }
    }



    printf("Longest line: \"%s", longestLine);

    if (longestLineLength >= LINE_LENGTH_LIMIT - 1) {
        printf("...");
    }

    printf("\" \n");

    printf("Length: %d \n", longestLineLength);

    return 0;
}
