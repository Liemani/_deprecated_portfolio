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
	if (
		index < 0 ||
		string->count <= index
		)
		return NULL;

	DoubleLinkedNode* currentNode = string->firstNode;

	for (int i = 0; i < index; ++i)
		currentNode = currentNode->next;

	return (char*)currentNode->data;
}

void DoubleLinkedString_append(DoubleLinkedString* string, char character) {
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
		DoubleLinkedNode* doubleLinkedNode = newDoubleLinkedNode(
			&character,
			NULL,
			NULL,
			sizeof(char));
		string->firstNode = doubleLinkedNode;
	}

	++string->count;
}

void DoubleLinkedString_insertAt(DoubleLinkedString* string, char character, int index) {
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

	++string->count;
}

void DoubleLinkedString_removeAt(DoubleLinkedString* string, char character, int index) {

}




// StringManager factory method
StringManager* StringManager_alloc() {
	StringManager* stringManager = (StringManager*)malloc(sizeof(StringManager));

	return stringManager;
}

StringManager* newStringManager() {
	StringManager* stringManager = StringManager_alloc();

	return stringManager;
}

// DoubleLinkedString factory method
DoubleLinkedString* DoubleLinkedString_alloc() {
	DoubleLinkedString* doubleLinkedString = (DoubleLinkedString*)malloc(sizeof(DoubleLinkedString));

	return doubleLinkedString;
}

DoubleLinkedString* newDoubleLinkedString() {
	DoubleLinkedString* doubleLinkedString = DoubleLinkedString_alloc();

	doubleLinkedString->firstNode = NULL;
	doubleLinkedString->count = 0;

	return doubleLinkedString;
}

DoubleLinkedString* freeDoubleLinkedString(DoubleLinkedString* doubleLinkedString) {
	freeDoubleLinkedNode(doubleLinkedString->firstNode);
	free(doubleLinkedString);
}
