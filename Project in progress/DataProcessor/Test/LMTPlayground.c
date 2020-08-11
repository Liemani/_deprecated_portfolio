//********************************************
// char* title = "LMTPlayground.c"
// made by Lieman
//
// description:
//	LMTPlayground implementation
//********************************************





//********************************************
// 0. index
// 1. preprocessor
//
// 2. type define
//
// 3. static variable
//
// 4. function
//
// 5. factory function
//
// 6. deprecated
//********************************************





// 1. preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// memcpy(), strlen()
#include <assert.h>		// assert()

#pragma warning(disable:4996) //memcpy()

#include "LMTPlayground.h"





// 2. type define
// 1 LMTPlayground must match with 1 pData
// if there is 2 different LMTPlayground have same pData,
// when one of them deleted, pData must delted,
// and the other's pData get NULL!
typedef unsigned char Data;

typedef struct LMTPlayground {
	int count;
	int chunk;
	Data* pData;

	int referenceCount;
} LMTPlayground;





// 3. static variable
static const int ALLOC_INTERVAL = sizeof(int);
static LMTPlayground* pEmptyLMTPlayground = NULL;





// 4. function
// what about use '_' for space in the name of which the meanning is important?
static int LMTPlayground__have_another_reference(const LMTPlayground* pLMTPlayground) {
	assert(pLMTPlayground);
	// if pLMTPlayground->referenceCount == 0 than arrayData have not another reference,  return false
	// if pLMTPlayground->referenceCount != 0 than arrayData have another reference,      return true
	// if arrayData have not another reference,                                     pLMTPlayground->referenceCount is false
	// if arrayData have another reference,                                         pLMTPlayground->referenceCount is true

	//           * abstract concept *                   * truth table of target *         * result expecting *
	// if arrayData don't have another reference,   pLMTPlayground->referenceCount is false,  and should return false
	// if arrayData have another reference,         pLMTPlayground->referenceCount is true,   and should return true
	return pLMTPlayground->referenceCount;
}

static inline int LMTPlayground__dont_have_another_reference(const LMTPlayground* pLMTPlayground) {
	return !LMTPlayground__have_another_reference(pLMTPlayground);
}



static inline int LMTPlayground__count_has_changed(int countDelta) {
	// countDelta != 0    <=>    countDelta
	return countDelta;
}

static inline int LMTPlayground__count_has_not_changed(int countDelta) {
	return !LMTPlayground__count_has_changed(countDelta);
}

//static inline int LMTPlayground__is_null(void* ptr) {
//	return !LMTPlayground__is_not_null(ptr);
//}
//
//static inline int LMTPlayground__is_not_null(void* ptr) {
//	// ptr != NULL    <=>    ptr
//	return ptr;
//}

static inline int LMTPlayground__chunk(int count) {
	return (count - 1) / ALLOC_INTERVAL + 1;
}

static void LMTPlayground__realloc(LMTPlayground** ppLMTPlayground, int countDelta) {
	LMTPlayground* pLMTPlayground = *ppLMTPlayground;

	if (LMTPlayground__count_has_not_changed(countDelta)) return;
	if (ppLMTPlayground == NULL) return;
	if (pLMTPlayground == NULL) return;

	int afterCount = pLMTPlayground->count + countDelta;
	int afterChunk = LMTPlayground__chunk(afterCount);

	if (LMTPlayground__have_another_reference(pLMTPlayground)) {
		--pLMTPlayground->referenceCount;
		Data* data = (Data*)malloc(afterCount);
		*ppLMTPlayground = newLMTPlayground__designated(data, afterCount, afterChunk); // change

		return;
	}

	pLMTPlayground->count = min(pLMTPlayground->count, afterCount);

	if (pLMTPlayground->chunk != afterChunk) {
		pLMTPlayground->chunk = afterChunk;
		pLMTPlayground->pData = (Data*)realloc(pLMTPlayground->pData, ALLOC_INTERVAL * afterChunk);
	}
}



int LMTPlayground__getCount(LMTPlayground* pLMTPlayground) {
	return pLMTPlayground->count;
}



