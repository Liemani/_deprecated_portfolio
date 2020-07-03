#ifndef LIST_H
#define LIST_H

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct list {
	Node *ptr;
} List;

void initList(List *pList);
void cleanupList(List *pList);

void printList(const List *pList);

void insertFirstNode(List *pList, const int data);
void insertNode(List *pList, const int prevData, const int data);
void deleteNode(List *pList, const int data);

#endif
