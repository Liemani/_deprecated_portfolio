#pragma once
//********************************************
// char* title = "LMTString.c"
// made by Lieman at 2020.07.15
//
// description:
//	LMTString implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// strcpy(), strlen(), strcat()
#pragma warning(disable:4996) //strcpy()
#include "LMTString.h"
#include "LMTArrayData.h"





// static variable
static const int ALLOC_INTERVAL = sizeof(int);





// static method
static int LMTString__have_another_reference(const LMTString* lmtString) {
	//* abstract concept *							* truth table of target *				* result expecting *
	// if string don't have another reference,	lmtString->referenceCount is false,	and should return false
	// if string have another reference,		lmtString->referenceCount is true,	and should return true
	return lmtString->referenceCount;
}

static int LMTString__dont_have_another_reference(const LMTString* lmtString) {
	//* abstract concept *							* truth table of target *				* result expecting *
	// if string don't have another reference,	lmtString->referenceCount is false,	and should return true
	// if string have another reference,		lmtString->referenceCount is true,	and should return false
	return !lmtString->referenceCount;
}

static void LMTString__makeDataStringIfNeed(LMTString* lmtString) {
	LMTArrayData* data = lmtString->data;

	lmtString->count = LMTArrayData__firstIndex(data, (unsigned char)'\0');

	if (lmtString->count == data->count) {
		LMTArrayData__append__Character(&lmtString->data, '\0');
		++lmtString->count;
	}
}

static void LMTString__prepareMutating(LMTString** pLMTString) {
	if (pLMTString == NULL) return;
	if (*pLMTString == NULL) return;
	if (LMTString__dont_have_another_reference(*pLMTString)) return;

	LMTString* lmtString = *pLMTString;

	--lmtString->referenceCount;
	*pLMTString = newLMTString__data(lmtString->data);




	--lmtString->referenceCount;
	*pLMTString = newLMTString__referenceData;

	LMTArrayData* lmtArrayData = *pLMTArrayData;

	int afterCount = lmtArrayData->count + countDelta;
	int afterChunk = LMTArrayData__chunk(afterCount);

	if (LMTArrayData__have_another_reference(lmtArrayData)) {
		--lmtArrayData->referenceCount;
		*pLMTArrayData = newLMTArrayData__LMTArrayData__count(lmtArrayData, afterCount);
	} else  if (lmtArrayData->chunk != afterChunk) {
		lmtArrayData->count = min(lmtArrayData->count, afterCount);
		lmtArrayData->chunk = afterChunk;
		lmtArrayData->data = (unsigned char*)realloc(lmtArrayData->data, ALLOC_INTERVAL * afterChunk);
	}
}





// method
//void LMTString__reallocIfNeed(LMTString* lmtString, int countDelta) {
//	int afterChunk = (lmtString->count + countDelta) / ALLOC_INTERVAL + 1;
//
//	if (lmtString->chunk == afterChunk) return;
//
//	lmtString->string = (char*)realloc(lmtString->string, ALLOC_INTERVAL * afterChunk);
//	lmtString->chunk = afterChunk;
//}

void LMTString__append__Character(LMTString** pLMTString, char character) {
	LMTString* lmtString = *pLMTString;

	if (LMTString__have_another_reference(lmtString)) {
		--lmtString->referenceCount;
		*pLMTString = newLMTString__data(lmtString->data);
	} else {

	}

	LMTArrayData__append__Character(&lmtString->data, '\0');

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

static LMTString* newLMTString__designated(LMTArrayData* data) {
	LMTString* lmtString = allocLMTString();

	lmtString->count = data->count;

	lmtString->data = referenceLMTArrayData__LMTArrayData(data);

	lmtString->referenceCount = 0;

	return lmtString;
}

LMTString* newLMTString() {
	LMTArrayData* data = newLMTArrayData__String("");

	return newLMTString__designated(data);
}

LMTString* newLMTString__String(char* string) {
	if (string == NULL) return newLMTString();

	LMTArrayData* data = newLMTArrayData__String(string);

	return newLMTString__designated(data);
}

LMTString* newLMTString__data(LMTArrayData* data) {
	if (data == NULL) return newLMTString();

	return newLMTString__designated(data);
}

LMTString* referenceLMTString__LMTString(LMTString* lmtString) {
	if (lmtString == NULL) return NULL;

	++lmtString->referenceCount;

	return lmtString;
}

void setLMTString__LMTString(LMTString** pLMTString, LMTString* string) {
	if (pLMTString == NULL) return;

	LMTString* lmtString = *pLMTString;

	if (lmtString == string) return;

	if (lmtString == NULL)
		*pLMTString = referenceLMTString__LMTString(string);


	if (LMTString__have_another_reference(lmtString)) {
		--(*pLMTString)->referenceCount;
		*pLMTString = newLMTString__String(lmtString);
	} else (LMTString__dont_have_another_reference(lmtString)) {
		lmtString
	}

	//if (string == NULL)
	//	*pLMTString = newLMTString();
}

void deallocLMTString(LMTString* lmtString) {
	if (lmtString == NULL) return;

	if (LMTString__have_another_reference(lmtString))
		--lmtString->referenceCount;
	else {
		deallocLMTArrayData(lmtString->data);
		free(lmtString);
	}
}
