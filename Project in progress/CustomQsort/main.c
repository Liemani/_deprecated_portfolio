//********************************************
// char* title = "main"
// made by Lieman at 2020.07.02
//
// description:
//	main function
//********************************************





// preprocessor
#include "Generator.h"
#include "CustomQsort.h"
#include "Comparator.h"

#define COUNT 100
#define LIMIT 100





void quicksortGeneric_test01() {
	unsigned char* byteArray = randomArray_byte(COUNT, LIMIT);
	quicksortGeneric_02(byteArray, COUNT, sizeof(unsigned char), ascendingOrderComparator_equalIncluded_byte);
	printArray_byte(byteArray, COUNT);
}

void quicksortGeneric_test02() {
	unsigned char* byteArray = randomArray_byte(COUNT, LIMIT);
	quicksortGeneric_02(byteArray, COUNT, sizeof(unsigned char), ascendingOrderComparator_byte);
	printArray_byte(byteArray, COUNT);
}

void quicksortGeneric_test03() {
	unsigned char* byteArray = randomArray_byte(COUNT, LIMIT);
	quicksortGeneric_02(byteArray, COUNT, sizeof(unsigned char), descendingOrderComparator_equalIncluded_byte);
	printArray_byte(byteArray, COUNT);
}

void quicksortGeneric_test04() {
	unsigned char* byteArray = randomArray_byte(COUNT, LIMIT);
	quicksortGeneric_02(byteArray, COUNT, sizeof(unsigned char), descendingOrderComparator_byte);
	printArray_byte(byteArray, COUNT);
}

void quicksortGeneric_test05() {
	unsigned char byteArray[] = { 4, 10, 4, 8, 10, 8, 8, 3, 7 };
	quicksortGeneric_02(byteArray, sizeof(byteArray) / sizeof(unsigned char), sizeof(unsigned char), ascendingOrderComparator_byte);
	printArray_byte(byteArray, COUNT);
}

void quicksort_int_test00() {
	int* intArray = randomArray_int(COUNT, LIMIT);
	quicksortGeneric_02(intArray, COUNT, sizeof(int), ascendingOrderComparator_equalIncluded_int);
	printArray_int(intArray, COUNT);
}

void quicksort_int_test01() {
	int* intArray = randomArray_int(COUNT, LIMIT);
	quicksortGeneric_02(intArray, COUNT, sizeof(int), ascendingOrderComparator_int);
	printArray_int(intArray, COUNT);
}

void quicksort_int_test02() {
	int* intArray = randomArray_int(COUNT, LIMIT);
	quicksortGeneric_02(intArray, COUNT, sizeof(int), descendingOrderComparator_equalIncluded_int);
	printArray_int(intArray, COUNT);
}

void quicksort_int_test03() {
	int* intArray = randomArray_int(COUNT, LIMIT);
	quicksortGeneric_02(intArray, COUNT, sizeof(int), descendingOrderComparator_int);
	printArray_int(intArray, COUNT);
}

void quicksortInt_test() {
	int* intArray = randomArray_int(100, LIMIT);
	quicksortInt(intArray, COUNT);
	printArray_int(intArray, COUNT);
}

void publicTest() {
	for (int i = 0; i < 100; ++i) {
		unsigned char lhs = random_byte();
		unsigned char rhs = random_byte();

		int printor = descendingOrderComparator_byte(&lhs, &rhs, sizeof(unsigned char));

		printf("(lhs, rhs, printor): %d %d %d \n", lhs, rhs, printor);
	}

	unsigned char lhs = 0;
	unsigned char rhs = 0;

	int printor = descendingOrderComparator_byte(&lhs, &rhs, sizeof(unsigned char));

	printf("(lhs, rhs, printor): %d %d %d \n", lhs, rhs, printor);
}

void rModule(void *lhs, void *rhs, int sizeOfElement, int (*compare)(void* lhs, void* rhs, int sizeOfElement)) {
	if ((!isEqualTo_byte(lhs, rhs, sizeOfElement) &&
		compare(lhs, rhs, sizeOfElement))) {
		printf("triggered \n");
	} else {
		printf("not triggered \n");
	}
}

// test for one function
void monoTest00() {
	unsigned char lhs = 0;
	unsigned char rhs = 0;

	int printor = descendingOrderComparator_byte(&lhs, &rhs, sizeof(unsigned char));

	printf("(lhs, rhs, printor): %d %d %d \n", lhs, rhs, printor);
}

void monoTest01() {
	unsigned char lhs = 0x4;
	unsigned char rhs = 0x3;

	rModule(&lhs, &rhs, sizeof(unsigned char), ascendingOrderComparator_equalIncluded_byte);
}

void polyTest00() {
	printf("test01 \n");
	quicksortGeneric_test01();
	printf("test02 \n");
	quicksortGeneric_test02();
	printf("test03 \n");
	quicksortGeneric_test03();
	printf("test04 \n");
	quicksortGeneric_test04();
}

void polyTest01() {
	printf("quicksort_int 00 \n");
	quicksort_int_test00();
	printf("quicksort_int 01 \n");
	quicksort_int_test01();
	printf("quicksort_int 02 \n");
	quicksort_int_test02();
	printf("quicksort_int 03 \n");
	quicksort_int_test03();
}

int main(void) {
	srand(time(NULL));
	polyTest01();
	return 0;
}