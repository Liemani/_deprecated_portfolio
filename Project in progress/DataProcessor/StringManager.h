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
	DoubleLinkedNode* lastNode;
	int count;
} DoubleLinkedString;





// method
char* DoubleLinkedString_subscript(DoubleLinkedString* string, int index);

void DoubleLinkedString_appendCharacter(DoubleLinkedString* string, char character);
void DoubleLinkedString_appendString(DoubleLinkedString* lhs, DoubleLinkedString* rhs);

void DoubleLinkedString_insertCharacterAt(DoubleLinkedString* string, char character, int index);
void DoubleLinkedString_insertStringAt(DoubleLinkedString* lhs, DoubleLinkedString* rhs, int index);

char DoubleLinkedString_removeCharacterAt(DoubleLinkedString* string, int index);
DoubleLinkedString* DoubleLinkedString_removeSubrange(DoubleLinkedString* string, int startIndex, int endIndex);

void DoubleLinkedString_lowercase(DoubleLinkedString* string);
void DoubleLinkedString_uppercase(DoubleLinkedString* string);





// StringManager factory method
StringManager* allocStringManager();
StringManager* newStringManager();

// DoubleLinkedString factory method
DoubleLinkedString* allocDoubleLinkedString();
DoubleLinkedString* newDoubleLinkedString();
DoubleLinkedString* freeDoubleLinkedString(DoubleLinkedString* doubleLinkedString);
