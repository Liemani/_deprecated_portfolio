//********************************************
// char* title = "main.c"
// made by Lieman at 2020.07.07
//
// description:
//	main
//********************************************





#include "FileManager.h"
#include "StringManager.h"





void test00() {
	FileManager_printFileToBinary("test.dat");
}

void StringManagerTest00() {
	DoubleLinkedString *string = newDoubleLinkedString();
	printf("string.count: %d \n", string->count);
	DoubleLinkedString_append(string, 'a');
	printf("string.count: %d \n", string->count);
	char *character;
	if (character = DoubleLinkedString_subscript(string, 0)) {
		printf("*DoubleLinkedString_subscript(string, 0): %c \n", *character);
	} else {
		printf("DoubleLinkedString_subscript(string, 0) is NULL! \n");
	}

	DoubleLinkedString_formUppercase(string);
	if (character = DoubleLinkedString_subscript(string, 0)) {
		printf("*DoubleLinkedString_subscript(string, 0): %c \n", *character);
	} else {
		printf("DoubleLinkedString_subscript(string, 0) is NULL! \n");
	}
}

void printASCII() {
	for (int i = 0; i < 128; ++i) {
		printf("[%3d] %c \n", i, i);
	}
}





int main() {
	StringManagerTest00();

	return 0;
}
