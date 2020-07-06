//********************************************
// char* title = "Node.c"
// made by Lieman at 2020.07.07
//
// description:
//	Node implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include "Node.h"





// method
void method() {

}





// SingleLinkedNode factory method
SingleLinkedNode* SingleLinkedNode_alloc() {
	SingleLinkedNode* singleLinkedNode = (SingleLinkedNode*)malloc(sizeof(SingleLinkedNode));

	// allocate here...

	return singleLinkedNode;
}

SingleLinkedNode* newSingleLinkedNode() {
	SingleLinkedNode* singleLinkedNode = SingleLinkedNode_alloc();

	// initialize here...

	return singleLinkedNode;
}

// DoubleLinkedNode factory method
DoubleLinkedNode* DoubleLinkedNode_alloc(size_t dataSize) {
	DoubleLinkedNode* doubleLinkedNode = (DoubleLinkedNode*)malloc(sizeof(DoubleLinkedNode));
	doubleLinkedNode->data = malloc(dataSize);

	return doubleLinkedNode;
}

DoubleLinkedNode* newDoubleLinkedNode(
	void* data,
	struct DoubleLinkedNode* previous,
	struct DoubleLinkedNode* next,
	size_t dataSize) {
	DoubleLinkedNode* doubleLinkedNode = DoubleLinkedNode_alloc(dataSize);

	doubleLinkedNode->data = data;
	doubleLinkedNode->previous = previous;
	doubleLinkedNode->next = next;

	previous ? previous->next = doubleLinkedNode : NULL;
	next ? next->previous = doubleLinkedNode : NULL;

	return doubleLinkedNode;
}

DoubleLinkedNode* freeDoubleLinkedNode(DoubleLinkedNode* doubleLinkedNode) {
	free(doubleLinkedNode->data);
	free(doubleLinkedNode);
}