#pragma once
//********************************************
// unsigned char* title = "LMTArrayData.c"
// made by Lieman at 2020.07.15
//
// description:
//	LMTArrayData implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// memcpy(), strlen()
#pragma warning(disable:4996) //strcpy()
#include "LMTArrayData.h"





// static variable
static const int ALLOC_INTERVAL = sizeof(int);





// static method
// what about use '_' for space in the name of which the meanning is important?
static int LMTArrayData__have_another_reference(const LMTArrayData* lmtArrayData) {
	// if lmtArrayData->referenceCount == 0 than arrayData have not another reference,	return false
	// if lmtArrayData->referenceCount != 0 than arrayData have another reference,		return true
	// if arrayData have not another reference,											lmtArrayData->referenceCount is false
	// if arrayData have another reference,												lmtArrayData->referenceCount is true

	//* abstract concept *							* truth table of target *				* result expecting *
	// if arrayData don't have another reference,	lmtArrayData->referenceCount is false,	and should return false
	// if arrayData have another reference,			lmtArrayData->referenceCount is true,	and should return true
	return lmtArrayData->referenceCount;
}

static int LMTArrayData__dont_have_another_reference(const LMTArrayData* lmtArrayData) {
	return !lmtArrayData->referenceCount;
}

static int LMTArrayData__chunk(int count) {
	return (count - 1) / ALLOC_INTERVAL + 1;
}

static void LMTArrayData__prepareMutating(LMTArrayData** pLMTArrayData, int countDelta) {
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
void LMTArrayData__append__Character(LMTArrayData** pLMTArrayData, char character) {
	LMTArrayData__prepareMutating(pLMTArrayData, 1);
	LMTArrayData* lmtArrayData = *pLMTArrayData;

	lmtArrayData->data[lmtArrayData->count] = (unsigned char)character;
	++lmtArrayData->count;
}

void LMTArrayData__append__data(LMTArrayData** pLMTArrayData, unsigned char* data, int count) {
	LMTArrayData__prepareMutating(pLMTArrayData, count);
	LMTArrayData* lmtArrayData = *pLMTArrayData;

	memcpy(lmtArrayData->data + lmtArrayData->count, data, count);

	lmtArrayData->count += count;
}

void LMTArrayData__append__LMTArrayData(LMTArrayData** pLHS, LMTArrayData* rhs) {
	LMTArrayData__prepareMutating(pLHS, rhs->count);
	LMTArrayData* lhs = *pLHS;

	memcpy(lhs->data + lhs->count, rhs->data, rhs->count);

	lhs->count += rhs->count;
}

unsigned char LMTArrayData__removeLast(LMTArrayData** pLMTArrayData) {
	LMTArrayData* lmtArrayData = *pLMTArrayData;
	unsigned char uCharacter = lmtArrayData->data[lmtArrayData->count - 1];

	LMTArrayData__prepareMutating(pLMTArrayData, -1);
	lmtArrayData = *pLMTArrayData;

	return uCharacter;
}

void LMTArrayData__removeAll(LMTArrayData** pLMTArrayData) {
	deallocLMTArrayData(*pLMTArrayData);

	*pLMTArrayData = newLMTArrayData();
}

// deprecated
static void LMTArrayData__reallocIfNeed(LMTArrayData** pLMTArrayData, int countDelta) {
	LMTArrayData* lmtArrayData = *pLMTArrayData;

	int afterChunk = LMTArrayData__chunk(lmtArrayData->count + countDelta);

	if (lmtArrayData->chunk == afterChunk) return;

	lmtArrayData->data = (unsigned char*)realloc(lmtArrayData->data, ALLOC_INTERVAL * afterChunk);
	lmtArrayData->count += countDelta;
	lmtArrayData->chunk = afterChunk;
}

void LMTArrayData__append__hex__fromCharacter(LMTArrayData* lmtArrayData, char character) {
	unsigned char hexArray[2];

	unsigned char hex = (unsigned char)character >> 4;
	hexArray[0] = hex + (hex < 10 ? '0' : 'A' - 10);

	hex = (unsigned char)character & 0x0F;
	hexArray[1] = hex + (hex < 10 ? '0' : 'A' - 10);

	LMTArrayData__append__data(lmtArrayData, hexArray, 2);
}

void LMTArrayData__append__visibleCharacter__fromCharacter(LMTArrayData* lmtArrayData, char character) {
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

		LMTArrayData__append__Character(lmtArrayData, '.');
	} else {
		LMTArrayData__append__Character(lmtArrayData, character);
	}
}





// LMTArrayData factory method
static LMTArrayData* allocLMTArrayData() {
	LMTArrayData* lmtArrayData = (LMTArrayData*)malloc(sizeof(LMTArrayData));

	return lmtArrayData;
}

static LMTArrayData* newLMTArrayData__designated(const unsigned char* data, int count, int chunk) {
	LMTArrayData* lmtArrayData = allocLMTArrayData();

	lmtArrayData->count = count;
	lmtArrayData->chunk = chunk;

	lmtArrayData->data = (unsigned char*)malloc(ALLOC_INTERVAL * chunk);

	if (data) memcpy(lmtArrayData->data, data, count);

	lmtArrayData->referenceCount = 0;

	return lmtArrayData;
}

LMTArrayData* newLMTArrayData__data(const unsigned char* data, int count) {
	int chunk = LMTArrayData__chunk(count);

	LMTArrayData* lmtArrayData = newLMTArrayData__designated(data, count, chunk);

	return lmtArrayData;
}

LMTArrayData* newLMTArrayData() {
	return newLMTArrayData__designated(NULL, 0, 1);
}

// if init from data, make new object.
// if init from object, make new reference.
LMTArrayData* newLMTArrayData__String(const char* string) {
	if (string) return newLMTArrayData__data((const unsigned char*)string, strlen(string));

	return newLMTArrayData();
}

LMTArrayData* newLMTArrayData__LMTArrayData__count(LMTArrayData* lmtArrayData, int count) {
	int chunk = LMTArrayData__chunk(count);

	lmtArrayData = newLMTArrayData__designated(lmtArrayData->data, min(lmtArrayData->count, count), chunk);

	return lmtArrayData;
}

LMTArrayData* referenceLMTArrayData__LMTArrayData(LMTArrayData* lmtArrayData) {
	if (lmtArrayData == NULL) return NULL;

	++lmtArrayData->referenceCount;

	return lmtArrayData;
}

void deallocLMTArrayData(LMTArrayData* lmtArrayData) {
	if (lmtArrayData == NULL) return;

	if (LMTArrayData__have_another_reference(lmtArrayData))
		--lmtArrayData->referenceCount;
	else {
		free(lmtArrayData->data);
		free(lmtArrayData);
	}
}
