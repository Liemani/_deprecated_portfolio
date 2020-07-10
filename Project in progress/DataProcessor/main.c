//********************************************
// char* title = "main.c"
// made by Lieman at 2020.07.10
//
// description:
//	main function and test
//********************************************





// preprocessor
#include <stdio.h>
#include <string.h>
#include "Controller/ViewController.h"

#include "Controller/FileManager.h"
#include "Model/DoubleLinkedString.h"
#include "Model/SimpleString.h"




void test00() {
	FileManager__printFileToBinary("test.dat");
}

void SimpleStringTest00() {
	DoubleLinkedString *string = newDoubleLinkedString();

	printf("string.count: %d \n", string->count);

	DoubleLinkedString__appendCharacter(string, 'a');

	printf("string.count: %d \n", string->count);

	char *character;

	if (character = DoubleLinkedString__subscript(string, 0)) {
		printf("*DoubleLinkedString__subscript(string, 0): %c \n", *character);
	} else {
		printf("DoubleLinkedString__subscript(string, 0) is NULL! \n");
	}

	DoubleLinkedString__uppercase(string);

	if (character = DoubleLinkedString__subscript(string, 0)) {
		printf("*DoubleLinkedString__subscript(string, 0): %c \n", *character);
	} else {
		printf("DoubleLinkedString__subscript(string, 0) is NULL! \n");
	}
}

void SimpleStringTest01() {
	DoubleLinkedString* string = newDoubleLinkedString__string("a");

	char character;

	if (character = DoubleLinkedString__subscript(string, 0)) {
		printf("*DoubleLinkedString__subscript(string, 0): %c \n", character);
	} else {
		printf("DoubleLinkedString__subscript(string, 0) is NULL! \n");
	}
}

void printASCII() {
	for (int i = 0; i < 128; ++i) {
		printf("[%3d] %c \n", i, i);
	}
}

void test01() {
	printf("strlen(\"\"): %d \n", strlen(""));
	printf("-7 / 3: %d \n", -7 / 3);
	printf(" -5 / 10: %d \n", -5 / 10);
}

void dataProcessor__ViewController__entry() {
	ViewController* viewController = newViewController();
	ViewController__entry(viewController);
}





int main() {
	FileManager__printWithSimpleString("test.dat");

	return 0;
}
