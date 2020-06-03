//********************************************
// char* title = "playground"
// made by Lieman at 2020.06.03
//
// description:
//	have fun!!
//********************************************





// preprocessor
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>





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

int *generateIntArray(int count) {
	int* intArray = (int*)malloc(sizeof(int) * count);

	srand(time(NULL));

	for (int i = 0; i < count; ++i) {
		intArray[i] = rand() % 101;
	}

	return intArray;
}

void selectionSort_int(int* intArray, int count) {
	for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			if (intArray[i] > intArray[j]) {
				int temp = intArray[i];
				intArray[i] = intArray[j];
				intArray[j] = temp;
			}
		}
	}
}

void printIntArray(int* intArray, int count) {
	for (int i = 0; i < count; ++i) {
		printf("%3d\n", intArray[i]);
	}
}

/// <summary>
/// <para>assume data type as signed integer value</para>
/// <para>only for big-endian system</para>
/// </summary>
/// <returns>
/// <para>0: false or equal</para>
/// <para>1: true</para>
/// </returns>
int isBiggerThan(void* lhs, void* rhs, int sizeOfData) {
	unsigned char* lhsAnalyzer = (unsigned char*)lhs;
	unsigned char* rhsAnalyzer = (unsigned char*)rhs;
	
	if (((char*)lhsAnalyzer)[sizeOfData - 1] > ((char*)rhsAnalyzer)[sizeOfData - 1]) {
		return 1;
	}

	if (sizeOfData == 1) {
		return 0;
	}

	for (int i = sizeOfData - 2; i >= 0; --i) {
		if (lhsAnalyzer[i] > rhsAnalyzer[i]) {
			return 1;
		}
	}

	return 0;
}

/// <summary>
/// <para>assume data type as signed integer value</para>
/// <para>only for big-endian system</para>
/// </summary>
void selectionSort(void* array, int count, int sizeOfElement, int (*compare)(void* lhs, void* rhs)) {
	unsigned char* charArray = (unsigned char*)array;

	for (int i = 0; i < sizeOfElement * (count - 1); i += sizeOfElement) {
		for (int j = i + sizeOfElement; j < sizeOfElement * count; j += sizeOfElement) {
			printf("%d is bigger than %d is %s\n", charArray[i], charArray[j], compare(&charArray[i], &charArray[j], sizeOfElement) ? "True" : "False");
			if (compare(&charArray[i], &charArray[j], sizeOfElement)) {
				int temp = charArray[i];
				charArray[i] = charArray[j];
				charArray[j] = temp;
			}
		}
	}
}

void test05() {
	int count = 10;
	int* intArray = generateIntArray(count);

	printIntArray(intArray, count);

	putchar('\n');
	printf("Sorting array!\n");
	selectionSort(intArray, count, sizeof(int), isBiggerThan);
	putchar('\n');

	printIntArray(intArray, count);
}

void test06() {
	int intVariable = 0;
	int* intPointer = &intVariable;
	
	printf("intPointer: \t\t%d\n", intPointer);
	printf("intPointer + 1: \t%d\n", intPointer + 1);
	printf("intPointer + 1 - intPointer: %d\n", intPointer + 1 - intPointer);

	putchar('\n');

	double doubleVariable = 0.0;
	double* doublePointer = &doubleVariable;

	printf("doublePointer: \t\t%d\n", doublePointer);
	printf("doublePointer + 1: \t%d\n", doublePointer + 1);
	printf("doublePointer + 1 - doublePointer: %d\n", doublePointer + 1 - doublePointer);
}

void printDoubleToHex() {
	for (double doubleVariable = 0.0; doubleVariable < 10.0; doubleVariable += 0.1) {
		printf("[%.1lf] 0x%016llx\n", doubleVariable, doubleVariable);
	}
}

void printIntInMemory() {
	int intValue = 0x12345678;

	unsigned char* analyzer = &intValue;

	printf("[%3d]: 0x%02x\n", analyzer[0], analyzer[0]);
	printf("[%3d]: 0x%02x\n", analyzer[1], analyzer[1]);
	printf("[%3d]: 0x%02x\n", analyzer[2], analyzer[2]);
	printf("[%3d]: 0x%02x\n", analyzer[3], analyzer[3]);

	// result: this system is big-endian not little-endian
}

void test07() {
	char lhs = 20;
	char rhs = 50;

	int result = isBiggerThan(&lhs, &rhs, 1);

	printf("%d is bigger than %d: %s", lhs, rhs, result ? "True" : "False");
}

/// <summary>
/// <para>assume data type as signed integer value</para>
/// <para>only for big-endian system</para>
/// </summary>
void bubbleSort(void* array, int count, int sizeOfElement, int (*compare)(void* lhs, void* rhs)) {
	unsigned char* charArray = (unsigned char*)array;

	for (int i = sizeOfElement * (count - 1); i > 0; i -= sizeOfElement) {
		for (int j = 0; j < i; j += sizeOfElement) {
			printf("%d is bigger than %d is %s\n", charArray[j], charArray[j + sizeOfElement], compare(&charArray[j], &charArray[j + sizeOfElement], sizeOfElement) ? "True" : "False");
			if (compare(&charArray[j], &charArray[j + sizeOfElement], sizeOfElement)) {
				int temp = charArray[j];
				charArray[j] = charArray[j + sizeOfElement];
				charArray[j + sizeOfElement] = temp;
			}
		}
	}
}

void test08() {
	int intArray[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	
	printf("%d\n%d\n", &intArray[0], &intArray[0][0]);
}

void test09() {
	int count = 10;
	int* intArray = generateIntArray(count);

	printIntArray(intArray, count);

	putchar('\n');
	printf("Sorting array!\n");
	bubbleSort(intArray, count, sizeof(int), isBiggerThan);
	putchar('\n');

	printIntArray(intArray, count);
}

/// <summary>
/// <para>assume data type as signed integer value</para>
/// <para>only for big-endian system</para>
/// </summary>
void bubbleSort(void* array, int count, int sizeOfElement, int (*compare)(void* lhs, void* rhs)) {
	unsigned char* charArray = (unsigned char*)array;

	for (int i = sizeOfElement * (count - 1); i > 0; i -= sizeOfElement) {
		for (int j = 0; j < i; j += sizeOfElement) {
			printf("%d is bigger than %d is %s\n", charArray[j], charArray[j + sizeOfElement], compare(&charArray[j], &charArray[j + sizeOfElement], sizeOfElement) ? "True" : "False");
			if (compare(&charArray[j], &charArray[j + sizeOfElement], sizeOfElement)) {
				int temp = charArray[j];
				charArray[j] = charArray[j + sizeOfElement];
				charArray[j + sizeOfElement] = temp;
			}
		}
	}
}





// main function
int main(int argc, char** argv) {
	test09();

	return 0;
}