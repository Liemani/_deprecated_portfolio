#include "Generator.h"
#include "CustomQsort.h"
#include "Comparator.h"

#define COUNT 20
#define LIMIT 20

void quicksortGeneric_test01() {
	unsigned char* byteArray = randomByteArray(COUNT, LIMIT);
	quicksortGeneric(byteArray, COUNT, sizeof(unsigned char), ascendingOrderComparator_equalIncluded_Byte);
	printByteArray(byteArray, COUNT);
}

void quicksortGeneric_test02() {
	unsigned char* byteArray = randomByteArray(COUNT, LIMIT);
	quicksortGeneric(byteArray, COUNT, sizeof(unsigned char), descendingOrderComparator_Byte);
	printByteArray(byteArray, COUNT);
}

void quicksortInt_test() {
	int* intArray = randomIntArray(100, LIMIT);
	quicksortInt(intArray, COUNT);
	printIntArray(intArray, COUNT);
}

void publicTest() {
	for (int i = 0; i < 100; ++i) {
		unsigned char lhs = randomByte();
		unsigned char rhs = randomByte();

		int printor = descendingOrderComparator_Byte(&lhs, &rhs, sizeof(unsigned char));

		printf("(lhs, rhs, printor): %d %d %d \n", lhs, rhs, printor);
	}

	unsigned char lhs = 0;
	unsigned char rhs = 0;

	int printor = descendingOrderComparator_Byte(&lhs, &rhs, sizeof(unsigned char));

	printf("(lhs, rhs, printor): %d %d %d \n", lhs, rhs, printor);
}

void personalTest() {
	unsigned char lhs = 0;
	unsigned char rhs = 0;

	int printor = descendingOrderComparator_Byte(&lhs, &rhs, sizeof(unsigned char));

	printf("(lhs, rhs, printor): %d %d %d \n", lhs, rhs, printor);
}

int main(void) {
	srand(time(NULL));

	personalTest();

	return 0;
}