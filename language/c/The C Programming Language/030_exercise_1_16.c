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


    for (length = 0;
        currentCharacter = getchar(),
        length < lineArrayLength - 1
        && currentCharacter != '\n'
        && currentCharacter != EOF;
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

int copyPaste(char* destination, char* source) {
    for (int i = 0; (destination[i] = source[i]) != '\0'; ++i);
}

int countInputLength() {
    int length;
    int currentCharacter;

    for (length = 0;
         currentCharacter = getchar(),
         !(currentCharacter == EOF || currentCharacter == '\n');
         ++length);
    
    if (currentCharacter == '\n') {
        ++length;
    }

    return length;
}

int countInputLength2() {
    int length;
    int currentCharacter;

    for (length = 0; (currentCharacter = getchar()) != EOF; ++length);

    return length;
}

int countInputLength3(char* line) {
    int length;
    int currentCharacter;

    while (TRUE) {
        currentCharacter = getchar();

        if (currentCharacter == EOF) {
            break;
        }
        
        line[length] = currentCharacter;
        ++length;

        if (currentCharacter == '\n') {
            break;
        }
    }

    line[length] = '\0';

    return length;
}

int main() {
    char currentLine[LINE_LENGTH_LIMIT];
    int currentLineLength;

    char longestLine[LINE_LENGTH_LIMIT];
    int longestLineLength;



    longestLineLength = 0;



    while ((currentLineLength = readALine(currentLine, LINE_LENGTH_LIMIT)) != 0) {
        if (currentLineLength == LINE_LENGTH_LIMIT - 1) {
            currentLineLength += countInputLength();
        }
        
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
