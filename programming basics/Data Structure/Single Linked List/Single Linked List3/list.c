#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

static Node* createNode(const void* pData, Node* next, int eleSize) {
	Node* tmp = malloc(sizeof(Node) + eleSize);
	assert(tmp);
	tmp->next = next;
	if (pData) {
		memcpy(tmp + 1, pData, eleSize);
	}

	return tmp;
}

void initList(List* pList, int eleSize)
{
	//pList->ptr = malloc(sizeof(Node));
	//assert(pList->ptr );
	pList->eleSize = eleSize;

	pList->ptr = createNode(NULL, NULL, eleSize);

	//pList->ptr->next = NULL;
}

void cleanupList(List* pList)
{
	Node* ptr = pList->ptr;
	while (ptr) {
		Node* tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

void printList(const List* pList, void (*print)(const void* pData))
{
	Node* ptr = pList->ptr->next;
	printf("[");
	while (ptr) {
		print(ptr + 1);
		printf("%s", (ptr->next) ? ", " : "");
		ptr = ptr->next;
	}
	printf("]\n");
}

void insertFirstNode(List* pList, const void* pData)
{
	//Node *ptr = malloc(sizeof(Node) + pList->eleSize);
	//assert(ptr );
	//memcpy(ptr + 1, pData, pList->eleSize);
	//
	//ptr->next = pList->ptr->next;
	//pList->ptr->next = ptr;

	pList->ptr->next = createNode(pData, pList->ptr->next, pList->eleSize);
}

void insertNode(List* pList, const void* pPrevData, const void* pData)
{
	Node* ptr = pList->ptr->next;

	while (ptr ) {
		//if (ptr->data == prevData)
		if (memcmp(ptr + 1, pPrevData, pList->eleSize) == 0)
			break;
		ptr = ptr->next;
	}

	if (ptr) {
		// Node *tmp = malloc(sizeof(Node) + pList->eleSize);
		//assert(tmp );
		//tmp->data = data;
		//memcpy(tmp + 1, pData, pList->eleSize);
		//tmp->next = ptr->next;
		//ptr->next = tmp;

		ptr->next = createNode(pData, ptr->next, pList->eleSize);
	}
}

void eleteNode(List* pList, const void* pData)
{
	Node* ptr1 = pList->ptr->next;
	Node* ptr2 = pList->ptr;

	while (ptr1) {
		//if (ptr1->data == data)
		if (memcmp(ptr1 + 1, pData, pList->eleSize) == 0)
			break;

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	if (ptr1) {
		ptr2->next = ptr1->next;
		free(ptr1);
	}
}