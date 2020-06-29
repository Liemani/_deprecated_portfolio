#pragma once
//********************************************
// char* title = "bubbleSort"
// made by Lieman at 2020.06.04
//
// description:
//	bubbleSort example
//********************************************





// preprocessor
#include <stdio.h>

#include "swap.h"





/// <summary>
/// <para>assume data type as signed integer value</para>
/// <para>only for big-endian system</para>
/// </summary>
void bubbleSort(void* array, int count, int sizeOfElement, int (*compare)(void* lhs, void* rhs, int sizeOfElement)) {
	unsigned char* charArray = (unsigned char*)array;

	for (int i = sizeOfElement * (count - 1); i > 0; i -= sizeOfElement) {
		for (int j = 0; j < i; j += sizeOfElement) {
			if (compare(&charArray[j], &charArray[j + sizeOfElement], sizeOfElement)) {
				swap(&charArray[j], &charArray[j + sizeOfElement], sizeOfElement);
			}
		}
	}
}