#pragma once
//********************************************
// char* title = "FileManager.c"
// made by Lieman at 2020.07.07
//
// description:
//	FileManager implementation
//********************************************





// preprocessor
#include <stdio.h>				// fopen(), fclose()
#include <stdlib.h>				// malloc()
#include "FileManager.h"
#pragma warning(disable:4996)	// fopen()





// method
void FileManager_printFileToBinary(char* name) {
	FILE* file = fopen(name, "rb");

	if (file == NULL) return;

	int character;

	int row = 0;
	int phase = 0;

	char line[50];

	while (1) {
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





// FileManager factory method
FileManager* FileManager_alloc() {
	FileManager* fileManager = (FileManager*)malloc(sizeof(FileManager));

	return fileManager;
}

FileManager* newFileManager() {
	FileManager* fileManager = FileManager_alloc();

	return fileManager;
}