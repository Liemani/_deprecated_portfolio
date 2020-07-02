#pragma once
//********************************************
// char* title = "Swap"
// made by Lieman at 2020.07.02
//
// description:
//	Swap
//********************************************





// preprocessor
#include <stdlib.h>
#include <string.h>





void swap_generic(void *plhs, void *prhs, size_t size) {
	void *tmp = malloc(size);

	memcpy(tmp, plhs, size);
	memcpy(plhs, prhs, size);
	memcpy(prhs, tmp, size);

	free(tmp);
}