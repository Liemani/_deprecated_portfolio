#pragma once
//********************************************
// char* title = "LMTData.c"
// made by Lieman
//
// description:
//	LMTData implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// memcpy(), strlen()
#pragma warning(disable:4996) //memcpy()
#include "LMTData.h"





// static variable
static const int ALLOC_INTERVAL = sizeof(int);
static LMTData* pEmptyLMTData = NULL;





// static method
// what about use '_' for space in the name of which the meanning is important?
static inline int LMTData__have_another_reference(const LMTData* pLMTData) {
	// if pLMTData->referenceCount == 0 than arrayData have not another reference,	return false
	// if pLMTData->referenceCount != 0 than arrayData have another reference,		return true
	// if arrayData have not another reference,											pLMTData->referenceCount is false
	// if arrayData have another reference,												pLMTData->referenceCount is true

	//* abstract concept *							* truth table of target *				* result expecting *
	// if arrayData don't have another reference,	pLMTData->referenceCount is false,	and should return false
	// if arrayData have another reference,			pLMTData->referenceCount is true,	and should return true
	return pLMTData->referenceCount;
}

static inline int LMTData__dont_have_another_reference(const LMTData* pLMTData) {
	return !LMTData__have_another_reference(pLMTData);
}

static inline int LMTData__chunk(int count) {
	return (count - 1) / ALLOC_INTERVAL + 1;
}

static void LMTData__realloc(LMTData** ppLMTData, int countDelta) {
	if (ppLMTData == NULL) return;
	if (*ppLMTData == NULL) return;

	LMTData* pLMTData = *ppLMTData;

	int afterCount = pLMTData->count + countDelta;
	int afterChunk = LMTData__chunk(afterCount);

	if (LMTData__have_another_reference(pLMTData)) {
		--pLMTData->referenceCount;
		*ppLMTData = newLMTData__LMTData__designated(pLMTData, afterCount, afterChunk);

		return;
	}

	pLMTData->count = min(pLMTData->count, afterCount);

	if (pLMTData->chunk != afterChunk) {
		pLMTData->chunk = afterChunk;
		pLMTData->pData = (Data*)realloc(pLMTData->pData, ALLOC_INTERVAL * afterChunk);
	}
}





// method
void LMTData__append__character(LMTData** ppLMTData, char character) {
	LMTData__realloc(ppLMTData, 1);
	LMTData* pLMTData = *ppLMTData;

	pLMTData->pData[pLMTData->count] = (Data)character;
	++pLMTData->count;
}

void LMTData__append__string(LMTData** ppLMTData, char* string) {


}

void LMTData__append__LMTData(LMTData** ppLHS, LMTData* pRHS) {
	LMTData__prepareMutating(ppLHS, pRHS->count);
	LMTData* pLHS = *ppLHS;

	memcpy(pLHS->pData + pLHS->count, pRHS->pData, pRHS->count);

	pLHS->count += pRHS->count;
}

Data LMTData__removeLast(LMTData** ppLMTData) {
	LMTData* pLMTData = *ppLMTData;
	Data data = pLMTData->pData[pLMTData->count - 1];

	LMTData__prepareMutating(ppLMTData, -1);

	return data;
}

void LMTData__removeAll(LMTData** ppLMTData) {
	delLMTData(*ppLMTData);

	*ppLMTData = newLMTData();
}

int LMTData__firstIndex(LMTData* pLMTData, Data data) {
	for (int i = 0; i < pLMTData->count; ++i)
		if (pLMTData->pData[i] == data)
			return i;

	return pLMTData->count;
}





// LMTData factory method
static inline LMTData* allocLMTData() {
	return (LMTData*)malloc(sizeof(LMTData));
}

LMTData* newLMTData__designated(const Data* pData, int count, int chunk) {
	// pData == NULL && count != 0		<=>		!pData && count
	if (!pData && count) return NULL;

	if (pData == NULL && pEmptyLMTData != NULL) {
		++pEmptyLMTData->referenceCount;
		return pEmptyLMTData;
	}

	LMTData* pLMTData = allocLMTData();

	pLMTData->count = count;
	pLMTData->chunk = chunk;

	pLMTData->pData = (Data*)malloc(ALLOC_INTERVAL * chunk);
	if (pData) memcpy(pLMTData->pData, pData, count);
	else pEmptyLMTData = pLMTData;

	pLMTData->referenceCount = 0;

	return pLMTData;
}

