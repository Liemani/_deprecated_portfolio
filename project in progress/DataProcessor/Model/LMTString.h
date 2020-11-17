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
typedef struct LMTString LMTString;





// method
//void LMTString__reallocIfNeed(LMTString* pLMTString, int countDelta);
//void LMTString__append__Character(LMTString* pLMTString, char character);
//void LMTString__append__data(LMTString* pLMTString, char* data, int count);
//void LMTString__append__LMTString(LMTString* lhs, LMTString* rhs);
//void LMTString__append__hex__fromCharacter(LMTString* pLMTString, char character);
//void LMTString__append__visibleCharacter__fromCharacter(LMTString* pLMTString, char character);
//char LMTStringg__removeLast(LMTString* pLMTString);
//void LMTStringg__removeAll(LMTString* pLMTString);





// LMTString factory method
LMTString* newLMTString();
LMTString* newLMTString__string(char* string);
LMTString* newLMTString__LMTString(LMTString* pLMTString);

void delLMTString(LMTString** ppLMTString);