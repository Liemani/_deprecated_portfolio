#pragma once
//********************************************
// char* title = "StringManager.c"
// made by Lieman at 2020.07.08
//
// description:
//	StringManager implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include "StringManager.h"
#include "Node.h"



// static method
static DoubleLinkedNode* DoubleLinkedString__nodeAt(DoubleLinkedString* string, int index) {
	if (index < 0 || string->count <= index) return NULL;

	DoubleLinkedNode* currentNode = string->firstNode;

	for (int i = 0; i < index; ++i)
		currentNode = currentNode->next;

	return currentNode;
}

// method
char* DoubleLinkedString__subscript(DoubleLinkedString* string, int index) {
	if (index < 0 || string->count <= index) return NULL;

	return (char*)DoubleLinkedString__nodeAt(string, index)->data;
}

void DoubleLinkedString__appendCharacter(DoubleLinkedString* string, char character) {
	if (string->lastNode) {
		string->lastNode = newDoubleLinkedNode(
			&character,
			string->lastNode,
			NULL,
			sizeof(char));
	} else {
		string->firstNode = string->lastNode = newDoubleLinkedNode(
			&character,
			NULL,
			NULL,
			sizeof(char));
	}

	++string->count;
}

void DoubleLinkedString__appendString(DoubleLinkedString* lhs, DoubleLinkedString* rhs) {
	DoubleLinkedNode__connect(lhs->lastNode, rhs->firstNode);

	lhs->lastNode = rhs->lastNode;

	rhs->firstNode = NULL;
	rhs->lastNode = NULL;

	lhs->count += rhs->count;
	freeDoubleLinkedString(rhs);
}

void DoubleLinkedString__insertCharacterAt(DoubleLinkedString* string, char character, int index) {
	if (index < string->count || string->count < index) return;

	// insert a character at index
	if (index == string->count) {
		string->lastNode = newDoubleLinkedNode(
			&character,
			string->lastNode,
			NULL,
			sizeof(char));
	} else if (index) {
		DoubleLinkedNode* currentNode = DoubleLinkedString__nodeAt(string, index);

		newDoubleLinkedNode(
			&character,
			currentNode->previous,
			currentNode,
			sizeof(char));
	} else {
		string->firstNode = newDoubleLinkedNode(
			&character,
			NULL,
			string->firstNode,
			sizeof(char));
	}

	++string->count;
}

void DoubleLinkedString__insertStringAt(DoubleLinkedString* lhs, DoubleLinkedString* rhs, int index) {
	if (index < lhs->count || lhs->count < index) return;

	if (index == lhs->count) {
		DoubleLinkedString__appendString(lhs, rhs);
	} else if (index) {
		DoubleLinkedNode* currentNode = DoubleLinkedString__nodeAt(lhs, index);

		DoubleLinkedNode__connect(currentNode->previous, rhs->firstNode);
		DoubleLinkedNode__connect(rhs->lastNode, currentNode);

		rhs->firstNode = NULL;
		rhs->lastNode = NULL;

		lhs->count += rhs->count;
		freeDoubleLinkedString(rhs);
	} else {
		DoubleLinkedNode__connect(rhs->lastNode, lhs->firstNode);

		lhs->firstNode = rhs->firstNode;

		rhs->firstNode = NULL;
		rhs->lastNode = NULL;

		lhs->count += rhs->count;
		freeDoubleLinkedString(rhs);
	}
}

char DoubleLinkedString__removeCharacterAt(DoubleLinkedString* string, int index) {
	if (index < 0 || string->count <= index) return -1;

	DoubleLinkedNode* currentNode = DoubleLinkedString__nodeAt(string, index);

	char character = *(char*)(string->lastNode->data);

	if (index == string->count - 1) {
		string->lastNode = string->lastNode->previous;
		DoubleLinkedNode__connect(string->lastNode, NULL);
	} else if (index) {
		DoubleLinkedNode__connect(currentNode->previous, currentNode->next);
	} else {
		string->firstNode = string->firstNode->next;
		DoubleLinkedNode__connect(NULL, string->firstNode);
	}

	freeDoubleLinkedNode(currentNode);

	--string->count;

	return character;
}

DoubleLinkedString* DoubleLinkedString__removeFirstN(DoubleLinkedString* string, int count) {
	if (count <= 0 || string->count < count) return NULL;

	DoubleLinkedNode* currentNode = DoubleLinkedString__nodeAt(string, count - 1);

	DoubleLinkedString* firstNString = newDoubleLinkedString__designated(string->firstNode, currentNode, count);

	string->firstNode = currentNode->next;
	string->count -= count;

	return firstNString;
}

void DoubleLinkedString__lowercase(DoubleLinkedString* string) {
	DoubleLinkedNode* currentNode = string->firstNode;

	char character;

	while (currentNode) {
		character = *(char *)currentNode->data;

		if ('A' <= character &&
			character <= 'Z'
			) {
			character += -'A' + 'a';
			memcpy(currentNode->data, &character, sizeof(char));
		}

		currentNode = currentNode->next;
	}
}

void DoubleLinkedString__uppercase(DoubleLinkedString* string) {
	DoubleLinkedNode* currentNode = string->firstNode;

	char character;

	while (currentNode) {
		character = *(char*)currentNode->data;

		if ('a' <= character &&
			character <= 'z'
			) {
			character += -'a' + 'A';
			memcpy(currentNode->data, &character, sizeof(char));
		}

		currentNode = currentNode->next;
	}
}





// StringManager factory method
StringManager* allocStringManager() {
	StringManager* stringManager = (StringManager*)malloc(sizeof(StringManager));

	return stringManager;
}

StringManager* newStringManager() {
	StringManager* stringManager = allocStringManager();

	return stringManager;
}

// DoubleLinkedString factory method
DoubleLinkedString* allocDoubleLinkedString() {
	DoubleLinkedString* doubleLinkedString = (DoubleLinkedString*)malloc(sizeof(DoubleLinkedString));

	return doubleLinkedString;
}

DoubleLinkedString* newDoubleLinkedString__designated(DoubleLinkedNode* firstNode, DoubleLinkedNode* secondNode, int count) {
	DoubleLinkedString* doubleLinkedString = allocDoubleLinkedString();

	doubleLinkedString->firstNode = firstNode;
	doubleLinkedString->lastNode = secondNode;
	doubleLinkedString->count = count;

	return doubleLinkedString;
}

DoubleLinkedString* newDoubleLinkedString() {
	DoubleLinkedString* doubleLinkedString = newDoubleLinkedString__designated(NULL, NULL, 0);

	return doubleLinkedString;
}

DoubleLinkedString* newDoubleLinkedString__string(char* string) {
	DoubleLinkedString* doubleLinkedString = newDoubleLinkedString__designated(NULL, NULL, 0);

	char character;

	while (character = string[doubleLinkedString->count])
		DoubleLinkedString__appendCharacter(doubleLinkedString, character);

	return doubleLinkedString;
}

DoubleLinkedString* freeDoubleLinkedString(DoubleLinkedString* doubleLinkedString) {
	DoubleLinkedNode *currentNode = doubleLinkedString->firstNode;

	while (currentNode->next) {
		currentNode = currentNode->next;
		freeDoubleLinkedNode(currentNode->previous);
	}

	freeDoubleLinkedNode(currentNode);

	free(doubleLinkedString);
}
