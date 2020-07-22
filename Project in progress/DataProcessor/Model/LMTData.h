#pragma once
//********************************************
// char* title = "LMTData.h"
// made by Lieman
//
// description:
//	LMTData interface
//********************************************





// preprocessor





typedef unsigned char Data;

// structure
// 1 LMTData must match with 1 pData
// if there is 2 different LMTData have same pData,
// when one of them deleted, pData must delted,
// and the other's pData get NULL!
typedef struct LMTData {
	int count;
	int chunk;
	Data* pData;

	int referenceCount;
} LMTData;





// method
void LMTData__append__character(LMTData** ppLMTData, char character);
void LMTData__append__LMTData(LMTData** ppLHS, LMTData* pRHS);
Data LMTData__removeLast(LMTData** ppLMTData);
void LMTData__removeAll(LMTData** ppLMTData);
int LMTData__firstIndex(LMTData* pLMTData, Data uCharacter);





// LMTData factory method
LMTData* newLMTData__designated(const Data* pData, int count, int chunk);
LMTData* newLMTData__Data(const Data* pData, int count);
LMTData* newLMTData();
LMTData* newLMTData__string(const char* string);
LMTData* newLMTData__LMTData(LMTData* pLMTData);

void delLMTData(LMTData* pLMTData);
