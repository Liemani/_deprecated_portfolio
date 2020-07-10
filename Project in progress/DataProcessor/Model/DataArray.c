#pragma once
//********************************************
// unsigned char* title = "DataArray.c"
// made by Lieman at 2020.07.10
//
// description:
//	DataArray implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc(), realloc(), free()
#include <string.h>		// strcpy(), strlen(), strcat()
#include <assert.h>		// assert()
#include "DataArray.h"
#pragma warning(disable:4996) //strcpy()





// static variable
static const int ALLOC_INTERVAL = sizeof(int);





// method
int DataArray__reallocIfNeed(DataArray* dataArray, int countDelta) {
	int afterChunk = (dataArray->count + 1 + countDelta) / ALLOC_INTERVAL + 1;

	if (dataArray->chunk != afterChunk) {
		dataArray->dataArray = (unsigned char*)realloc(dataArray->dataArray, ALLOC_INTERVAL * afterChunk);
		assert(dataArray->dataArray);
		dataArray->chunk = afterChunk;
	}
}

void DataArray__append__Character(DataArray* dataArray, unsigned char character) {
	DataArray__reallocIfNeed(dataArray, 1);
	dataArray->dataArray[dataArray->count] = character;
	dataArray->dataArray[dataArray->count + 1] = '\0';

	++dataArray->count;
}

//void DataArray__append__String(DataArray* dataArray, unsigned char* dataA) {
//	int dataArrayCount = strlen(dataArray);
//
//	DataArray__reallocIfNeed(dataArray, dataArrayCount);
//	strcat(dataArray->dataArray, dataArray);
//
//	dataArray->count += dataArrayCount;
//}

void DataArray__append__DataArray(DataArray* lhs, DataArray* rhs) {
	DataArray__reallocIfNeed(lhs, rhs->count);
	strcat(lhs->dataArray, rhs->dataArray);

	lhs->count += rhs->count;
}

void DataArray__append__hex__fromCharacter(DataArray* dataArray, unsigned char character) {
	unsigned char hexArray[3];

	unsigned char hex = character >> 4;
	hexArray[0] = hex + (hex < 10 ? '0' : 'A' - 10);

	hex = character & 0x0F;
	hexArray[1] = hex + (hex < 10 ? '0' : 'A' - 10);

	hexArray[2] = '\0';

	DataArray__append__String(dataArray, hexArray);
}

void DataArray__append__data__fromCharacter(DataArray* dataArray, unsigned char character) {
	if (
		character <= 0 ||
		character == 7 ||
		character == 8 ||
		character == 9 ||
		character == 10 ||
		character == 13 ||
		character == 27 ||
		character == 32 ||
		127 <= character) {
		DataArray__append__Character(dataArray, '.');
	} else {
		DataArray__append__Character(dataArray, character);
	}
}

unsigned char DataArrayg__removeLast(DataArray* dataArray) {
	unsigned char character = dataArray->dataArray[dataArray->count - 1];
	DataArray__reallocIfNeed(dataArray, -1);
	dataArray->dataArray[dataArray->count - 1] = '\0';

	return character;
}

void DataArrayg__removeAll(DataArray* dataArray) {
	dataArray->count = 0;
	dataArray->chunk = 1;

	free(dataArray->dataArray);
	dataArray->dataArray = (unsigned char*)malloc(ALLOC_INTERVAL * dataArray->chunk);
	assert(dataArray->dataArray);

	dataArray->dataArray[0] = '\0';
}

void DataArrayg__uppercase(DataArray* dataArray) {
	unsigned char character;

	for (int i = 0; i < dataArray->count; ++i) {
		character = dataArray->dataArray[i];

		if ('a' <= character && character <= 'z') {
			character += -'a' + 'A';
			dataArray->dataArray[i] = character;
		}
	}
}

void DataArray__lowercase(DataArray* dataArray) {
	unsigned char character;

	for (int i = 0; i < dataArray->count; ++i) {
		character = dataArray->dataArray[i];

		if ('A' <= character && character <= 'Z') {
			character += -'A' + 'a';
			dataArray->dataArray[i] = character;
		}
	}
}





// DataArray factory method
DataArray* allocDataArray() {
	DataArray* dataArray = (DataArray*)malloc(sizeof(DataArray));

	return dataArray;
}

DataArray* newDataArray__designated(unsigned char* data, int maxIndex) {
	DataArray* dataArray = allocDataArray();

	dataArray->maxIndex = maxIndex;
	dataArray->chunk = (maxIndex + 1) / ALLOC_INTERVAL + 1;

	dataArray->dataArray = (unsigned char*)malloc(ALLOC_INTERVAL * dataArray->chunk);
	assert(dataArray->dataArray);

	if (dataArray)
		strcpy(dataArray->dataArray, data);
	else
		dataArray->dataArray[0] = '\0';

	return dataArray;
}

DataArray* newDataArray() {
	return newDataArray__designated(NULL, 0);
}

DataArray* newDataArray__String(unsigned char* dataArray) {
	if (dataArray == NULL) return newDataArray();

	return newDataArray__designated(dataArray, strlen(dataArray));
}

DataArray* newDataArray__DataArray(DataArray* dataArray) {
	return newDataArray__designated(dataArray->dataArray, dataArray->count);
}

void deallocDataArray__memberwise(DataArray* dataArray) {
	free(dataArray);
}

void deallocDataArray__designated(DataArray* dataArray) {
	free(dataArray->dataArray);
	free(dataArray);
}
