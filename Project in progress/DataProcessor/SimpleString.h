#pragma once
//********************************************
// char* title = "SimpleString.h"
// made by Lieman at 2020.07.09
//
// description:
//	SimpleString interface
//********************************************





// preprocessor





// structure
typedef struct SimpleString {
	int count;
	int chunk;
	char* string;
} SimpleString;





// static variable
static const int ALLOC_INTERVAL;





// static method
static int SimpleString__reallocIfNeed(SimpleString* string, int countDelta);

// method
void SimpleString__append__Character(SimpleString* string, char character);
void SimpleString__append__String(SimpleString* simpleString, char* string);
void SimpleString__append__SimpleString(SimpleString* lhs, SimpleString* rhs);
void SimpleString__append__hex__fromUCharacter(SimpleString* string, unsigned char character);

char SimpleStringg__removeLast(SimpleString* string);
void SimpleStringg__removeAll(SimpleString* string);

void SimpleString__uppercase(SimpleString* string);
void SimpleString__lowercase(SimpleString* string);





// SimpleString factory method
SimpleString* allocSimpleString();

SimpleString* newSimpleString__memberwise(char* string, int count);
SimpleString* newSimpleString__designated(char* string, int count);

SimpleString* newSimpleString();

SimpleString* newSimpleString__String(char* string);
SimpleString* newSimpleString__SimpleString(SimpleString* simpleString);

char SimpleStringg__removeLast(SimpleString* string);

void freeSimpleString__memberwise(SimpleString* simpleString);
void freeSimpleString__designated(SimpleString* simpleString);
