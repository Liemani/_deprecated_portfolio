#pragma once
//********************************************
// char* title = "SimpleString.h"
// made by Lieman at 2020.07.08
//
// description:
//	SimpleString interface
//********************************************





// preprocessor
#include <wchar.h>
#include "Node.h"





// structure
typedef struct SimpleString {
	char* string;
	size_t count;
} SimpleString;





// static method
// method





// SimpleString factory method
SimpleString* allocSimpleString();
SimpleString* newSimpleString();
