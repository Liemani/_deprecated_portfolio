#pragma once
//********************************************
// char* title = "View"
// made by Lieman at 2020.07.02
//
// description:
//	View
//********************************************





// preprocessor
#include <stdio.h>





void printArray_int(int* intArray, int count) {
	putchar('{');
	for (int i = 0; i < count; ++i) {
		printf("%d, ", intArray[i]);
	}
	printf("\b\b}");

	putchar('\n');
	putchar('\n');
}

void printArray_byte(unsigned char* byteArray, int count) {
	putchar('{');
	for (int i = 0; i < count; ++i) {
		printf("%d, ", byteArray[i]);
	}
	printf("\b\b}");

	putchar('\n');
	putchar('\n');
}