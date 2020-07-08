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
#include "SimpleString.h"
#include "Node.h"





// static method
// method





// SimpleString factory method
SimpleString* allocSimpleString() {
	SimpleString* simpleString = (SimpleString*)malloc(sizeof(SimpleString));

	return simpleString;
}

SimpleString* newSimpleString() {
	SimpleString* simpleString = allocSimpleString();

	return simpleString;
}
