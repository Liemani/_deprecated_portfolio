#pragma once
//********************************************
// char* title = "StringManager"
// made by Lieman at 2020.07.06
//
// description:
//	StringManager
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include "Node.h"





// structure
typedef struct StringManager {
	char* buffer;
} StringManager;

typedef struct DoubleLinkedString {
	DoubleLinkedNode* firstNode;
	size_t size;
} DoubleLinkedString;





// method
void* DoubleLinkedString_subscript(DoubleLinkedString* string, int index) {
	DoubleLinkedNode* temporaryNode = string->firstNode;

	if (!temporaryNode ||
		index < 0) {
		return NULL;
	}

	if (temporaryNode) {
		DoubleLinkedNode* currentNode = temporaryNode;

		for (int i = 0; (temporaryNode = temporaryNode->next) && i < index; ++i)
			currentNode = temporaryNode;

		return currentNode->data;
	} else {
		return NULL;
	}
}

void DoubleLinkedString_append(DoubleLinkedString *string, char character) {
	DoubleLinkedNode* temporaryNode = string->firstNode;

	if (temporaryNode) {
		DoubleLinkedNode* currentNode = temporaryNode;

		while (temporaryNode = temporaryNode->next)
			currentNode = temporaryNode;

		DoubleLinkedNode* doubleLinkedNode = newDoubleLinkedNode(
			&character,
			temporaryNode,
			NULL,
			sizeof(char));
	} else {
		DoubleLinkedNode *doubleLinkedNode = newDoubleLinkedNode(
			&character,
			NULL,
			NULL,
			sizeof(char));
		string->firstNode = doubleLinkedNode;
	}
}

void DoubleLinkedString_insert(DoubleLinkedString* string, char character, int index) {
	DoubleLinkedNode* temporaryNode = string->firstNode;

	if (temporaryNode) {
		DoubleLinkedNode* currentNode = temporaryNode;

		for (int i = 0; (temporaryNode = temporaryNode->next) && i < index; ++i)
			currentNode = temporaryNode;

		DoubleLinkedNode* doubleLinkedNode = newDoubleLinkedNode(
			&character,
			temporaryNode,
			temporaryNode->next,
			sizeof(char));
	} else {
		DoubleLinkedNode* doubleLinkedNode = newDoubleLinkedNode(
			&character,
			NULL,
			NULL,
			sizeof(char));
		string->firstNode = doubleLinkedNode;
	}
}





// StringManager factory
StringManager* _StringManager_alloc() {
	StringManager* stringManager = (StringManager*)malloc(sizeof(StringManager));

	return stringManager;
}

StringManager* newStringManager() {
	StringManager* stringManager = _StringManager_alloc();

	return stringManager;
}

// DoubleLinkedString factory
DoubleLinkedString* _DoubleLinkedString_alloc() {
	DoubleLinkedString* doubleLinkedString = (DoubleLinkedString*)malloc(sizeof(DoubleLinkedString));

	return doubleLinkedString;
}

DoubleLinkedString* newDoubleLinkedString(size_t size) {
	DoubleLinkedString* doubleLinkedString = _DoubleLinkedString_alloc();

	doubleLinkedString->firstNode = NULL;
	doubleLinkedString->size = size;

	return doubleLinkedString;
}

DoubleLinkedString* freeDoubleLinkedString(DoubleLinkedString* doubleLinkedString) {
	freeDoubleLinkedNode(doubleLinkedString->firstNode);
	free(doubleLinkedString);
}
