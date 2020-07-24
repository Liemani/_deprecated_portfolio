#pragma once
//********************************************
// char* title = "LMTString.c"
// made by Lieman
//
// description:
//	LMTString implementation
//********************************************





// preprocessor
#include <stdlib.h>    // malloc(), realloc(), free()
#include <string.h>    // strcpy(), strlen(), strcat()
#include <assert.h>    // assert()
#pragma warning(disable:4996)    //strcpy()
#include "LMTString.h"
#include "LMTData.h"





// static variable
static const int ALLOC_INTERVAL = sizeof(int);
static LMTString* pEmpltyLMTString = NULL;





// static method
static int LMTString__have_another_reference(const LMTString* pLMTString) {
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
//	LMTString* lmtString = *ppLMTString;
//
//	--lmtString->referenceCount;
//	*ppLMTString = newLMTString__data(lmtString->data);
//
//
//
//
//	--lmtString->referenceCount;
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





// method
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

//void LMTString__append__String(LMTString* lmtString, char* string) {
//	if (string == NULL) return;
//
//	const int count = strlen(string);
//
//	LMTString__reallocIfNeed(lmtString, count);
//
//	strcpy(lmtString->string, string);
//
//	lmtString->count += count;
//}

//void LMTString__append__LMTString(LMTString* lhs, LMTString* rhs) {
//	LMTString__reallocIfNeed(lhs, rhs->count);
//
//	strcpy(lhs->string, rhs->string);
//
//	lhs->count += rhs->count;
//}

//void LMTString__append__visibleCharacter__fromCharacter(LMTString* lmtString, char character) {
//	if (
//		character <= 0 ||
//		(7 <= character &&
//		character <= 10) ||
//		character == 13 ||
//		character == 27 ||
//		character == 32 ||
//		127 <= character) {
//
//		LMTString__append__Character(lmtString, '.');
//	} else {
//		LMTString__append__Character(lmtString, character);
//	}
//}

//char LMTStringg__removeLast(LMTString* lmtString) {
//	char uCharacter = lmtString->string[lmtString->count - 1];
//
//	LMTString__reallocIfNeed(lmtString, -1);
//
//	--lmtString->count;
//
//	return uCharacter;
//}

//void LMTStringg__removeAll(LMTString* lmtString) {
//	lmtString->count = 0;
//	lmtString->chunk = 1;
//
//	free(lmtString->string);
//	lmtString->string = (char*)malloc(ALLOC_INTERVAL * lmtString->chunk);
//}





// LMTString factory method
static inline LMTString* allocLMTString() {
	return (LMTString*)malloc(sizeof(LMTString));
}

//static LMTString* newLMTString__designated(LMTData* pData) {    // add count parameter
//	if (pData == NULL && pEmpltyLMTString) {
//		++pEmpltyLMTString->referenceCount;
//		return pEmpltyLMTString;
//	}
//
//	LMTString* lmtString = allocLMTString();
//
//	//lmtString->count = count;
//
//	lmtString->data = referenceLMTData__LMTData(pData);
//
//	lmtString->referenceCount = 0;
//
//	return lmtString;
//}
//
//LMTString* newLMTString() {
//	LMTData* data = newLMTData__String("");
//
//	return newLMTString__designated(data);
//}
//
//LMTString* newLMTString__String(char* string) {
//	if (string == NULL) return newLMTString();
//
//	LMTData* data = newLMTData__String(string);
//
//	return newLMTString__designated(data);
//}
//
//LMTString* newLMTString__data(LMTData* pData) {
//	LMTData* stringData = newLMTData__LMTData(pData);
//
//	return newLMTString__designated(stringData);
//}
//
//LMTString* newLMTString__LMTString(LMTString* pLMTString) {
//	if (pLMTString == NULL) return newLMTString();
//
//	++pLMTString->referenceCount;
//
//	return pLMTString;
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
//
//void delLMTString(LMTString** ppLMTString) {
//	LMTString* pLMTString = *ppLMTString;
//
//	if (pLMTString == NULL) return;
//
//	if (LMTString__have_another_reference(pLMTString))
//		--pLMTString->referenceCount;
//	else {
//		deallocLMTData(pLMTString->data);
//		free(pLMTString);
//	}
//
//	*ppLMTString = NULL;
//}
