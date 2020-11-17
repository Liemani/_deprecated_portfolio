#pragma once
//********************************************
// char* title = "Average"
// made by Lieman at 2020.06.29
//
// description:
//	Average
//********************************************





// preprocessor
#include <stdio.h>

#include "Add.h"





/// <summary>
/// <para>assume lhs, rhs as unsigned integral</para>
/// <para></para>
/// <para></para>
/// <para></para>
/// <para></para>
/// </summary>
void averageData(void* lhs, void* rhs, void* result, size_t sizeOfElement) {
	unsigned char carry = addDataInLittleEndianess(lhs, rhs, result, sizeOfElement);

	unsigned char* resultByte = (unsigned char*)result;

	resultByte[0] >>= 1;

	for (int i = 1; i < sizeOfElement; ++i) {
		resultByte[i - 1] |= resultByte[i] << 7;
		resultByte[i] >> 1;
	}

	resultByte[sizeOfElement - 1] |= carry << 7;
}