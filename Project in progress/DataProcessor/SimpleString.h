#pragma once
//********************************************
// char* title = "SimpleString.h"
// made by Lieman at 2020.07.08
//
// description:
//	SimpleString interface
//********************************************





// preprocessor





// structure
typedef struct SimpleString {
	char* string;
	int count;
} SimpleString;





// static method
// method





// SimpleString factory method
SimpleString* allocSimpleString();

SimpleString* newSimpleString__shallowMemberwise(char* string, int count);
SimpleString* newSimpleString__deepMemberwise(char* string, int count);
SimpleString* newSimpleString();

void freeSimpleString__shallow(SimpleString* simpleString);
void freeSimpleString__deep(SimpleString* simpleString);
