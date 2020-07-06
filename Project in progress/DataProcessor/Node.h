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
	struct DoubleLinkedNode* previous;
	void* data;
	struct DoubleLinkedNode* next;
} DoubleLinkedNode;





// method





// SingleLinkedNode factory method
SingleLinkedNode* SingleLinkedNode_alloc();

SingleLinkedNode* newSingleLinkedNode();

// DoubleLinkedNode factory method
DoubleLinkedNode* DoubleLinkedNode_alloc(size_t dataSize);
DoubleLinkedNode* newDoubleLinkedNode(
	void* data,
	struct DoubleLinkedNode* previous,
	struct DoubleLinkedNode* next,
	size_t dataSize);
DoubleLinkedNode* freeDoubleLinkedNode(DoubleLinkedNode* doubleLinkedNode);