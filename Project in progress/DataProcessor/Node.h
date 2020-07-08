#pragma once
//********************************************
// char* title = "Node.h"
// made by Lieman at 2020.07.07
//
// description:
//	Node interface
//********************************************





// preprocessor
#include <wchar.h>	// size_t





// structure
typedef struct SingleLinkedNode {
	void* nothing;
} SingleLinkedNode;

typedef struct DoubleLinkedNode {
	void* data;
	struct DoubleLinkedNode* previous;
	struct DoubleLinkedNode* next;
} DoubleLinkedNode;





// method
void DoubleLinkedNode_connect(DoubleLinkedNode* lhs, DoubleLinkedNode* rhs);





// SingleLinkedNode factory method
SingleLinkedNode* allocSingleLinkedNode();

SingleLinkedNode* newSingleLinkedNode();

// DoubleLinkedNode factory method
DoubleLinkedNode* allocDoubleLinkedNode(size_t dataSize);
DoubleLinkedNode* newDoubleLinkedNode(
	void* data,
	struct DoubleLinkedNode* previous,
	struct DoubleLinkedNode* next,
	size_t dataSize);
DoubleLinkedNode* freeDoubleLinkedNode(DoubleLinkedNode* doubleLinkedNode);