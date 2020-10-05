#include <stdio.h>

int main() {
    int inputCharacter;
    int previousCharacter = 0;

    while ((inputCharacter = getchar()) != EOF) {
        if (inputCharacter != ' '
            || previousCharacter != ' ')
            putchar(inputCharacter);

        previousCharacter = inputCharacter;
    }

    return 0;
}

/* WHAT WOULD BE BETTER?

1.

if (!(A == B && C == D))
    body;



2.

if (A != B || C != D)
    body;



3.

if (A == B && C == D);
else
    body;



*/
