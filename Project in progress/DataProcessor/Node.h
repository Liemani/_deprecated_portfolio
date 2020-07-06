#pragma once
//********************************************
// char* title = "Node"
// made by Lieman at 2020.07.06
//
// description:
//	Node
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()





// structure
typedef struct SingleLinkedNode {

} SingleLinkedNode;

typedef struct DoubleLinkedNode {
	struct DoubleLinkedNode* previous;
	void* data;
	struct DoubleLinkedNode* next;
} DoubleLinkedNode;





// method
void method() {

}





// SingleLinkedNode factory
SingleLinkedNode* _SingleLinkedNode_alloc() {
	SingleLinkedNode* singleLinkedNode = (SingleLinkedNode*)malloc(sizeof(SingleLinkedNode));

	// allocate here...

	return singleLinkedNode;
}

SingleLinkedNode* newSingleLinkedNode() {
	SingleLinkedNode* singleLinkedNode = _SingleLinkedNode_alloc();

	// initialize here...

	return singleLinkedNode;
}

// DoubleLinkedNode factory
DoubleLinkedNode* _DoubleLinkedNode_alloc(size_t dataSize) {
	DoubleLinkedNode* doubleLinkedNode = (DoubleLinkedNode*)malloc(sizeof(DoubleLinkedNode));
	doubleLinkedNode->data = malloc(dataSize);

	return doubleLinkedNode;
}

DoubleLinkedNode* newDoubleLinkedNode(
	void *data,
	struct DoubleLinkedNode* previous,
	struct DoubleLinkedNode* next,
	size_t dataSize) {
	DoubleLinkedNode* doubleLinkedNode = _DoubleLinkedNode_alloc(dataSize);

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