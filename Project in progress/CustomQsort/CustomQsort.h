//********************************************
// char* title = "CustomQsort"
// made by Lieman at 2020.06.30
//
// description:
//	quicksort example
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "View.h"

#include "Average.h"





void quicksortGeneric(void *array, int count, int sizeOfElement, int (*compare)(void* lhs, void* rhs, int sizeOfElement)) {
	int startIndex = 0;
	int endIndex = count - 1;
	unsigned char* byteArray = (unsigned char*)array;

	int CompareIncludeEqual;
	int pivotIndex = startIndex;

	void* temp = malloc(sizeOfElement);

	printByteArray(byteArray, count);
	if (!compare(&byteArray[startIndex], &byteArray[endIndex], sizeOfElement)) {
		memcpy(temp, &byteArray[startIndex], sizeOfElement);
		memcpy(&byteArray[startIndex], &byteArray[endIndex], sizeOfElement);
		memcpy(&byteArray[endIndex], temp, sizeOfElement);
	}

	while (1) {
		while (
			compare(&byteArray[startIndex], &byteArray[pivotIndex], sizeOfElement) &&
			startIndex != endIndex
			) {
			++startIndex;
		}
	
		while (
			compare(&byteArray[pivotIndex], &byteArray[endIndex], sizeOfElement) &&
			startIndex != endIndex
			) {
			--endIndex;
		}

		if (startIndex != endIndex) {
			memcpy(temp, &byteArray[startIndex], sizeOfElement);
			memcpy(&byteArray[startIndex], &byteArray[endIndex], sizeOfElement);
			memcpy(&byteArray[endIndex], temp, sizeOfElement);
		} else {
		
			break;
		}
		printByteArray(byteArray, count);
	}
	free(temp);

	int leftArrayCount = startIndex;
	if (leftArrayCount > 1) {
		quicksortGeneric(array, leftArrayCount, sizeOfElement, compare);
	}

	int rightArraycount = count - leftArrayCount;
	if (rightArraycount > 1) {
		quicksortGeneric(byteArray + leftArrayCount, rightArraycount, sizeOfElement, compare);
	}
}

void quicksortInt(int* array, int count) {
	int startIndex = 0;
	int endIndex = count - 1;
	int middleValue = 0;

	// int middleValue = (array[startIndex] + array[endIndex]) >> 1;
	averageData(&array[startIndex], &array[endIndex], &middleValue, sizeof(int));

	while (1) {
		printIntArray(array, count);
		while (
			array[startIndex] <= middleValue &&
			startIndex != endIndex
			) {
			++startIndex;
		}

		while (
			array[endIndex] > middleValue &&
			startIndex != endIndex
			) {
			--endIndex;
		}

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