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

#include "selectionSort.h"
#include "bubbleSort.h"
#include "swap.h"
#include "quicksortInt.h"





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

int *generateIntArray(int limit, int count) {
	int* intArray = (int*)malloc(sizeof(int) * count);

	srand(time(NULL));

	for (int i = 0; i < count; ++i) {
		intArray[i] = rand() % (limit + 1);
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
	putchar('{');
	for (int i = 0; i < count; ++i) {
		printf("%d, ", intArray[i]);
	}
	printf("\b\b}");

	putchar('\n');
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

int isSmallerThanOrEqualTo(void* lhs, void* rhs, int sizeOfData) {
	return !isBiggerThan(lhs, rhs, sizeOfData);
}

void test05() {
	const int count = 10;
	const int limit = 100;

	int* intArray = generateIntArray(limit, count);

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

void test08() {
	int intArray[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	
	printf("%d\n%d\n", &intArray[0], &intArray[0][0]);
}

void test09() {
	const int count = 10;
	const int limit = 100;

	int* intArray = generateIntArray(limit, count);

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
/// <para>range of count is depend on INT_MAX</para>
/// <para>because the middleValue is of type int</para>
/// <para>must leftIndex check equality</para>
/// </summary>
void quicksort(void* array, int count, int sizeOfElement, int (*compare)(void* lhs, void* rhs, int sizeOfElement)) {
	unsigned char* charArray = (unsigned char*)array;

	int leftIndex = 0;
	int rightIndex = sizeOfElement * (count - 1);

	int middleValue = (charArray[leftIndex] + charArray[rightIndex]) / 2;

	/*while (1) {
		while () {
			!compare(middleValue, charArray[leftIndex])
		}
	}*/

	/*int middleValue = (charArray[0] + charArray[sizeOfElement * (count - 1)]) / 2;

	for (int i = 0; i < sizeOfElement * count; i += sizeOfElement) {
		if (compare(middleValue, charArray[i], sizeOfElement)) {
			continue;
		}

		for (int j = 0; j > i; j -= sizeOfElement) {
			if (!compare(middleValue, charArray[j], sizeOfElement)) {

			}
		}
	}*/



	

//	while (1) {
//		// 등호비교는 right가
//		// 반 나누는거는 -1, 0
//		while (compare(&middleValue, &charArray[leftIndex], sizeOfElement) &&
//			leftIndex < rightIndex) {
//			leftIndex += sizeOfElement;
//		}
//
//		while (!compare(&middleValue, &charArray[rightIndex], sizeOfElement) &&
//			leftIndex < rightIndex) {
//			rightIndex -= sizeOfElement;
//		}
//
//		if (leftIndex < rightIndex) {
//			swap(&charArray[leftIndex], &charArray[rightIndex], sizeOfElement);
//		} else {
//			break;
//		}
//	}
//
//	printIntArray(array, count);
//	printf("rightIndex: %d\n", rightIndex);
//	printf("count: %d\n", count);
//	printf("%d\n", rightIndex / sizeOfElement > 1);
//	putchar('\n');
//
//	if (rightIndex / sizeOfElement > 0) {
//		quicksort(charArray, rightIndex / sizeOfElement + 1, sizeOfElement, compare);
//	}
//
//	printIntArray(array, count);
//	printf("leftIndex: %d\n", leftIndex);
//	printf("count: %d\n", count);
//	printf("%d\n", count - rightIndex / sizeOfElement > 1);
//	putchar('\n');
//
//	if (count - rightIndex / sizeOfElement > 2) {
//		quicksort(charArray + leftIndex, count - 1 - rightIndex / sizeOfElement, sizeOfElement, compare);
//	}
}

void test10() {
	int* intArray;
	const int limit = 1000;
	const int count = 100;

	intArray = generateIntArray(limit, count);
	//int tempArray[] = { 54, 38, 81, 20, 30, 38, 68, 10, 76, 38 };
	//intArray = tempArray;

	printIntArray(intArray, count);

	putchar('\n');
	printf("sorting...\n");
	//quicksort(intArray, count, 4, isBiggerThan);
	quicksortInt(intArray, count);
	putchar('\n');

	printIntArray(intArray, count);
}





// main function
int main(int argc, char** argv) {
	test10();

	return 0;
}