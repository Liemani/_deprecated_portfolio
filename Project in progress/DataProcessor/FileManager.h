#pragma once
//********************************************
// char* title = "FileManager.h"
// made by Lieman at 2020.07.07
//
// description:
//	FileManager interface
//********************************************





// preprocessor





// structure
typedef struct FileManager {
	const char* name;
} FileManager;





// method
void FileManager_printFileToBinary(char* name);





// FileManager factory method
FileManager* allocFileManager();
FileManager* newFileManager();
