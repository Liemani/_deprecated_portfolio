#pragma once
//********************************************
// char* title = "FileManager.c"
// made by Lieman at 2020.07.09
//
// description:
//	FileManager implementation
//********************************************





// preprocessor
#include <stdio.h>				// fopen(), fclose()
#include <stdlib.h>				// malloc()
#include "FileManager.h"
#include "DoubleLinkedString.h"
#include "SimpleString.h"
#pragma warning(disable:4996)	// fopen()





// method
void FileManager__printFileToBinary(char* name) {
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

void FileManager__printWithSimpleString(char* name) {
	FILE* file = fopen(name, "rb");

	if (file == NULL) return;

	int character;

	int row = 0;
	int phase = 1;

	SimpleString* line = newSimpleString();
	SimpleString* hexString = newSimpleString();
	SimpleString* characterString = newSimpleString();

	while (1) {
		for (int column = 0; column < 8; ++column) {
			character = fgetc(file);

			SimpleString__append__hex__fromUCharacter(hexString, (unsigned char)character);
			SimpleString__append__Character(hexString, ' ');

			SimpleString__append__Character(characterString, character);

			if (character == -1) return;
		}

		SimpleString__append__Character(hexString, ' ');

		if (phase) {
			phase = 0;
		} else {
			SimpleString__append__Character(hexString, '\n');
			SimpleString__append__SimpleString(line, hexString);
			SimpleString__append__SimpleString(line, characterString);

			for (int i = 0; i < line->count; ++i) {
				printf("%c", line->string[i]);
			}

			SimpleStringg__removeAll(hexString);
			SimpleStringg__removeAll(characterString);
			++row;
			++phase;
		}
	}

	fclose(file);
}





// FileManager factory method
FileManager* allocFileManager() {
	FileManager* fileManager = (FileManager*)malloc(sizeof(FileManager));

	return fileManager;
}

FileManager* newFileManager() {
	FileManager* fileManager = allocFileManager();

	return fileManager;
}