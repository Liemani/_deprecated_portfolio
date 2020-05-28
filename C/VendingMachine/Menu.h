#pragma once
//********************************************
// const title = "fileManager"
// made by Lieman at 2020.05.28
//
// description:
//	fileManager example
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include "beverage.h"
#include "constant.h"
#include "bool.h"

#define NO_TARGET 0
#define NO_TARGET_WITH_EOF 1
#define TARGET 2
#define TARGET_WITH_EOF 3

#define IS_TARGET 1
#define IS_EOF 2

#pragma warning(disable:4996)





// global variable
typedef struct FileManager {
	const char *name;

	Beverage **(*readAllBeverages)(struct FileManager* fileManager, int* count);
	void (*writeBeverage)(struct FileManager *fileManager, Beverage* beverage);
	void (*deleteBeverage)(struct FileManager* fileManager);
} FileManager;





// private function
/// assume:
///		check first character also
///
///	return: 0
///		EOF if feof(file)
///
///	file:
///		on the target character
///
int _FileManager_moveToNextCharacter(FILE* file, char targetCharacter) {
	while (1) {
		char isTarget = fgetc(file) == targetCharacter ? IS_TARGET : FALSE;
		char isEOF = feof(file) == EOF ? IS_EOF : FALSE;

		switch (isTarget | isEOF) {
			case NO_TARGET:
				break;
			case NO_TARGET_WITH_EOF:
				return EOF;
				break;
			case TARGET:
				fseek(file, -1, SEEK_CUR);
				return 0;
				break;
			case TARGET_WITH_EOF:
				fseek(file, 0, SEEK_CUR);
				return 0;
				break;
			default:
				printf("Invalid input\n");
				putchar('\n');
				break;
		}
	}
}

///
///	assume:
///		file is on '\0' at start
///		or feof(file) is true
///
///	return: size
///		EOF if feof(file)
///		INT_MAX if meet EOF
///
///	file:
///		dont' rewind
///
int _FileManager_sizeOfEmptySpace(FILE* file) {
	if (feof(file)) {
		return EOF;
	}

	int startIndex = ftell(file);

	while (fgetc(file) == '\0');

	int endIndex = ftell(file);
	int sizeOfEmptySpace = endIndex - startIndex;

	return feof(file) ? INT_MAX : sizeOfEmptySpace;
}

/// assume:
///		start location of file is one the beverage
///
///	return:
///
///	file:
///		after beverage
///
void _FileManager_moveAfterBeverage(FILE* file) {
	_FileManager_moveToNextCharacter(file, '\0');
	fseek(file, sizeof(int), SEEK_CUR); // EOF 가 뜨지 않아서 문제가 발생할 수 있다
}

void _FileManager_writeBeverageToFile(FILE *file, Beverage *beverage) {
	fwrite(beverage->name, sizeof(char), strlen(beverage->name) + 1, file);
	fwrite(&beverage->cost, sizeof(beverage->cost), 1, file);
}

// public function
Beverage *_FileManager_readBeverage(FILE *file) {
	while (fgetc(file) == '\0') {
		if (feof(file)) {
			return NULL;
		}
	}

	if (feof(file)) {
		return NULL;
	}

	fseek(file, -1, SEEK_CUR);

	char name[BEVERAGE_NAME_COUNT_LIMIT];
	int character = 0;
	int index = 0;
	while ((character = getc(file)) != '\0') {
		name[index] = character;
		index++;
	}
	name[index] = character;

	int cost = 0;
	fread(&cost, sizeof(cost), 1, file);

	Beverage* beverage = newBeverage(name, cost);
	return beverage;
}

Beverage** _FileManager_readAllBeverages(struct FileManager* fileManager, int *count) {
	FILE* file = fopen(fileManager->name, "rb");
	if (file == NULL) return NULL;

	Beverage** beverageArray = (Beverage**)malloc(sizeof(Beverage*) * BEVERAGE_ARRAY_COUNT_LIMIT);

	int beverageArrayCount = 0;
	Beverage* beverage;
	while ((beverage = _FileManager_readBeverage(file)) != NULL) {
		beverageArray[beverageArrayCount] = beverage;
		beverageArrayCount++;
	}

	realloc(beverageArray, sizeof(Beverage*) * beverageArrayCount);

	fclose(file);

	*count = beverageArrayCount;
	return beverageArray;
}

void _FileManager_writeBeverage(struct FileManager *fileManager, Beverage *beverage) {
	FILE* file = fopen(fileManager->name, "rb+");

	if (file == NULL) {
		file = fopen(fileManager->name, "ab");

		_FileManager_writeBeverageToFile(file, beverage);

		fclose(file);
		return;
	}

	int startIndex;
	int sizeOfEmptySpace;
	int beverageSize = strlen(beverage->name) + sizeof(char) + sizeof(int);

	do {
		if (fgetc(file) != '\0') {
			fseek(file, -1, SEEK_CUR);
			_FileManager_moveAfterBeverage(file);
		}

		if (feof(file)) {
			_FileManager_writeBeverageToFile(file, beverage);

			fclose(file);
			return;
		}

		startIndex = ftell(file);
		sizeOfEmptySpace = _FileManager_sizeOfEmptySpace(file);
	} while (sizeOfEmptySpace < beverageSize);

	fseek(file, startIndex, SEEK_SET);
	_FileManager_writeBeverageToFile(file, beverage);

	fclose(file);
}

void _FileManager_deleteBeverage(struct FileManager *fileManager) {
	FILE* file = fopen(fileManager->name, "rb+");

	printf("Code goes here...");

	fclose(file);
}

Beverage* _FileManager_readBeverage_another1(struct FileManager* fileManager) {
	FILE* file = fopen(fileManager->name, "rb");

	if (file == NULL) return NULL;

	int character = 0;

	int startIndex = 0;
	int endIndex = 0;

	while ((character = fgetc(file)) != '\0');
	startIndex = ftell(file) - 1;

	while ((character = fgetc(file)) != '\0');
	endIndex = ftell(file);

	char* name = (char*)malloc(endIndex - startIndex);

	fseek(file, startIndex, SEEK_SET);

	int index = 0;
	while ((character = fgetc(file)) != '\0') {
		name[index] = character;
		index++;
	}
	name[index] = character;

	int cost = 0; // 바로 아래에 fread()가 있으니 initialize 하지 않으면 오류가 나겠지?
	fread(&cost, sizeof(int), 1, file);

	fclose(file);

	return newBeverage(name, cost);
}





// allocation
FileManager *_FileManager_alloc() {
	FileManager *fileManager = (FileManager *)malloc(sizeof(FileManager));

	// initialize methods
	fileManager->readAllBeverages = _FileManager_readAllBeverages;
	fileManager->writeBeverage = _FileManager_writeBeverage;
	fileManager->deleteBeverage = _FileManager_deleteBeverage;

	return fileManager;
}

// initialization
FileManager* newFileManager() {
	FileManager* fileManager = _FileManager_alloc();

	// initialize properties
	fileManager->name = DATA_NAME;

	return fileManager;
}