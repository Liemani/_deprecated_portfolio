#pragma once
//********************************************
// char* title = "selectionSort"
// made by Lieman at 2020.06.04
//
// description:
//	selectionSort example
//********************************************





// preprocessor
#include <stdio.h>

#include "swap.h"





/// <summary>
/// <para>assume data type as signed integer value</para>
/// <para>only for big-endian system</para>
/// </summary>
void selectionSort(void* array, int count, int sizeOfElement, int (*compare)(void* lhs, void* rhs, int sizeOfElement)) {
	unsigned char* charArray = (unsigned char*)array;

	for (int i = 0; i < sizeOfElement * (count - 1); i += sizeOfElement) {
		for (int j = i + sizeOfElement; j < sizeOfElement * count; j += sizeOfElement) {
			if (compare(&charArray[i], &charArray[j], sizeOfElement)) {
				int temp = charArray[i];
				charArray[i] = charArray[j];
				charArray[j] = temp;
			}
		}
	}
}