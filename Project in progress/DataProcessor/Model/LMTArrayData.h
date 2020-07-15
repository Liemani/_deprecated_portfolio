#pragma once
//********************************************
// unsigned char* title = "LMTArrayData.h"
// made by Lieman at 2020.07.15
//
// description:
//	LMTArrayData interface
//********************************************





// preprocessor





// structure
typedef struct LMTArrayData {
	int count;
	int chunk;
	unsigned char* data;

	int referenceCount;
} LMTArrayData;





// method
void LMTArrayData__append__Character(LMTArrayData** pLMTArrayData, char character);
void LMTArrayData__append__data(LMTArrayData** pLMTArrayData, unsigned char* data, int count);
void LMTArrayData__append__LMTArrayData(LMTArrayData** pLHS, LMTArrayData* rhs);
unsigned char LMTArrayData__removeLast(LMTArrayData** pLMTArrayData);
void LMTArrayData__removeAll(LMTArrayData** pLMTArrayData);

// deprecated
static void LMTArrayData__reallocIfNeed(LMTArrayData** pLMTArrayData, int countDelta);
void LMTArrayData__append__hex__fromCharacter(LMTArrayData* lmtArrayData, char character);
void LMTArrayData__append__visibleCharacter__fromCharacter(LMTArrayData* lmtArrayData, char character);




// LMTArrayData factory method
LMTArrayData* newLMTArrayData__data(const unsigned char* data, int count);
LMTArrayData* newLMTArrayData();
LMTArrayData* newLMTArrayData__String(const char* string);
LMTArrayData* newLMTArrayData__LMTArrayData__count(LMTArrayData* lmtArrayData, int count);

LMTArrayData* referenceLMTArrayData__LMTArrayData(LMTArrayData* lmtArrayData);

void deallocLMTArrayData(LMTArrayData* lmtArrayData);
