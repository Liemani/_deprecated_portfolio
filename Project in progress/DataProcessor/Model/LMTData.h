#pragma once
//********************************************
// char* title = "LMTData.h"
// made by Lieman
//
// description:
//	LMTData interface
//********************************************





// preprocessor





// structure
typedef unsigned char Data;
typedef struct LMTData LMTData;


static struct TestStruct {
	int testInt;
};
// static test



// method
void LMTData__append__character(LMTData** ppLMTData, char character);
void LMTData__append__string(LMTData** ppLMTData, char* string);
void LMTData__append__LMTData(LMTData** ppLHS, LMTData* pRHS);
int LMTData__removeLast(LMTData** ppLMTData);
void LMTData__removeAll(LMTData** ppLMTData);
int LMTData__firstIndex(LMTData* pLMTData, Data uCharacter);





// LMTData factory method
LMTData* newLMTData__designated(const Data* pData, int count, int chunk);
LMTData* newLMTData__Data(const Data* pData, int count);
LMTData* newLMTData();
LMTData* newLMTData__string(const char* string);
LMTData* newLMTData__LMTData(LMTData* pLMTData);

void delLMTData(LMTData* pLMTData);
