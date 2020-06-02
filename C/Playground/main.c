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

void operatorOrder() {
	printf("%d\n", 1 && 0 || 1); // 1
	printf("%d\n", 1 || 1 && 0); // 0
}

void test04() {
	printf("%ld", sizeof(float));

	float* myPointer = (float*)malloc(sizeof(float) * 1);

	*myPointer = 3.14F;

	printf("%.2f", *myPointer);
}





// main function
int main(int argc, char** argv) {
	test04();

	return 0;
}