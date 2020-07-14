#pragma once
//********************************************
// char* title = "LMTString.c"
// made by Lieman at 2020.07.14
//
// description:
//	LMTString implementation
//********************************************





// preprocessor
#include "LMTString.h"





// static variable
static const int ALLOC_INTERVAL = sizeof(int);





// method
void LMTString__reallocIfNeed(LMTString* lmtString, int countDelta) {
	int afterChunk = (lmtString->count + countDelta) / ALLOC_INTERVAL + 1;

	if (lmtString->chunk == afterChunk) return;

	lmtString->string = (char*)realloc(lmtString->string, ALLOC_INTERVAL * afterChunk);
	lmtString->chunk = afterChunk;
}

void LMTString__append__Character(LMTString* lmtString, char character) {
	LMTString__reallocIfNeed(lmtString, 1);

	lmtString->string[lmtString->count] = character;

	++lmtString->count;

	lmtString->string[lmtString->count] = '\0';
}

void LMTString__append__String(LMTString* lmtString, char* string) {
	if (string == NULL) return;

	const int count = strlen(string);

	LMTString__reallocIfNeed(lmtString, count);

	strcpy(lmtString->string, string);

	lmtString->count += count;
}

void LMTString__append__LMTString(LMTString* lhs, LMTString* rhs) {
	LMTString__reallocIfNeed(lhs, rhs->count);

	strcpy(lhs->string, rhs->string);

	lhs->count += rhs->count;
}

void LMTString__append__visibleCharacter__fromCharacter(LMTString* lmtString, char character) {
	if (
		character <= 0 ||
		(7 <= character &&
		character <= 10) ||
		character == 13 ||
		character == 27 ||
		character == 32 ||
		127 <= character) {

		LMTString__append__Character(lmtString, '.');
	} else {
		LMTString__append__Character(lmtString, character);
	}
}

char LMTStringg__removeLast(LMTString* lmtString) {
	char uCharacter = lmtString->string[lmtString->count - 1];

	LMTString__reallocIfNeed(lmtString, -1);

	--lmtString->count;

	return uCharacter;
}

void LMTStringg__removeAll(LMTString* lmtString) {
	lmtString->count = 0;
	lmtString->chunk = 1;

	free(lmtString->string);
	lmtString->string = (char*)malloc(ALLOC_INTERVAL * lmtString->chunk);
}





// LMTString factory method
static LMTString* allocLMTString() {
	LMTString* lmtString = (LMTString*)malloc(sizeof(LMTString));

	return lmtString;
}

static LMTString* newLMTString__designated(char* string, int count, int chunk) {
	LMTString* lmtString = allocLMTString();

	lmtString->count = count;
	lmtString->chunk = chunk;

	lmtString->string = (char*)malloc(ALLOC_INTERVAL * chunk);

	if (string) strcpy(lmtString->string, string);
	else lmtString->string[0] = '\0';

	lmtString->referenceCount = 1;

	return lmtString;
}

LMTString* newLMTString() {
	return newLMTString__designated(NULL, 0, 1);
}

LMTString* newLMTString__String(char* string) {
	if (string == NULL) return newLMTString();

	const int count = strlen(string);
	const int chunk = count / ALLOC_INTERVAL + 1;
	
	return newLMTString__designated(string, count, chunk);
}

void deallocLMTString(LMTString* lmtString) {
	free(lmtString->string);
	free(lmtString);
}
