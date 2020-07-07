//********************************************
// char* title = "Node.c"
// made by Lieman at 2020.07.07
//
// description:
//	Node implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include <string.h>		// memcpy()
#include "Node.h"





// method
void DoubleLinkedNode_connect(DoubleLinkedNode* lhs, DoubleLinkedNode* rhs) {
	if (lhs) {
		lhs->next = rhs;
	}
	
	if (rhs) {
		rhs->previous = lhs;
	}
}





// SingleLinkedNode factory method
SingleLinkedNode* allocSingleLinkedNode() {
	SingleLinkedNode* singleLinkedNode = (SingleLinkedNode*)malloc(sizeof(SingleLinkedNode));

	// allocate here...

	return singleLinkedNode;
}

SingleLinkedNode* newSingleLinkedNode() {
	SingleLinkedNode* singleLinkedNode = allocSingleLinkedNode();

	// initialize here...

	return singleLinkedNode;
}

// DoubleLinkedNode factory method
DoubleLinkedNode* allocDoubleLinkedNode(size_t dataSize) {
	DoubleLinkedNode* doubleLinkedNode = (DoubleLinkedNode*)malloc(sizeof(DoubleLinkedNode));
	doubleLinkedNode->data = malloc(dataSize);

	return doubleLinkedNode;
}

DoubleLinkedNode* newDoubleLinkedNode(
	void* data,
	struct DoubleLinkedNode* previous,
	struct DoubleLinkedNode* next,
	size_t dataSize) {

	DoubleLinkedNode* doubleLinkedNode = allocDoubleLinkedNode(dataSize);

	memcpy(doubleLinkedNode->data, data, dataSize);

	DoubleLinkedNode_connect(previous, doubleLinkedNode);
	DoubleLinkedNode_connect(doubleLinkedNode, next);

	return doubleLinkedNode;
}

DoubleLinkedNode* freeDoubleLinkedNode(DoubleLinkedNode* doubleLinkedNode) {
	free(doubleLinkedNode->data);
	free(doubleLinkedNode);
}