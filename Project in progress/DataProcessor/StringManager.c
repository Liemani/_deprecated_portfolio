#pragma once
//********************************************
// char* title = "StringManager.c"
// made by Lieman at 2020.07.07
//
// description:
//	StringManager implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include "StringManager.h"
#include "Node.h"





// method
char* DoubleLinkedString_subscript(DoubleLinkedString* string, int index) {
	if (index < 0 || string->count <= index) return NULL;

	DoubleLinkedNode* currentNode = string->firstNode;

	for (int i = 0; i < index; ++i)
		currentNode = currentNode->next;

	return (char*)currentNode->data;
}

void DoubleLinkedString_appendCharacter(DoubleLinkedString* string, char character) {
	if (string->lastNode) {
		string->lastNode = newDoubleLinkedNode(
			&character,
			string->lastNode,
			NULL,
			sizeof(char));

		string->lastNode->previous->next = string->lastNode;
	} else {
		string->firstNode = newDoubleLinkedNode(
			&character,
			NULL,
			NULL,
			sizeof(char));

		string->lastNode = string->firstNode;
	}

	++string->count;
}

void DoubleLinkedString_appendString(DoubleLinkedString* lhs, DoubleLinkedString* rhs) {
	DoubleLinkedNode_connect(lhs->lastNode, rhs->firstNode);

	lhs->lastNode = rhs->lastNode;

	rhs->firstNode = NULL;
	rhs->lastNode = NULL;

	lhs->count += rhs->count;
	freeDoubleLinkedString(rhs);
}

void DoubleLinkedString_insertCharacterAt(DoubleLinkedString* string, char character, int index) {
	if (index < string->count || string->count < index) return;

	if (index == string->count) {
		string->lastNode = newDoubleLinkedNode(
			&character,
			string->lastNode,
			NULL,
			sizeof(char));
	} else if (index) {
		DoubleLinkedNode* currentNode = string->firstNode;

		for (int i = 0; i < index; ++i)
			currentNode = currentNode->next;

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

void DoubleLinkedString_insertStringAt(DoubleLinkedString* lhs, DoubleLinkedString* rhs, int index) {
	if (index < lhs->count || lhs->count < index) return;

	if (index == lhs->count) {
		DoubleLinkedString_appendString(lhs, rhs);
	} else if (index) {
		DoubleLinkedNode* currentNode = lhs->firstNode;

		for (int i = 0; i < index; ++i)
			currentNode = currentNode->next;

		DoubleLinkedNode_connect(currentNode->previous, rhs->firstNode);
		DoubleLinkedNode_connect(rhs->lastNode, currentNode);

		rhs->firstNode = NULL;
		rhs->lastNode = NULL;

		lhs->count += rhs->count;
		freeDoubleLinkedString(rhs);
	} else {
		DoubleLinkedNode_connect(rhs->lastNode, lhs->firstNode);

		lhs->firstNode = rhs->firstNode;

		rhs->firstNode = NULL;
		rhs->lastNode = NULL;

		lhs->count += rhs->count;
		freeDoubleLinkedString(rhs);
	}
}

char DoubleLinkedString_removeCharacterAt(DoubleLinkedString* string, int index) {
	if (index < 0 || string->count <= index) return -1;

	DoubleLinkedNode* currentNode = string->firstNode;

	for (int i = 0; i < index; ++i)
		currentNode = currentNode->next;

	if (index == string->count - 1) {
		char character = *(char*)(string->lastNode->data);

		DoubleLinkedNode* currentNode = string->lastNode;
		string->lastNode = string->lastNode->previous;
		freeDoubleLinkedNode(currentNode);

		return character;
	} else if (index) {

	} else {

	}


	//if (currentNode->previous) {
	//	currentNode->previous->next = currentNode->next;
	//} else {
	//	string->firstNode = currentNode->previous;
	//}

	//if (currentNode->next) {
	//	currentNode->next->previous = currentNode->previous;
	//} else {
	//	string->lastNode = currentNode->next;
	//}

	//freeDoubleLinkedNode(currentNode);
}

void DoubleLinkedString_lowercase(DoubleLinkedString* string) {
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

void DoubleLinkedString_uppercase(DoubleLinkedString* string) {
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

DoubleLinkedString* newDoubleLinkedString() {
	DoubleLinkedString* doubleLinkedString = allocDoubleLinkedString();

	doubleLinkedString->firstNode = NULL;
	doubleLinkedString->lastNode = NULL;
	doubleLinkedString->count = 0;

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
