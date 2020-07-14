#pragma once
//********************************************
// char* title = "LMTString.h"
// made by Lieman at 2020.07.14
//
// description:
//	LMTString interface
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// strcpy(), strlen(), strcat()
#include <assert.h>		// assert()
#pragma warning(disable:4996) //strcpy()





// structure
typedef struct LMTString {
	int count;
	int chunk;
	char* string;

	int referenceCount;
} LMTString;





// method
void LMTString__reallocIfNeed(LMTString* lmtString, int countDelta);
void LMTString__append__Character(LMTString* lmtString, char character);
void LMTString__append__data(LMTString* lmtString, char* data, int count);
void LMTString__append__LMTString(LMTString* lhs, LMTString* rhs);
void LMTString__append__hex__fromCharacter(LMTString* lmtString, char character);
void LMTString__append__visibleCharacter__fromCharacter(LMTString* lmtString, char character);
char LMTStringg__removeLast(LMTString* lmtString);
void LMTStringg__removeAll(LMTString* lmtString);





// LMTString factory method
LMTString* newLMTString();
LMTString* newLMTString__String(char* string);

void deallocLMTString(LMTString* lmtString);
