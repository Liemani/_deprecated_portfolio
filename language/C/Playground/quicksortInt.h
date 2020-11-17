#pragma once
//********************************************
// char* title = "quicksortInt"
// made by Lieman at 2020.06.05
//
// description:
//	quicksortInt example
//********************************************





// preprocessor
#include <stdio.h>





void quicksortInt(int* array, int count) {
	int startIndex = 0;
	int endIndex = count - 1;

	int middleValue = (array[startIndex] + array[endIndex]) / 2;

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
		}
		else
			break;
	}

	int leftArrayCount = startIndex;
	if (leftArrayCount > 1)
		quicksortInt(array, leftArrayCount);

	int rightArraycount = count - leftArrayCount;
	if (rightArraycount > 1)
		quicksortInt(array + leftArrayCount, rightArraycount);
}