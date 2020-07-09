#pragma once
//********************************************
// char* title = "FileManager.h"
// made by Lieman at 2020.07.09
//
// description:
//	FileManager interface
//********************************************





// preprocessor
#include "DoubleLinkedString.h"





// structure
typedef struct FileManager {
	const char* name;
} FileManager;





// method
void FileManager__printFileToBinary(char* name);
void FileManager__printWithSimpleString(char* name);





// FileManager factory method
FileManager* allocFileManager();
FileManager* newFileManager();
