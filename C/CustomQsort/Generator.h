#pragma once
//********************************************
// char* title = "Generator"
// made by Lieman at 2020.06.29
//
// description:
//	Generator
//********************************************





// preprocessor
#include <stdlib.h>	// malloc()
#include <time.h>	// time()





// function
int* RandomIntArray(int count, int limit) {
	int* intArray = (int*)malloc(sizeof(int) * count);

	srand(time(NULL));

	for (int i = 0; i < count; ++i) {
		intArray[i] = rand() % (limit + 1);
	}

	return intArray;
}