//********************************************
// char* title = "main"
// made by Lieman at 2020.06.01
//
// description:
//	main function
//********************************************





// preprocessor
#include <stdio.h>
#include <limits.h>



// function
void copyPaste() {
	int c;

	while ((c = getchar()) != '\n') {
		putchar(c);
	}
}

void countCharacters() {
	int counter;

	for (counter = 0; getchar() != '\n'; counter++);

	printf("Count of input: %d", counter);
}

void test01() {
	printf("sizeof(\'A\'): %d\n", sizeof('A'));
}

void test02() {
	printf("hello, "
	"world");
}

void test03() {
	printf("%d\n", sizeof(INT_MAX + 1));
	printf("%d\n", INT_MAX + 1);
}





// main function
int main(int argc, char** argv) {
	test03();

	return 0;
}