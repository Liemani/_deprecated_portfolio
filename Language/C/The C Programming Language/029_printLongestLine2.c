#include <stdio.h>

#define MAX_LINE 1000

int myGetline(char line[], int arrayLength);
void myCopy(char to[], char from[]);

int main() {
    int currentLineLength;
    int longestLineLength;

    char currentLine[MAX_LINE];
    char longestLine[MAX_LINE];

    longestLineLength = 0;

    while ((currentLineLength = myGetline(currentLine, MAX_LINE)) > 0) {
        if (currentLineLength > longestLineLength) {
            longestLineLength = currentLineLength;
            myCopy(longestLine, currentLine);
        }
    }

    if (longestLineLength > 0) {
        printf("Longest line: \"%s\" \n", longestLine);
    }

    return 0;
}

/* myGetline: read a line into line, return length */
int myGetline(char line[], int arrayLength) {
    int character, i;

    for (i = 0; i < arrayLength - 1 && (character = getchar()) != EOF && character != '\n'; ++i) {
        line[i] = character;
    }

    if (character == '\n') {
        line[i] = character;
        ++i;
    }

    line[i] = '\0';

    return i;
}

/* myCopy: copy 'source' into 'source'; assume destination is big enough */
void myCopy(char destination[], char source[]) {
    for (int i = 0; (destination[i] = source[i]) != '\0'; ++i);
}
