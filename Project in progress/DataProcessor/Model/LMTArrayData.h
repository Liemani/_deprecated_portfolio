#pragma once
//********************************************
// unsigned char* title = "LMTArrayData.h"
// made by Lieman at 2020.07.14
//
// description:
//	LMTArrayData interface
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// strcpy(), strlen(), strcat()
#include <assert.h>		// assert()
#pragma warning(disable:4996) //strcpy()





// structure
typedef struct LMTArrayData {
	int count;
	int chunk;
	unsigned char* data;

	int referenceCount;
} LMTArrayData;





// method
void LMTArrayData__append__Character(LMTArrayData* lmtArrayData, char character);
void LMTArrayData__append__data(LMTArrayData* lmtArrayData, unsigned char* data, int count);
void LMTArrayData__append__LMTArrayData(LMTArrayData* lhs, LMTArrayData* rhs);
void LMTArrayData__append__hex__fromCharacter(LMTArrayData* lmtArrayData, char character);
void LMTArrayData__append__visibleCharacter__fromCharacter(LMTArrayData* lmtArrayData, char character);
unsigned char LMTArrayDatag__removeLast(LMTArrayData* lmtArrayData);
void LMTArrayDatag__removeAll(LMTArrayData* lmtArrayData);





// LMTArrayData factory method
LMTArrayData* newLMTArrayData__data(const unsigned char* data, int count);
LMTArrayData* newLMTArrayData();
LMTArrayData* newLMTArrayData__String(const char* string);
LMTArrayData* newLMTArrayData__LMTArrayData(LMTArrayData* lmtArrayData);

void deallocLMTArrayData(LMTArrayData* lmtArrayData);
