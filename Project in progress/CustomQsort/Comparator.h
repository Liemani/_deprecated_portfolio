#pragma once
//********************************************
// char* title = "Comparator"
// made by Lieman at 2020.07.03
//
// description:
//	Comparator
//********************************************





int isEqualTo_byte(void* plhs, void* prhs, int sizeOfElement) {
	unsigned char *lhs = (unsigned char*)plhs;
	unsigned char *rhs = (unsigned char*)prhs;

	int result = 0;

	for (int i = 0; i < sizeOfElement; ++i) {
		result |= lhs[i] ^ rhs[i];
	}

	return !result;
}