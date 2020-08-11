//********************************************
// char* title = "LMTString.c"
// made by Lieman
//
// description:
//	LMTString implementation
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
#include <stdlib.h>    // malloc(), realloc(), free()
#include <string.h>    // strcpy(), strlen(), strcat()
#include <assert.h>    // assert()

#pragma warning(disable:4996)    //strcpy()

#include "LMTString.h"
#include "LMTData.h"





// 2. type define
typedef struct LMTString {
	int count;

	int dataCount;
	int chunk;
	LMTData** ppData;

	int referenceCount;
} LMTString;





// 3. static variable
static const int ALLOC_INTERVAL = sizeof(int);
static LMTString* pEmptyLMTString;





// 4. function
static inline int LMTString__chunk(int count) {
	return (count - 1) / ALLOC_INTERVAL + 1;
}



static inline int LMTString__have_another_reference(const LMTString* pLMTString) {
	assert(pLMTString);

	//* abstract concept *							* truth table of target *				* result expecting *
	// if string don't have another reference,	pLMTString->referenceCount is false,	and should return false
	// if string have another reference,		pLMTString->referenceCount is true,	and should return true
	return pLMTString->referenceCount;
}

static inline int LMTString__dont_have_another_reference(const LMTString* pLMTString) {
	return !LMTString__have_another_reference(pLMTString);
}

//static void LMTString__makeDataStringIfNeed(LMTString* pLMTString) {
//	LMTData* data = pLMTString->data;
//
//	pLMTString->count = LMTData__firstIndex(data, (unsigned char)'\0');
//
//	if (pLMTString->count == data->count) {
//		LMTData__append__Character(&pLMTString->data, '\0');
//		++pLMTString->count;
//	}
//}

//static void LMTString__prepareMutating(LMTString** ppLMTString) {
//	if (ppLMTString == NULL) return;
//	if (*ppLMTString == NULL) return;
//
//	if (LMTString__dont_have_another_reference(*ppLMTString)) return;
//
//	LMTString* pLMTString = *ppLMTString;
//
//	--pLMTString->referenceCount;
//	*ppLMTString = newLMTString__data(pLMTString->data);
//
//
//
//
//	--pLMTString->referenceCount;
//	*ppLMTString = newLMTString__referenceData;
//
//	LMTData* pLMTData = *pLMTData;
//
//	int afterCount = pLMTData->count + countDelta;
//	int afterChunk = LMTData__chunk(afterCount);
//
//	if (LMTData__have_another_reference(pLMTData)) {
//		--pLMTData->referenceCount;
//		*pLMTData = newLMTData__LMTData__count(pLMTData, afterCount);
//	} else  if (pLMTData->chunk != afterChunk) {
//		pLMTData->count = min(pLMTData->count, afterCount);
//		pLMTData->chunk = afterChunk;
//		pLMTData->pData = (unsigned char*)realloc(pLMTData->pData, ALLOC_INTERVAL * afterChunk);
//	}
//}



//void LMTString__reallocIfNeed(LMTString* pLMTString, int countDelta) {
//	int afterChunk = (pLMTString->count + countDelta) / ALLOC_INTERVAL + 1;
//
//	if (pLMTString->chunk == afterChunk) return;
//
//	pLMTString->string = (char*)realloc(pLMTString->string, ALLOC_INTERVAL * afterChunk);
//	pLMTString->chunk = afterChunk;
//}

//void LMTString__append__Character(LMTString** ppLMTString, char character) {
//	LMTString* pLMTString = *ppLMTString;
//
//	if (LMTString__have_another_reference(pLMTString)) {
//		--pLMTString->referenceCount;
//		*ppLMTString = newLMTString__data(pLMTString->data);
//	} else {
//
//	}
//
//	LMTData__append__Character(&pLMTString->data, '\0');
//
//	LMTString__reallocIfNeed(pLMTString, 1);
//
//	pLMTString->data[pLMTString->count] = character;
//
//	++pLMTString->count;
//
//	pLMTString->data[pLMTString->count] = '\0';
//}

//void LMTString__append__String(LMTString* pLMTString, char* string) {
//	if (string == NULL) return;
//
//	const int count = strlen(string);
//
//	LMTString__reallocIfNeed(pLMTString, count);
//
//	strcpy(pLMTString->string, string);
//
//	pLMTString->count += count;
//}

