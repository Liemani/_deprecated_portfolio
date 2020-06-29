#include <stdlib.h>	// exit()
#include <assert.h>
#include "queue.h"

void initQueue(Queue* pq, int size)
{
	pq->pArr = malloc(sizeof(int) * size);
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

	if (pq->rear == pq->size - 1) {
		pq->rear = 0;
	} else {
		++pq->rear;
	}

	assert(pq->front != pq->rear);
}

int pop(Queue* pq)
{
	assert(pq->front != pq->rear);

	int index = pq->front;

	if (pq->front == pq->size - 1) {
		pq->front = 0;
	} else {
		++pq->front;
	}

	return pq->pArr[index];
}