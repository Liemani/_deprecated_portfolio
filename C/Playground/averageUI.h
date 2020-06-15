#pragma once
//********************************************
// char* title = "average"
// made by Lieman at 2020.06.05
//
// description:
//	average example
//********************************************





// preprocessor
#include <stdio.h>

#include "add_Byte.h"





/// <summary>
/// <para>assume lhs, rhs as unsigned integral</para>
/// <para></para>
/// <para></para>
/// <para></para>
/// <para></para>
/// </summary>
void averageUI(void* lhs, void* rhs, void* result, size_t sizeOfElement) {
	int carry = 0;

	unsigned char* plhs = (unsigned char*)lhs;
	unsigned char* prhs = (unsigned char*)rhs;
	unsigned char* presult = (unsigned char*)result;

	for (int i = 0; i < sizeOfElement; ++i) {
		carry = add_Byte(plhs[i], prhs[i], (unsigned char)carry, &presult[i]);
	}
}