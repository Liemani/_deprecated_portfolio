//********************************************
// char* title = "playground"
// made by Lieman at 2020.06.03
//
// description:
//	'The C Programming Language' example
//********************************************





// preprocessor
#include <stdio.h>





void longestWord() {
	char c;

	char word[100];
	int count = 0;

	char longestWord[100];
	int longestCount = 0;

	c = getchar();
	do {
		if (c == ' ' || c == '\n') {
			word[count] = '\0';

			if (count > longestCount) {
				longestCount = count;

				for (int index = 0; index < 100; ++index) {
					longestWord[index] = word[index];

					if (word[index] == '\0') {
						break;
					}
				}
			}

			count = 0;
		}
		else {
			word[count] = c;
			++count;
		}
	} while ((c = getchar()) != '\n');

	printf("Longest word: \"%s\"\n", longestWord);
	printf("count: %d", longestCount);
}





int main(int argc, char** argv) {
	longestWord();

	return 0;
}
