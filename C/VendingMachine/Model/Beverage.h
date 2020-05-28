#pragma once
//********************************************
// char* title = "beverage"
// made by Lieman at 2020.05.27
//
// description:
//	beverage example
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Resource/constant.h"

#pragma warning(disable:4996)





// global variable
typedef struct Beverage {
	char* name;
	int cost;

	void (*dealloc)(struct Beverage* beverage);
} Beverage;





// function
// deallocation
void _Beverage_dealloc(struct Beverage* beverage) {
	free(beverage->name);
	free(beverage);
}





// allocation
Beverage* _Beverage_alloc() {
	Beverage* beverage = (Beverage*)malloc(sizeof(Beverage));

	// allocate properties
	beverage->name = (char*)malloc(sizeof(char) * BEVERAGE_NAME_COUNT_LIMIT);

	// initialize methods
	beverage->dealloc = _Beverage_dealloc;

	return beverage;
}

// initialization
Beverage* newBeverage(char* name, int cost) {
	Beverage* beverage = _Beverage_alloc();

	// initialize properties
	beverage->name = (char*)malloc(sizeof(char) * BEVERAGE_NAME_COUNT_LIMIT);
	strcpy(beverage->name, name);
	beverage->name = (char*)realloc(beverage->name, sizeof(char) * (strlen(beverage->name) + 1)); // memory leak warning

	beverage->cost = cost;

	return beverage;
}