//void LMTString__append__LMTString(LMTString* lhs, LMTString* rhs) {
//	LMTString__reallocIfNeed(lhs, rhs->count);
//
//	strcpy(lhs->string, rhs->string);
//
//	lhs->count += rhs->count;
//}

//void LMTString__append__visibleCharacter__fromCharacter(LMTString* pLMTString, char character) {
//	if (
//		character <= 0 ||
//		(7 <= character &&
//		character <= 10) ||
//		character == 13 ||
//		character == 27 ||
//		character == 32 ||
//		127 <= character) {
//
//		LMTString__append__Character(pLMTString, '.');
//	} else {
//		LMTString__append__Character(pLMTString, character);
//	}
//}

//char LMTStringg__removeLast(LMTString* pLMTString) {
//	char uCharacter = pLMTString->string[pLMTString->count - 1];
//
//	LMTString__reallocIfNeed(pLMTString, -1);
//
//	--pLMTString->count;
//
//	return uCharacter;
//}

//void LMTStringg__removeAll(LMTString* pLMTString) {
//	pLMTString->count = 0;
//	pLMTString->chunk = 1;
//
//	free(pLMTString->string);
//	pLMTString->string = (char*)malloc(ALLOC_INTERVAL * pLMTString->chunk);
//}





// 5. factory function
static inline LMTString* allocLMTString() {
	return (LMTString*)malloc(sizeof(LMTString));
}

static void reallocLMTString(LMTData** ppLMTString, int countDelta) {
	LMTString* pLMTString = *ppLMTString;

	if (LMTString__count) {

	}
}



static LMTString* newLMTString__designated(LMTData* pLMTData, int count) {
	// (!pData && (count - 1))    <=>    (pData == NULL && count != 1)
	if (!pLMTData && (count - 1)) return NULL;

	if (pLMTData == NULL && pEmptyLMTString) {
		++pEmptyLMTString->referenceCount;
		return pEmptyLMTString;
	}

	LMTString* pLMTString = allocLMTString();

	pLMTString->count = count;
	pLMTString->dataCount = 1;
	pLMTString->chunk = 1;

	pLMTString->ppData = (LMTData**)malloc(sizeof(LMTData**) * ALLOC_INTERVAL);
	if (pLMTData) pLMTString->ppData[0] = pLMTData;
	else {
		pLMTString->ppData[0] = newLMTData__string("");
		pEmptyLMTString = pLMTString;
	}

	pLMTString->referenceCount = 0;

	return pLMTString;
}

inline LMTString* newLMTString() {
	return newLMTString__designated(NULL, 0);
}

LMTString* newLMTString__string(char* string) {
	if (string == NULL) return NULL;

	LMTData* data = newLMTData__string(string);

	return newLMTString__designated(data, LMTData__getCount(data));
}



LMTString* referenceLMTString(LMTString* pLMTString) {
	if (pLMTString == NULL) return NULL;

	++pLMTString->referenceCount;

	return pLMTString;
}



void delLMTString(LMTString** ppLMTString) {
	LMTString* pLMTString = *ppLMTString;

	if (ppLMTString == NULL) return;
	if (pLMTString == NULL) return;

	if (LMTString__have_another_reference(pLMTString))
		--pLMTString->referenceCount;
	else {
		if (pLMTString == pEmptyLMTString) pEmptyLMTString == NULL;

		for (int i = 0; i < pLMTString->dataCount ; ++i)
			delLMTData(pLMTString->ppData[i]);
		
		free(pLMTString->ppData);
		free(pLMTString);
	}

	*ppLMTString = NULL;
}

//LMTString* newLMTString__data(LMTData* pData) {
//	LMTData* stringData = newLMTData__LMTData(pData);
//
//	return newLMTString__designated(stringData);
//}
//
//// make replica of parameter name to (pLHS, rhs)
//void setLMTString__LMTString(LMTString** ppLHS, const LMTString* pRHS) {
//	if (ppLHS == NULL) return;
//
//	LMTString* pLHS = *ppLHS;
//
//	if (pLHS == NULL) {
//		*ppLHS = newLMTString__LMTString(pRHS);
//		return;
//	}
//
//	if (pLHS == pRHS) return;
//
//
//	if (LMTString__have_another_reference(pLHS))
//		--pLHS->referenceCount;
//	else
//		delLMTString(pLHS);
//
//	*ppLHS = newLMTString__LMTString(pRHS);
//}
