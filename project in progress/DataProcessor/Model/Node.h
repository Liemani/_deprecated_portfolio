#pragma once
//********************************************
// char* title = "Node.h"
// made by Lieman at 2020.07.07
//
// description:
//	Node interface
//********************************************





// preprocessor





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
void DoubleLinkedNode__connect(DoubleLinkedNode* lhs, DoubleLinkedNode* rhs);





// SingleLinkedNode factory method
SingleLinkedNode* allocSingleLinkedNode();

SingleLinkedNode* newSingleLinkedNode();

// DoubleLinkedNode factory method
DoubleLinkedNode* allocDoubleLinkedNode(int dataSize);
DoubleLinkedNode* newDoubleLinkedNode(
	void* data,
	struct DoubleLinkedNode* previous,
	struct DoubleLinkedNode* next,
	int dataSize);
DoubleLinkedNode* deallocDoubleLinkedNode(DoubleLinkedNode* doubleLinkedNode);
