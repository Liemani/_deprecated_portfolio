#pragma once
//********************************************
// char* title = "FileManager.h"
// made by Lieman at 2020.07.10
//
// description:
//	FileManager interface
//********************************************





// preprocessor
#include <stdio.h>





// structure
typedef struct FileManager {
	FILE* file;
} FileManager;





// method
void FileManager__printFileToBinary(char* name);
void FileManager__printWithSimpleString(char* name);





// FileManager factory method
FileManager* allocFileManager();
FileManager* newFileManager();
void deallocFileManager(FileManager* fileManager);
