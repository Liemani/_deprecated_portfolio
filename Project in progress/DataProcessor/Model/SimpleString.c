#pragma once
//********************************************
// char* title = "SimpleString.c"
// made by Lieman at 2020.07.10
//
// description:
//	SimpleString implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// strcpy(), strlen(), strcat()
#include <assert.h>		// assert()
#include "SimpleString.h"
#pragma warning(disable:4996) //strcpy()





// static variable
static const int ALLOC_INTERVAL = sizeof(int);





// method
int SimpleString__reallocIfNeed(SimpleString* string, int countDelta) {
	int afterChunk = (string->count + 1 + countDelta) / ALLOC_INTERVAL + 1;

	if (string->chunk != afterChunk) {
		string->string = (char*)realloc(string->string, ALLOC_INTERVAL * afterChunk);
		assert(string->string);
		string->chunk = afterChunk;
	}
}

void SimpleString__append__Character(SimpleString* string, char character) {
	SimpleString__reallocIfNeed(string, 1);
	string->string[string->count] = character;
	string->string[string->count + 1] = '\0';

	++string->count;
}

void SimpleString__append__String(SimpleString* simpleString, char* string) {
	int stringCount = strlen(string);

	SimpleString__reallocIfNeed(simpleString, stringCount);
	strcat(simpleString->string, string);

	simpleString->count += stringCount;
}

void SimpleString__append__SimpleString(SimpleString* lhs, SimpleString* rhs) {
	SimpleString__reallocIfNeed(lhs, rhs->count);
	strcat(lhs->string, rhs->string);

	lhs->count += rhs->count;
}

void SimpleString__append__hex__fromCharacter(SimpleString* string, char character) {
	char hexArray[3];

	char hex = character >> 4;
	hexArray[0] = hex + (hex < 10 ? '0' : 'A' - 10);

	hex = character & 0x0F;
	hexArray[1] = hex + (hex < 10 ? '0' : 'A' - 10);

	hexArray[2] = '\0';

	SimpleString__append__String(string, hexArray);
}

void SimpleString__append__data__fromCharacter(SimpleString* string, char character) {
	if (
		character <= 0 ||
		character == 7 ||
		character == 8 ||
		character == 9 ||
		character == 10 ||
		character == 13 ||
		character == 27 ||
		character == 32 ||
		127 <= character) {
		SimpleString__append__Character(string, '.');
	} else {
		SimpleString__append__Character(string, character);
	}
}

char SimpleStringg__removeLast(SimpleString* string) {
	char character = string->string[string->count - 1];
	SimpleString__reallocIfNeed(string, -1);
	string->string[string->count - 1] = '\0';

	return character;
}

void SimpleStringg__removeAll(SimpleString* string) {
	string->count = 0;
	string->chunk = 1;

	free(string->string);
	string->string = (char*)malloc(ALLOC_INTERVAL * string->chunk);
	assert(string->string);

	string->string[0] = '\0';
}

void SimpleStringg__uppercase(SimpleString* string) {
	char character;

	for (int i = 0; i < string->count; ++i) {
		character = string->string[i];

		if ('a' <= character && character <= 'z') {
			character += - 'a' + 'A';
			string->string[i] = character;
		}
	}
}

void SimpleString__lowercase(SimpleString* string) {
	char character;

	for (int i = 0; i < string->count; ++i) {
		character = string->string[i];

		if ('A' <= character && character <= 'Z') {
			character += - 'A' + 'a';
			string->string[i] = character;
		}
	}
}





// SimpleString factory method
SimpleString* allocSimpleString() {
	SimpleString* simpleString = (SimpleString*)malloc(sizeof(SimpleString));

	return simpleString;
}

SimpleString* newSimpleString__designated(char* string, int count) {
	SimpleString* simpleString = allocSimpleString();

	simpleString->count = count;
	simpleString->chunk = (count + 1) / ALLOC_INTERVAL + 1;

	simpleString->string = (char*)malloc(ALLOC_INTERVAL * simpleString->chunk);
	assert(simpleString->string);

	if (string)
		strcpy(simpleString->string, string);
	else
		simpleString->string[0] = '\0';

	return simpleString;
}

SimpleString* newSimpleString() {
	return newSimpleString__designated(NULL, 0);
}

SimpleString* newSimpleString__String(char* string) {
	if (string == NULL) return newSimpleString();

	return newSimpleString__designated(string, strlen(string));
}

SimpleString* newSimpleString__SimpleString(SimpleString* simpleString) {
	return newSimpleString__designated(simpleString->string, simpleString->count);
}

void deallocSimpleString__memberwise(SimpleString* simpleString) {
	free(simpleString);
}

void deallocSimpleString__designated(SimpleString* simpleString) {
	free(simpleString->string);
	free(simpleString);
}
