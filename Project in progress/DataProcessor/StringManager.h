#pragma once
//********************************************
// char* title = "StringManager.h"
// made by Lieman at 2020.07.07
//
// description:
//	StringManager interface
//********************************************





// preprocessor
#include "StringManager.h"
#include "Node.h"





// structure
typedef struct StringManager {
	char* buffer;
} StringManager;

typedef struct DoubleLinkedString {
	DoubleLinkedNode* firstNode;
	int count;
} DoubleLinkedString;





// method
char* DoubleLinkedString_subscript(DoubleLinkedString* string, int index);
void DoubleLinkedString_append(DoubleLinkedString* string, char character);
void DoubleLinkedString_insertAt(DoubleLinkedString* string, char character, int index);
void DoubleLinkedString_removeAt(DoubleLinkedString* string, char character, int index);




// StringManager factory method
StringManager* StringManager_alloc();
StringManager* newStringManager();

// DoubleLinkedString factory method
DoubleLinkedString* DoubleLinkedString_alloc();
DoubleLinkedString* newDoubleLinkedString();
DoubleLinkedString* freeDoubleLinkedString(DoubleLinkedString* doubleLinkedString);
