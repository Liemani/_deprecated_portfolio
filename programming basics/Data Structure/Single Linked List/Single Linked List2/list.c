#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

static Node *createNode(int data, Node *next)
{
	Node *tmp = malloc(sizeof(Node));
	assert(tmp );
	tmp->data = data;
	tmp->next = next;
	return tmp;
}

void initList(List *pList)
{
	pList->ptr = createNode(-1, NULL);	// for to solve BAB problem in deleteNode
}

void cleanupList(List *pList)
{
	Node *ptr = pList->ptr;
	while (ptr ) {
		Node *tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	
//	Node *tmp = pList->ptr;
//	while () {
//	
//	}
}

void printList(const List *pList)
{
	Node *ptr = pList->ptr->next;
	printf("[");
	while (ptr ) {
		printf("%d%s", ptr->data, (ptr->next ) ? ", " : "");
		ptr = ptr->next;
	}
	printf("]\n");
	
//	Node *tmp = pList->ptr;
//	while (tmp->next != NULL) {
//		printf("data: %d \n", tmp->data);
//		tmp = tmp->next;
//	}
//	printf("data: %d \n", tmp->data);
}

void insertFirstNode(List *pList, const int data)
{
	//Node *ptr = malloc(sizeof(Node));
	//assert(ptr );
	//ptr->data = data;
	
	//ptr->next = pList->ptr->next;
	pList->ptr->next = createNode(data, pList->ptr->next);

}

void insertNode(List *pList, const int prevData, const int data)
{
	Node *ptr = pList->ptr->next;
	
	while (ptr ) {
		if (ptr->data == prevData)
			break;
		ptr = ptr->next;
	}
	
	if (ptr ) {
		//Node *tmp = malloc(sizeof(Node));
		//tmp->data = data;
		//tmp->next = ptr->next;
		//ptr->next = tmp;
		ptr->next = createNode(data, ptr->next);
	}
}

void deleteNode(List *pList, const int data)
{
	Node *ptr1 = pList->ptr->next;
	Node *ptr2 = pList->ptr;
	
	while (ptr1 ) {
		if (ptr1->data == data)
			break;
			
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next;
	}
	
	if (ptr1 ) {
		ptr2->next = ptr1->next;
		free(ptr1);
	}
	
	
	
//	Node *tmp = pList->entry;
//	
//	while (tmp->data) {
//	
//	}
}

