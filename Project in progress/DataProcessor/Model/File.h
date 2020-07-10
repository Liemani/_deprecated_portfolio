#pragma once
//********************************************
// char* title = "File.h"
// made by Lieman at 2020.07.10
//
// description:
//	File interface
//********************************************





// preprocessor
#include <stdio.h>		// FILE
#include <stdlib.h>		// malloc()
#include <string.h>		// strlen(), strcpy()
#include "SimpleString.h"





// structure
typedef struct File {
	FILE* file;
} File;





// method





// File factory method
File* allocFile();

File* newFile__designated(char* name);

void deallocFile(File* file);
