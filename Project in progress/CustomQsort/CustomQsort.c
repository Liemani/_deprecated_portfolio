//********************************************
// char* title = "CustomQsort"
// made by Lieman at 2020.06.29
//
// description:
//	quicksort example
//********************************************





// preprocessor
#include <stdio.h>
#include <string.h>

#include "View.h"
#include "Generator.h"

#include "Average.h"





void quicksortGeneric(int *array, int count, int elementSize, int (*compare)(void* lhs, void* rhs, int sizeOfElement)) {
	int startIndex = 0;
	int endIndex = count - 1;

	int middleValue = 0;
}

void quicksortInt(int* array, int count) {
	int startIndex = 0;
	int endIndex = count - 1;

	// int middleValue = (array[startIndex] + array[endIndex]) >> 1;

	int middleValue;

	averageData(array[startIndex], array[endIndex], &middleValue, sizeof(int));

	while (1) {
		while (array[startIndex] <= middleValue &&
			startIndex != endIndex)
			++startIndex;

		while (array[endIndex] > middleValue &&
			startIndex != endIndex)
			--endIndex;

		if (startIndex != endIndex) {
			int temp = array[startIndex];
			array[startIndex] = array[endIndex];
			array[endIndex] = temp;
		} else
			break;
	}

	int leftArrayCount = startIndex;
	if (leftArrayCount > 1)
		quicksortInt(array, leftArrayCount);

	int rightArraycount = count - leftArrayCount;
	if (rightArraycount > 1)
		quicksortInt(array + leftArrayCount, rightArraycount);
}

int main(void) {
	int* intArray = RandomIntArray(100, 100);
	printIntArray(intArray, 100);
	quicksortInt(intArray, 100);
	printIntArray(intArray, 100);

	return 0;
}