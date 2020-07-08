#pragma once
//********************************************
// char* title = "StringManager.h"
// made by Lieman at 2020.07.08
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





// static method
static DoubleLinkedNode* DoubleLinkedString__nodeAt(DoubleLinkedString* string, int index);

// method
char* DoubleLinkedString__subscript(DoubleLinkedString* string, int index);

void DoubleLinkedString__appendCharacter(DoubleLinkedString* string, char character);
void DoubleLinkedString__appendString(DoubleLinkedString* lhs, DoubleLinkedString* rhs);

void DoubleLinkedString__insertCharacterAt(DoubleLinkedString* string, char character, int index);
void DoubleLinkedString__insertStringAt(DoubleLinkedString* lhs, DoubleLinkedString* rhs, int index);

char DoubleLinkedString__removeCharacterAt(DoubleLinkedString* string, int index);

// count: The number of elements to remove from the collection. 
//		count must be greater than or equal to zero and must not exceed the number of elements in the collection.
DoubleLinkedString* DoubleLinkedString__removeFirstN(DoubleLinkedString* string, int count);

void DoubleLinkedString__lowercase(DoubleLinkedString* string);
void DoubleLinkedString__uppercase(DoubleLinkedString* string);





// StringManager factory method
StringManager* allocStringManager();
StringManager* newStringManager();

// DoubleLinkedString factory method
DoubleLinkedString* allocDoubleLinkedString();
DoubleLinkedString* newDoubleLinkedString__designated(DoubleLinkedNode* firstNode, DoubleLinkedNode* secondNode, int count);
DoubleLinkedString* newDoubleLinkedString();
DoubleLinkedString* freeDoubleLinkedString(DoubleLinkedString* doubleLinkedString);
