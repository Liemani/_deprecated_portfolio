#pragma once
//********************************************
// char* title = "swap"
// made by Lieman at 2020.06.04
//
// description:
//	swap example
//********************************************





// preprocessor
#include <stdio.h>





void swap(void* lhs, void* rhs, int sizeOfElement) {
	unsigned char* uChLHS = (unsigned char*)lhs;
	unsigned char* uChRHS = (unsigned char*)rhs;

	unsigned char temp;
	for (int i = 0; i < sizeOfElement; ++i) {
		temp = uChLHS[i];
		uChLHS[i] = uChRHS[i];
		uChRHS[i] = temp;
	}
}