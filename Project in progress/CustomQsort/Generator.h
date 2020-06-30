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
int* randomIntArray(int count, int limit) {
	int* intArray = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; ++i) {
		intArray[i] = rand() % (limit + 1);
	}

	return intArray;
}

unsigned char* randomByteArray(int count, int limit) {
	unsigned char* byteArray = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; ++i) {
		byteArray[i] = rand() % (limit + 1);
	}

	return byteArray;
}

unsigned char randomByte() {
	return (unsigned char) rand();
}