inline LMTData* newLMTData__Data(const Data* pData, int count) {
	return newLMTData__designated(pData, count, LMTData__chunk(count));
}

inline LMTData* newLMTData() {
	return newLMTData__designated(NULL, 0, 1);
}

LMTData* newLMTData__string(const char* string) {
	if (string == NULL) return newLMTData();
	else return newLMTData__data((const Data*)string, strlen(string));
}

LMTData* newLMTData__LMTData(LMTData* pLMTData) {
	if (pLMTData == NULL) return newLMTData();

	++pLMTData->referenceCount;

	return pLMTData;
}



void delLMTData(LMTData* pLMTData) {
	if (pLMTData == NULL) return;

	if (LMTData__have_another_reference(pLMTData))
		--pLMTData->referenceCount;
	else {
		if (pLMTData == pEmptyLMTData) pEmptyLMTData == NULL;
		free(pLMTData->pData);
		free(pLMTData);
	}
}





// deprecated
//LMTData* newLMTData__LMTData__count(LMTData* pLMTData, int count) {
//	int chunk = LMTData__chunk(count);
//
//	pLMTData = newLMTData__designated(pLMTData->pData, min(pLMTData->count, count), chunk);
//
//	return pLMTData;
//}

// not accepted in this structure!
//LMTData* copyLMTData__LMTData(LMTData* pRHS) {
//	LMTData* pLMTData = allocLMTData();
//
//	pLMTData->count = pRHS->count;
//	pLMTData->chunk = pRHS->chunk;
//	pLMTData->pData = pRHS->pData;
//
//	pLMTData->referenceCount = 0;
//
//	return pLMTData;
//}

//static void LMTData__reallocIfNeed(LMTData** ppLMTData, int countDelta) {
//	LMTData* pLMTData = *ppLMTData;
//
//	int afterChunk = LMTData__chunk(pLMTData->count + countDelta);
//
//	if (pLMTData->chunk == afterChunk) return;
//
//	pLMTData->pData = (Data*)realloc(pLMTData->pData, ALLOC_INTERVAL * afterChunk);
//	pLMTData->count += countDelta;
//	pLMTData->chunk = afterChunk;
//}
//
//void LMTData__append__hex__fromCharacter(LMTData* pLMTData, char character) {
//	Data hexArray[2];
//
//	Data hex = (Data)character >> 4;
//	hexArray[0] = hex + (hex < 10 ? '0' : 'A' - 10);
//
//	hex = (Data)character & 0x0F;
//	hexArray[1] = hex + (hex < 10 ? '0' : 'A' - 10);
//
//	LMTData__append__data(pLMTData, hexArray, 2);
//}
//
//void LMTData__append__visibleCharacter__fromCharacter(LMTData* pLMTData, char character) {
//	if (
//		character <= 0 ||
//		character == 7 ||
//		character == 8 ||
//		character == 9 ||
//		character == 10 ||
//		character == 13 ||
//		character == 27 ||
//		character == 32 ||
//		127 <= character) {
//
//		LMTData__append__Character(pLMTData, '.');
//	} else {
//		LMTData__append__Character(pLMTData, character);
//	}
//}

//LMTData* cloneLMTData__LMTData(LMTData* pRHS) {
//	LMTData* pLMTData = allocLMTData();
//
//	pLMTData->count = pRHS->count;
//	pLMTData->chunk = pRHS->chunk;
//
//	pLMTData->pData = (Data*)malloc(ALLOC_INTERVAL * pRHS->chunk);
//	memcpy(pLMTData->pData, pRHS->pData, pRHS->count);
//
//	pLMTData->referenceCount = 0;
//
//	return pLMTData;
//}

//void LMTData__append__Data(LMTData** ppLMTData, Data* data, int count) {
//	LMTData__prepareMutating(ppLMTData, count);
//	LMTData* pLMTData = *ppLMTData;
//
//	memcpy(pLMTData->pData + pLMTData->count, data, count);
//
//	pLMTData->count += count;
//}