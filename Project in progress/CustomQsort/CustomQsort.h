#pragma once
//********************************************
// char* title = "CustomQsort"
// made by Lieman at 2020.07.02
//
// description:
//	Custom Quicksort
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "View.h"
#include "Comparator.h"
#include "Average.h"
#include "Swap.h"





void quicksortGeneric_03(void* array, int count, int sizeOfElement, int (*compare)(void* plhs, void* prhs, int sizeOfElement)) {
	unsigned char* byteArray = (unsigned char*)array;

	int startIndex = 0;
	int endIndex = sizeOfElement * (count - 1);

	int pivotIndex = 0;

	if (
		(!isEqualTo_byte(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement) &&
			!compare(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement))
		) {
		swap_generic(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement);

		if (startIndex != endIndex) {
			++startIndex;
		}

		if (startIndex != endIndex) {
			--endIndex;
		}
	}

	while (1) {
		while (
			(isEqualTo_byte(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex], sizeOfElement) ||
				compare(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex], sizeOfElement)) &&
			startIndex != endIndex
			) {
			++startIndex;
		}

		while (
			(!isEqualTo_byte(&byteArray[pivotIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement) &&
				compare(&byteArray[pivotIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement)) &&
			startIndex != endIndex
			) {
			--endIndex;
		}

		if (startIndex != endIndex) {
			swap_generic(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement);
		} else {
			break;
		}
	}

	int leftArrayCount;
	int rightArrayCount;

	if (startIndex == 0) {
		leftArrayCount = 1;
	} else if (startIndex == count - 1) {
		leftArrayCount = count - 1;
	} else if (
		(isEqualTo_byte(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex], sizeOfElement) ||
			compare(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex], sizeOfElement))
		) {
		leftArrayCount = startIndex + 1;
	} else {
		leftArrayCount = startIndex;
	}

	rightArrayCount = count - leftArrayCount;

	if (leftArrayCount > 1) {
		quicksortGeneric_03(byteArray, leftArrayCount, sizeOfElement, compare);
	}

	if (rightArrayCount > 1) {
		quicksortGeneric_03(byteArray + sizeOfElement * leftArrayCount, rightArrayCount, sizeOfElement, compare);
	}
}



// TEST:
//  sizeOfElement * startIndex
//  vs
//  startIndex += 4
//
//  delete compare's 3rd argument
//
//  make isEqualTo_byte() to memcmp()
void quicksortGeneric_02(void* array, int count, int sizeOfElement, int (*compare)(void* plhs, void* prhs, int sizeOfElement)) {
	unsigned char* byteArray = (unsigned char*)array;

	int startIndex = 0;
	int endIndex = count - 1;

	int pivotIndex = 0;

	void* temp = malloc(sizeOfElement);

	if (
		(!isEqualTo_byte(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement) &&
		!compare(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement))
		) {
		swap_generic(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement);

		if (startIndex != endIndex) {
			++startIndex;
		}

		if (startIndex != endIndex) {
			--endIndex;
		}
	}

	while (1) {
		while (
			(isEqualTo_byte(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex],sizeOfElement) ||
			compare(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex], sizeOfElement)) &&
			startIndex  != endIndex
			) {
			++startIndex;
		}

		while (
			(!isEqualTo_byte(&byteArray[pivotIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement) &&
			compare(&byteArray[pivotIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement)) &&
			startIndex  != endIndex
			) {
			--endIndex;
		}

		if (startIndex != endIndex) {
			swap_generic(&byteArray[sizeOfElement * startIndex], &byteArray[sizeOfElement * endIndex], sizeOfElement);
		} else {
			break;
		}
	}

	free(temp);

	int leftArrayCount;
	int rightArrayCount;

	if (startIndex == 0) {
		leftArrayCount = 1;
	} else if (startIndex == count - 1) {
		leftArrayCount = count - 1;
	} else if (
		(isEqualTo_byte(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex], sizeOfElement) ||
		compare(&byteArray[sizeOfElement * startIndex], &byteArray[pivotIndex], sizeOfElement))
		) {
		leftArrayCount = startIndex + 1;
	} else {
		leftArrayCount = startIndex;
	}

	rightArrayCount = count - leftArrayCount;

	if (leftArrayCount > 1) {
		quicksortGeneric_02(byteArray, leftArrayCount, sizeOfElement, compare);
	}

	if (rightArrayCount > 1) {
		quicksortGeneric_02(byteArray + sizeOfElement * leftArrayCount, rightArrayCount, sizeOfElement, compare);
	}
}



void quicksortGeneric(void *array, int count, int sizeOfElement, int (*compare)(void* plhs, void* prhs, int sizeOfElement)) {
	int startIndex = 0;
	int endIndex = count - 1;
	unsigned char* byteArray = (unsigned char*)array;

	int pivotIndex = startIndex;

	void* temp = malloc(sizeOfElement);

	if (!compare(&byteArray[startIndex], &byteArray[endIndex], sizeOfElement)) {
		memcpy(temp, &byteArray[startIndex], sizeOfElement);
		memcpy(&byteArray[startIndex], &byteArray[endIndex], sizeOfElement);
		memcpy(&byteArray[endIndex], temp, sizeOfElement);
	}

	++startIndex;
	--endIndex;

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
