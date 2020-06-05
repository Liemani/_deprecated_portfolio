#pragma once
//********************************************
// char* title = "swap"
// made by Lieman at 2020.06.05
//
// description:
//	swap example
//********************************************





// preprocessor
#include <stdio.h>





void swap(void* lhs, void* rhs, size_t sizeOfElement) {
	unsigned char* uChLHS = (unsigned char*)lhs;
	unsigned char* uChRHS = (unsigned char*)rhs;

	unsigned char temp;
	for (size_t i = 0; i < sizeOfElement; ++i) {
		temp = uChLHS[i];
		uChLHS[i] = uChRHS[i];
		uChRHS[i] = temp;
	}
}