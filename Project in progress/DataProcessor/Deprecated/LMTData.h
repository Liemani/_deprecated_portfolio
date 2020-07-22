#pragma once
//********************************************
// unsigned char* title = "LMTData.h"
// made by Lieman at 2020.07.13
//
// description:
//	LMTData interface
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// strcpy(), strlen(), strcat()
#include <assert.h>		// assert()
#pragma warning(disable:4996) //strcpy()





// structure
typedef struct LMTData {
	int count;
	int chunk;
	unsigned char* data;
} LMTData;





// method
void LMTData__reallocIfNeed(LMTData* lmtData, int countDelta);
void LMTData__append__Character(LMTData* lmtData, char character);
void LMTData__append__data(LMTData* lmtData, unsigned char* data, int count);
void LMTData__append__LMTData(LMTData* lhs, LMTData* rhs);
void LMTData__append__hex__fromCharacter(LMTData* lmtData, char character);
void LMTData__append__visibleCharacter__fromCharacter(LMTData* lmtData, char character);
unsigned char LMTDatag__removeLast(LMTData* lmtData);
void LMTDatag__removeAll(LMTData* lmtData);





// LMTData factory method
LMTData* newLMTData__data(unsigned char* data, int count);
LMTData* newLMTData();
LMTData* newLMTData__String(char* string);
LMTData* newLMTData__LMTData(LMTData* lmtData);

void deallocLMTData(LMTData* lmtData);
