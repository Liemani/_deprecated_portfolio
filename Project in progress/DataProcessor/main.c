//********************************************
// char* title = "main.c"
// made by Lieman
//
// description:
//	main function and test
//********************************************





// preprocessor
#include "Controller/ViewController.h"

#include "Controller/FileManager.h"
#include "Model/DoubleLinkedString.h"
#include "Test/LMTPlayground.h"

#include "Model/LMTData.h"
#include "Model/LMTString.h"




//void test00() {
//	FileManager__printFileToBinary("test.dat");
//}
//
//void SimpleStringTest00() {
//	DoubleLinkedString *string = newDoubleLinkedString();
//
//	printf("string.count: %d \n", string->count);
//
//	DoubleLinkedString__appendCharacter(string, 'a');
//
//	printf("string.count: %d \n", string->count);
//
//	char *character;
//
//	if (character = DoubleLinkedString__subscript(string, 0)) {
//		printf("*DoubleLinkedString__subscript(string, 0): %c \n", *character);
//	} else {
//		printf("DoubleLinkedString__subscript(string, 0) is NULL! \n");
//	}
//
//	DoubleLinkedString__uppercase(string);
//
//	if (character = DoubleLinkedString__subscript(string, 0)) {
//		printf("*DoubleLinkedString__subscript(string, 0): %c \n", *character);
//	} else {
//		printf("DoubleLinkedString__subscript(string, 0) is NULL! \n");
//	}
//}
//
//void SimpleStringTest01() {
//	DoubleLinkedString* string = newDoubleLinkedString__string("a");
//
//	char character;
//
//	if (character = DoubleLinkedString__subscript(string, 0)) {
//		printf("*DoubleLinkedString__subscript(string, 0): %c \n", character);
//	} else {
//		printf("DoubleLinkedString__subscript(string, 0) is NULL! \n");
//	}
//}
//
//void printASCII() {
//	for (int i = 0; i < 128; ++i) {
//		printf("[%3d] %c \n", i, i);
//	}
//}
//
//void test01() {
//	printf("strlen(\"\"): %d \n", strlen(""));
//	printf("-7 / 3: %d \n", -7 / 3);
//	printf(" -5 / 10: %d \n", -5 / 10);
//}
//
//void dataProcessor__ViewController__entry() {
//	ViewController* viewController = newViewController();
//	ViewController__entry(viewController);
//}

void monoTest01() {
	LMTData* pLMTData = newLMTData();

	LMTData__descript(pLMTData);

	LMTData__append__character(&pLMTData, 'a');

	LMTData__descript(pLMTData);

	LMTData__append__character(&pLMTData, 'b');

	LMTData__descript(pLMTData);

	LMTData* pLMTData2 = newLMTData__string("hello!");

	LMTData__descript(pLMTData2);
}

void monoTest02() {
	LMTPlayground* playground = newLMTPlayground();
	LMTPlayground__append__character(&playground, 'a');
	printf("%d", LMTPlayground__getCount(playground));
}

void targetTest(char* fileName) {
	LMTFile* pFile = NULL;
	LMTData* pData = NULL;
	LMTString* line = NULL;
	LMTData* space = NULL;
	
	newLMTData__string(&space, " ")

	newLMTFile(&pFile, fileName);

	LMTFile__copy_8Data(pData, pFile);
	newLMTString__Data(&line, pData);
	
	for (int i = 0; i < 8; ++i) {
		LMTString__append_hex_by_char(line, LMTData__Data_at_index(pData, i));
		LMTString__append_character(line, space);
	}
}





int main() {
	//FileManager__printWithSimpleString("test.dat");
	monoTest01();

	return 0;
}
