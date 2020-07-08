#pragma once
//********************************************
// char* title = "SimpleString.c"
// made by Lieman at 2020.07.08
//
// description:
//	SimpleString implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include <string.h>		// strcpy()
#include "SimpleString.h"





// static method
// method





// SimpleString factory method
SimpleString* allocSimpleString() {
	SimpleString* simpleString = (SimpleString*)malloc(sizeof(SimpleString));

	return simpleString;
}

SimpleString* newSimpleString__shallowMemberwise(char* string, int count) {
	SimpleString* simpleString = allocSimpleString();

	simpleString->string = string;
	simpleString->count = count;

	return simpleString;
}

SimpleString* newSimpleString__deepMemberwise(char* string, int count) {
	SimpleString* simpleString = allocSimpleString();

	simpleString->string = (char*)malloc(sizeof(char) * count + 1);
	strcpy(simpleString->string, string);
	simpleString->count = count;

	return simpleString;
}

SimpleString* newSimpleString() {
	SimpleString* simpleString = allocSimpleString();

	simpleString->string = NULL;
	simpleString->count = 0;

	return simpleString;
}

void freeSimpleString__shallow(SimpleString* simpleString) {
	free(simpleString);
}

void freeSimpleString__deep(SimpleString* simpleString) {
	free(simpleString->string);
	free(simpleString);
}