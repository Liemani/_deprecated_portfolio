#include <stdlib.h>	// exit(), malloc()
#include <assert.h> // assert()
#include "queue.h"

void initQueue(Queue* pq, int size)
{
	pq->pArr = malloc(sizeof(int) * size);
	assert(pq->pArr);
	pq->size = size;
	pq->front = 0;
	pq->rear = 0;
}

void cleanupQueue(Queue* pq)
{
	free(pq->pArr);
}

void push(Queue* pq, int data)
{
	pq->pArr[pq->rear] = data;

	//if (pq->rear == pq->size - 1) {
	//	pq->rear = 0;
	//} else {
	//	++pq->rear;
	//}

	++pq->rear;
	pq->rear %= pq->size;

	assert(pq->front != pq->rear);
}

int pop(Queue* pq)
{
	assert(pq->front != pq->rear);

	int index = pq->front;
	++pq->front;
	pq->front %= pq->size;

	//if (pq->front == pq->size - 1) {
	//	pq->front = 0;
	//} else {
	//	++pq->front;
	//}

	return pq->pArr[index];
}