#pragma once
//********************************************
// char* title = "LMTString.h"
// made by Lieman
//
// description:
//	LMTString interface
//********************************************





// preprocessor
#include "LMTData.h"





// structure
typedef struct LMTString {
	int count;
	LMTData* data;

	int referenceCount;
} LMTString;





// method
//void LMTString__reallocIfNeed(LMTString* lmtString, int countDelta);
//void LMTString__append__Character(LMTString* lmtString, char character);
//void LMTString__append__data(LMTString* lmtString, char* data, int count);
//void LMTString__append__LMTString(LMTString* lhs, LMTString* rhs);
//void LMTString__append__hex__fromCharacter(LMTString* lmtString, char character);
//void LMTString__append__visibleCharacter__fromCharacter(LMTString* lmtString, char character);
//char LMTStringg__removeLast(LMTString* lmtString);
//void LMTStringg__removeAll(LMTString* lmtString);





// LMTString factory method
LMTString* newLMTString();
LMTString* newLMTString__String(char* string);
LMTString* newLMTString__data(LMTData* pData);
LMTString* newLMTString__LMTString(LMTString* pLMTString);

void delLMTString(LMTString** ppLMTString);