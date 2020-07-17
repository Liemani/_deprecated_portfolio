#pragma once
//********************************************
// unsigned char* title = "LMTData.c"
// made by Lieman at 2020.07.13
//
// description:
//	LMTData implementation
//********************************************





// preprocessor
#include "LMTData.h"





// static variable
static const int ALLOC_INTERVAL = sizeof(int);





// method
void LMTData__reallocIfNeed(LMTData* lmtData, int countDelta) {
	int afterChunk = (lmtData->count + countDelta - 1) / ALLOC_INTERVAL + 1;

	if (lmtData->chunk == afterChunk) return;

	lmtData->data = (unsigned char*)realloc(lmtData->data, ALLOC_INTERVAL * afterChunk);
	lmtData->chunk = afterChunk;
}

void LMTData__append__Character(LMTData* lmtData, char character) {
	LMTData__reallocIfNeed(lmtData, 1);

	lmtData->data[lmtData->count] = (unsigned char)character;

	++lmtData->count;
}

void LMTData__append__data(LMTData* lmtData, unsigned char* data, int count) {
	LMTData__reallocIfNeed(lmtData, count);

	for (int i = 0; i < count; ++i) lmtData->data[lmtData->count + i] = data[i];

	lmtData->count += count;
}

void LMTData__append__LMTData(LMTData* lhs, LMTData* rhs) {
	LMTData__reallocIfNeed(lhs, rhs->count);

	for (int i = 0; i < rhs->count; ++i) lhs->data[lhs->count + i] = rhs->data[i];

	lhs->count += rhs->count;
}

void LMTData__append__hex__fromCharacter(LMTData* lmtData, char character) {
	unsigned char hexArray[2];

	unsigned char hex = character >> 4;
	hexArray[0] = hex + (hex < 10 ? '0' : 'A' - 10);

	hex = character & 0x0F;
	hexArray[1] = hex + (hex < 10 ? '0' : 'A' - 10);

	LMTData__append__data(lmtData, hexArray, 2);
}

void LMTData__append__visibleCharacter__fromCharacter(LMTData* lmtData, char character) {
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

		LMTData__append__Character(lmtData, '.');
	} else {
		LMTData__append__Character(lmtData, character);
	}
}

unsigned char LMTDatag__removeLast(LMTData* lmtData) {
	unsigned char uCharacter = lmtData->data[lmtData->count - 1];

	LMTData__reallocIfNeed(lmtData, -1);

	--lmtData->count;

	return uCharacter;
}

void LMTDatag__removeAll(LMTData* lmtData) {
	lmtData->count = 0;
	lmtData->chunk = 1;

	free(lmtData->data);
	lmtData->data = (unsigned char*)malloc(ALLOC_INTERVAL * lmtData->chunk);
}





// LMTData factory method
static LMTData* allocLMTData() {
	LMTData* lmtData = (LMTData*)malloc(sizeof(LMTData));

	return lmtData;
}

static LMTData* newLMTData__designated(unsigned char* data, int count, int chunk) {
	LMTData* lmtData = allocLMTData();

	lmtData->count = count;
	lmtData->chunk = chunk;

	lmtData->data = (unsigned char*)malloc(ALLOC_INTERVAL * chunk);

	if (data)
		strcpy(lmtData->data, data);

	return lmtData;
}

LMTData* newLMTData__data(unsigned char* data, int count) {
	int chunk = (count - 1) / ALLOC_INTERVAL + 1;

	LMTData* lmtData = newLMTData__designated(data, count, chunk);

	return lmtData;
}

LMTData* newLMTData() {
	return newLMTData__designated(NULL, 0, 1);
}

LMTData* newLMTData__String(char* string) {
	if (string) return newLMTData__data((unsigned char *)string, strlen(string));

	return newLMTData();
}

LMTData* newLMTData__LMTData(LMTData* lmtData) {
	return newLMTData__designated(lmtData->data, lmtData->count, lmtData->chunk);
}

void deallocLMTData(LMTData* lmtData) {
	free(lmtData->data);
	free(lmtData);
}
