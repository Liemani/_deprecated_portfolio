#pragma once
//********************************************
// unsigned char* title = "LMTArrayData.c"
// made by Lieman at 2020.07.14
//
// description:
//	LMTArrayData implementation
//********************************************





// preprocessor
#include "LMTArrayData.h"





// static variable
static const int ALLOC_INTERVAL = sizeof(int);





// static method
static int LMTArrayData__chunk(int count) {
	return (count - 1) / ALLOC_INTERVAL + 1;
}

static void LMTArrayData__reallocIfNeed(LMTArrayData* lmtArrayData, int countDelta) {
	int afterChunk = LMTArrayData__chunk(lmtArrayData->count + countDelta);

	if (lmtArrayData->chunk == afterChunk) return;

	lmtArrayData->data = (unsigned char*)realloc(lmtArrayData->data, ALLOC_INTERVAL * afterChunk);
	lmtArrayData->count += countDelta;
	lmtArrayData->chunk = afterChunk;
}

// method
void LMTArrayData__append__Character(LMTArrayData** pLMTArrayData, char character) {
	LMTArrayData* lmtArrayData = *pLMTArrayData;

	if (lmtArrayData->referenceCount == 1) {
		LMTArrayData__reallocIfNeed(lmtArrayData, 1);

		lmtArrayData->data[lmtArrayData->count - 1] = (unsigned char)character;
	} else {
		--lmtArrayData->referenceCount;

		*pLMTArrayData = newLMTArrayData__LMTArrayData(lmtArrayData);
		// how to make reculcive call to loop with readability
		LMTArrayData__append__Character(pLMTArrayData, character);
	}
}

void LMTArrayData__append__data(LMTArrayData* lmtArrayData, unsigned char* data, int count) {
	LMTArrayData__reallocIfNeed(lmtArrayData, count);

	for (int i = 0; i < count; ++i) lmtArrayData->data[lmtArrayData->count + i] = data[i];

	lmtArrayData->count += count;
}

void LMTArrayData__append__LMTArrayData(LMTArrayData* lhs, LMTArrayData* rhs) {
	LMTArrayData__reallocIfNeed(lhs, rhs->count);

	for (int i = 0; i < rhs->count; ++i) lhs->data[lhs->count + i] = rhs->data[i];

	lhs->count += rhs->count;
}

void LMTArrayData__append__hex__fromCharacter(LMTArrayData* lmtArrayData, char character) {
	unsigned char hexArray[2];

	unsigned char hex = character >> 4;
	hexArray[0] = hex + (hex < 10 ? '0' : 'A' - 10);

	hex = character & 0x0F;
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

unsigned char LMTArrayDatag__removeLast(LMTArrayData* lmtArrayData) {
	unsigned char uCharacter = lmtArrayData->data[lmtArrayData->count - 1];

	LMTArrayData__reallocIfNeed(lmtArrayData, -1);

	--lmtArrayData->count;

	return uCharacter;
}

void LMTArrayDatag__removeAll(LMTArrayData* lmtArrayData) {
	lmtArrayData->count = 0;
	lmtArrayData->chunk = 1;

	free(lmtArrayData->data);
	lmtArrayData->data = (unsigned char*)malloc(ALLOC_INTERVAL * lmtArrayData->chunk);
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

	lmtArrayData->referenceCount = 1;

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
	if (string) return newLMTArrayData__Data((const unsigned char*)string, strlen(string));

	return newLMTArrayData();
}

LMTArrayData* newLMTArrayData__LMTArrayData(LMTArrayData* lmtArrayData) {
	++lmtArrayData->referenceCount;

	return lmtArrayData;
}

void deallocLMTArrayData(LMTArrayData* lmtArrayData) {
	if (lmtArrayData->referenceCount == 1) free(lmtArrayData->data);

	free(lmtArrayData);
}
