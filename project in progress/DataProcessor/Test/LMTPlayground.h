#pragma once
//********************************************
// char* title = "LMTPlayground.h"
// made by Lieman
//
// description:
//	LMTPlayground interface
//********************************************





// preprocessor





// type define
typedef unsigned char Data;

typedef struct LMTPlayground LMTPlayground;




// function
static int LMTPlayground__have_another_reference(const LMTPlayground* pLMTPlayground);
static int LMTPlayground__dont_have_another_reference(const LMTPlayground* pLMTPlayground);

static int LMTPlayground__count_has_changed(int countDelta);
static int LMTPlayground__count_has_not_changed(int countDelta);

static int LMTPlayground__chunk(int count);

static void LMTPlayground__realloc(LMTPlayground** ppLMTPlayground, int countDelta);



int LMTPlayground__getCount(LMTPlayground* pLMTPlayground);

void LMTPlayground__append__character(LMTPlayground** ppLMTPlayground, char character);
void LMTPlayground__append__string(LMTPlayground** ppLMTPlayground, char* string);
void LMTPlayground__append__LMTPlayground(LMTPlayground** ppLHS, LMTPlayground* pRHS);

int LMTPlayground__removeLast(LMTPlayground** ppLMTPlayground);
void LMTPlayground__removeAll(LMTPlayground** ppLMTPlayground);

int LMTPlayground__firstIndex(LMTPlayground* pLMTPlayground, Data uCharacter);

int LMTPlayground__descript(LMTPlayground* pLMTPlayground);





// factory method
static LMTPlayground* allocLMTPlayground();
static LMTPlayground* newLMTPlayground__designated(const Data* pData, int count, int chunk);
static LMTPlayground* newLMTPlayground__Data(const Data* pData, int count);

LMTPlayground* newLMTPlayground();
LMTPlayground* newLMTPlayground__string(const char* string);
LMTPlayground* newLMTPlayground__LMTPlayground(LMTPlayground* pLMTPlayground);

void delLMTPlayground(LMTPlayground** pLMTPlayground);
