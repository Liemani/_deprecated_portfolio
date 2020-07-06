#pragma once
//********************************************
// char* title = "FileManager"
// made by Lieman at 2020.07.06
//
// description:
//	FileManager
//********************************************





// preprocessor
#include <stdio.h>				// fopen(), fclose()
#include <stdlib.h>				// malloc()
#pragma warning(disable:4996)	// fopen()





// structure
typedef struct FileManager {
	const char* name;
} FileManager;





// method
void _FileManager_printFileToBinary(char* name) {
	FILE* file = fopen(name, "rb");

	if (file == NULL) return;

	int character;

	int row = 0;
	int phase = 0;

	char line[50];

	while (1) {
		sprintf
		for (int column = 0; column < 8; ++column) {
			character = fgetc(file);

			if (character == -1) {
				puts("ff");
				return;
			}

			printf("%02x ", character);
		}

		if (phase) {
			putchar('\b');
			putchar('\n');
			phase = 0;
		} else {
			putchar(' ');
			++phase;
		}

		++row;
	}

	fclose(file);
}





// initializer
FileManager* _FileManager_alloc() {
	FileManager* fileManager = (FileManager*)malloc(sizeof(FileManager));

	return fileManager;
}

FileManager* newFileManager() {
	FileManager* fileManager = _FileManager_alloc();

	return fileManager;
}