void LMTPlayground__append__character(LMTPlayground** ppLMTPlayground, char character) {
	LMTPlayground* pLMTPlayground = *ppLMTPlayground;

	if (ppLMTPlayground == NULL) return;
	if (pLMTPlayground == NULL) return;

	LMTPlayground__realloc(ppLMTPlayground, 1);

	pLMTPlayground->pData[pLMTPlayground->count] = (Data)character;

	++pLMTPlayground->count;
}

void LMTPlayground__append__string(LMTPlayground** ppLMTPlayground, char* string) {
	LMTPlayground* pLMTPlayground = *ppLMTPlayground;

	if (ppLMTPlayground == NULL) return;
	if (pLMTPlayground == NULL) return;

	int count = strlen(string) + 1;

	LMTPlayground__realloc(ppLMTPlayground, count);

	strcpy(pLMTPlayground->pData + pLMTPlayground->count, string);

	pLMTPlayground->count += count;
}

void LMTPlayground__append__LMTPlayground(LMTPlayground** ppLHS, LMTPlayground* pRHS) {
	LMTPlayground* pLHS = *ppLHS;

	if (ppLHS == NULL) return;
	if (pLHS == NULL) return;

	LMTPlayground__realloc(ppLHS, pRHS->count);

	memcpy(pLHS->pData + pLHS->count, pRHS->pData, pRHS->count);

	pLHS->count += pRHS->count;
}



int LMTPlayground__removeLast(LMTPlayground** ppLMTPlayground) {
	LMTPlayground* pLMTPlayground = *ppLMTPlayground;

	if (ppLMTPlayground == NULL) return -1;
	if (pLMTPlayground == NULL) return -1;

	Data data = pLMTPlayground->pData[pLMTPlayground->count - 1];

	LMTPlayground__realloc(ppLMTPlayground, -1);

	return data;
}

void LMTPlayground__removeAll(LMTPlayground** ppLMTPlayground) {
	LMTPlayground* pLMTPlayground = *ppLMTPlayground;

	if (ppLMTPlayground == NULL) return;
	if (pLMTPlayground == NULL) return;

	delLMTPlayground(ppLMTPlayground);

	*ppLMTPlayground = newLMTPlayground();
}



int LMTPlayground__firstIndex(LMTPlayground* pLMTPlayground, Data data) {
	if (pLMTPlayground == NULL) return;

	int count = pLMTPlayground->count;

	for (int i = 0; i < count; ++i)
		if (pLMTPlayground->pData[i] == data)
			return i;

	return count;
}



int LMTPlayground__descript(LMTPlayground* pLMTPlayground) {
	printf("[count: %d, chunk: %d reference count: %d] \n", pLMTPlayground->count, pLMTPlayground->chunk, pLMTPlayground->referenceCount);

	for (int i = 0; i < pLMTPlayground->count; ++i)
		printf("%d ", pLMTPlayground->pData[i]);

	putchar('\n');
}





// 5. factory function
static inline LMTPlayground* allocLMTPlayground() {
	return (LMTPlayground*)malloc(sizeof(LMTPlayground));
}

static LMTPlayground* newLMTPlayground__designated(const Data* pData, int count, int chunk) {
	// pData == NULL && count != 0		<=>		!pData && count
	if (!pData && count) return NULL;

	if (pData == NULL && pEmptyLMTPlayground) {
		++pEmptyLMTPlayground->referenceCount;
		return pEmptyLMTPlayground;
	}

	LMTPlayground* pLMTPlayground = allocLMTPlayground();

	pLMTPlayground->count = count;
	pLMTPlayground->chunk = chunk;

	pLMTPlayground->pData = (Data*)malloc(ALLOC_INTERVAL * chunk);
	if (pData) memcpy(pLMTPlayground->pData, pData, count);
	else pEmptyLMTPlayground = pLMTPlayground;

	pLMTPlayground->referenceCount = 0;

	return pLMTPlayground;
}

static inline LMTPlayground* newLMTPlayground__Data(const Data* pData, int count) {
	return newLMTPlayground__designated(pData, count, LMTPlayground__chunk(count));
}

inline LMTPlayground* newLMTPlayground() {
	return newLMTPlayground__designated(NULL, 0, 1);
}

LMTPlayground* newLMTPlayground__string(const char* string) {
	if (string == NULL) return newLMTPlayground();
	else return newLMTPlayground__Data((const Data*)string, strlen(string) + 1);
}

