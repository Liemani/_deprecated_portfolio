#pragma once
//********************************************
// char* title = "LMTData.h"
// made by Lieman
//
// description:
//	LMTData interface
//********************************************





// preprocessor





// type define
typedef unsigned char Data;

typedef struct LMTData LMTData;




// function
int LMTData__getCount(LMTData* pLMTData);

static int LMTData__have_another_reference(const LMTData* pLMTData);
static int LMTData__dont_have_another_reference(const LMTData* pLMTData);

static int LMTData__count_has_changed(int countDelta);
static int LMTData__count_has_not_changed(int countDelta);

static int LMTData__chunk(int count);



void LMTData__append__character(LMTData** ppLMTData, char character);
void LMTData__append__string(LMTData** ppLMTData, char* string);
void LMTData__append__LMTData(LMTData** ppLHS, LMTData* pRHS);

int LMTData__removeLast(LMTData** ppLMTData);
void LMTData__removeAll(LMTData** ppLMTData);

int LMTData__firstIndex(LMTData* pLMTData, Data uCharacter);

int LMTData__descript(LMTData* pLMTData);





// factory method
static LMTData* allocLMTData();
static void reallocLMTData(LMTData** ppLMTData, int countDelta);

static LMTData* newLMTData__designated(const Data* pData, int count, int chunk);
static LMTData* newLMTData__Data(const Data* pData, int count);

LMTData* newLMTData();
LMTData* newLMTData__string(const char* string);

LMTData* referenceLMTData(LMTData* pLMTData);

void delLMTData(LMTData** pLMTData);
