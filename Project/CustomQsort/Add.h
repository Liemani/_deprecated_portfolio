#pragma once
//********************************************
// char* title = "Add"
// made by Lieman at 2020.06.29
//
// description:
//	Add
//********************************************





// preprocessor
#include <stdio.h>





unsigned char addByteInLittleEndianess(
	unsigned char lhs,
	unsigned char rhs,
	unsigned char carry,
	unsigned char* result) {

	unsigned short sum = (unsigned short)lhs + (unsigned short)rhs + (unsigned short)carry;
	*result = (unsigned char)sum;

	return (unsigned char)(sum >> 8);
}

unsigned char addDataInLittleEndianess(
	void* lhs,
	void* rhs,
	void* result,
	size_t sizeOfElement) {

	unsigned char carry = 0;

	unsigned char* lhsByte = (unsigned char*)lhs;
	unsigned char* rhsByte = (unsigned char*)rhs;
	unsigned char* resultByte = (unsigned char*)result;

	for (int i = 0; i < sizeOfElement; ++i) {
		carry = addByteInLittleEndianess(lhsByte[i], rhsByte[i], (unsigned char)carry, &resultByte[i]);
	}

	return carry;
}