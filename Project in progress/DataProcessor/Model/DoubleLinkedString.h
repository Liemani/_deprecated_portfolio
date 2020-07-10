#pragma once
//********************************************
// char* title = "DoubleLinkedString.h"
// made by Lieman at 2020.07.08
//
// description:
//	DoubleLinkedString interface
//********************************************





// preprocessor
#include "Node.h"





typedef struct DoubleLinkedString {
	DoubleLinkedNode* firstNode;
	DoubleLinkedNode* lastNode;
	int count;
} DoubleLinkedString;





// static method
static DoubleLinkedNode* DoubleLinkedString__nodeAt(DoubleLinkedString* string, int index);
static void DoubleLinkedString__removeAll(DoubleLinkedString* string);

// method
char DoubleLinkedString__subscript(DoubleLinkedString* string, int index);

void DoubleLinkedString__appendCharacter(DoubleLinkedString* string, char character);
void DoubleLinkedString__appendString(DoubleLinkedString* lhs, DoubleLinkedString* rhs);

void DoubleLinkedString__insertCharacterAt(DoubleLinkedString* string, char character, int index);
void DoubleLinkedString__insertStringAt(DoubleLinkedString* lhs, DoubleLinkedString* rhs, int index);

char DoubleLinkedString__removeCharacterAt(DoubleLinkedString* string, int index);
void DoubleLinkedString__removeFirstFromTo(DoubleLinkedString* sourceString, DoubleLinkedString* destinationString, int count);

void DoubleLinkedString__lowercase(DoubleLinkedString* string);
void DoubleLinkedString__uppercase(DoubleLinkedString* string);





// DoubleLinkedString factory method
DoubleLinkedString* allocDoubleLinkedString();

DoubleLinkedString* newDoubleLinkedString__designated(DoubleLinkedNode* firstNode, DoubleLinkedNode* secondNode, int count);
DoubleLinkedString* newDoubleLinkedString();
DoubleLinkedString* newDoubleLinkedString__string(char* string);

DoubleLinkedString* deallocDoubleLinkedString(DoubleLinkedString* doubleLinkedString);
