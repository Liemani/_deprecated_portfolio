#pragma once
//********************************************
// unsigned char* title = "DataArray.h"
// made by Lieman at 2020.07.10
//
// description:
//	DataArray interface
//********************************************





// preprocessor





// structure
typedef struct DataArray {
	int maxIndex;
	int chunk;
	unsigned char* dataArray;
} DataArray;





// static variable
static const int ALLOC_INTERVAL;





// method
int DataArray__reallocIfNeed(DataArray* dataArray, int countDelta);

void DataArray__append__Character(DataArray* dataArray, unsigned char character);
void DataArray__append__String(DataArray* dataArray, unsigned char* data);
void DataArray__append__DataArray(DataArray* lhs, DataArray* rhs);
void DataArray__append__hex__fromCharacter(DataArray* dataArray, unsigned char character);
void DataArray__append__data__fromCharacter(DataArray* dataArray, unsigned char character);

unsigned char DataArrayg__removeLast(DataArray* dataArray);
void DataArrayg__removeAll(DataArray* dataArray);

void DataArray__uppercase(DataArray* dataArray);
void DataArray__lowercase(DataArray* dataArray);





// DataArray factory method
DataArray* allocDataArray();

DataArray* newDataArray__designated(unsigned char* dataArray, int count);

DataArray* newDataArray();

DataArray* newDataArray__String(unsigned char* dataArray);
DataArray* newDataArray__DataArray(DataArray* dataArray);

unsigned char DataArrayg__removeLast(DataArray* dataArray);

void deallocDataArray__memberwise(DataArray* dataArray);
void deallocDataArray__designated(DataArray* dataArray);
