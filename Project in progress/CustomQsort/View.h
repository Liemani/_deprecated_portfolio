#pragma once
//********************************************
// char* title = "View"
// made by Lieman at 2020.06.29
//
// description:
//	View
//********************************************





// preprocessor
#include <stdio.h>





void printIntArray(int* intArray, int count) {
	putchar('{');
	for (int i = 0; i < count; ++i) {
		printf("%d, ", intArray[i]);
	}
	printf("\b\b}");

	putchar('\n');
}