LMTPlayground* newLMTPlayground__LMTPlayground(LMTPlayground* pLMTPlayground) {
	if (pLMTPlayground == NULL) return NULL;

	++pLMTPlayground->referenceCount;

	return pLMTPlayground;
}



void delLMTPlayground(LMTPlayground** ppLMTPlayground) {
	LMTPlayground* pLMTPlayground = *ppLMTPlayground;

	if (ppLMTPlayground == NULL) return;
	if (pLMTPlayground == NULL) return;

	if (LMTPlayground__have_another_reference(pLMTPlayground))
		--pLMTPlayground->referenceCount;
	else {
		if (pLMTPlayground == pEmptyLMTPlayground) pEmptyLMTPlayground == NULL;
		free(pLMTPlayground->pData);
		free(pLMTPlayground);
	}
}





// 6. deprecated
//LMTPlayground* newLMTPlayground__LMTPlayground__count(LMTPlayground* pLMTPlayground, int count) {
//	int chunk = LMTPlayground__chunk(count);
//
//	pLMTPlayground = newLMTPlayground__designated(pLMTPlayground->pData, min(pLMTPlayground->count, count), chunk);
//
//	return pLMTPlayground;
//}

// not accepted in this structure!
//LMTPlayground* copyLMTPlayground__LMTPlayground(LMTPlayground* pRHS) {
//	LMTPlayground* pLMTPlayground = allocLMTPlayground();
//
//	pLMTPlayground->count = pRHS->count;
//	pLMTPlayground->chunk = pRHS->chunk;
//	pLMTPlayground->pData = pRHS->pData;
//
//	pLMTPlayground->referenceCount = 0;
//
//	return pLMTPlayground;
//}

//static void LMTPlayground__reallocIfNeed(LMTPlayground** ppLMTPlayground, int countDelta) {
//	LMTPlayground* pLMTPlayground = *ppLMTPlayground;
//
//	int afterChunk = LMTPlayground__chunk(pLMTPlayground->count + countDelta);
//
//	if (pLMTPlayground->chunk == afterChunk) return;
//
//	pLMTPlayground->pData = (Data*)realloc(pLMTPlayground->pData, ALLOC_INTERVAL * afterChunk);
//	pLMTPlayground->count += countDelta;
//	pLMTPlayground->chunk = afterChunk;
//}
//
//void LMTPlayground__append__hex__fromCharacter(LMTPlayground* pLMTPlayground, char character) {
//	Data hexArray[2];
//
//	Data hex = (Data)character >> 4;
//	hexArray[0] = hex + (hex < 10 ? '0' : 'A' - 10);
//
//	hex = (Data)character & 0x0F;
//	hexArray[1] = hex + (hex < 10 ? '0' : 'A' - 10);
//
//	LMTPlayground__append__data(pLMTPlayground, hexArray, 2);
//}
//
//void LMTPlayground__append__visibleCharacter__fromCharacter(LMTPlayground* pLMTPlayground, char character) {
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
//		LMTPlayground__append__Character(pLMTPlayground, '.');
//	} else {
//		LMTPlayground__append__Character(pLMTPlayground, character);
//	}
//}

//LMTPlayground* cloneLMTPlayground__LMTPlayground(LMTPlayground* pRHS) {
//	LMTPlayground* pLMTPlayground = allocLMTPlayground();
//
//	pLMTPlayground->count = pRHS->count;
//	pLMTPlayground->chunk = pRHS->chunk;
//
//	pLMTPlayground->pData = (Data*)malloc(ALLOC_INTERVAL * pRHS->chunk);
//	memcpy(pLMTPlayground->pData, pRHS->pData, pRHS->count);
//
//	pLMTPlayground->referenceCount = 0;
//
//	return pLMTPlayground;
//}

//void LMTPlayground__append__Data(LMTPlayground** ppLMTPlayground, Data* data, int count) {
//	LMTPlayground__prepareMutating(ppLMTPlayground, count);
//	LMTPlayground* pLMTPlayground = *ppLMTPlayground;
//
//	memcpy(pLMTPlayground->pData + pLMTPlayground->count, data, count);
//
//	pLMTPlayground->count += count;
//}