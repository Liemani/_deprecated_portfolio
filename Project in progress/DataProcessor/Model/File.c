//********************************************
// char* title = "File.c"
// made by Lieman at 2020.07.10
//
// description:
//	File implementation
//********************************************





// preprocessor
#include "File.h"





// method
char* File__read__NCharacter(SimpleString* simpleString, File* file, int count) {
	file->file;
	fread()
}





// File factory method
File* allocFile() {
	File* file = (File*)malloc(sizeof(File));

	return file;
}

File* newFile__designated(char* name) {
	File* file = allocFile();

	file->file = fopen(name, "rb");

	return file;
}

void deallocFile(File* file) {
	fclose(file->file);

	free(file);
}
