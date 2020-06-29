#include <stdlib.h>	// exit()
#include <assert.h>
#include <string.h> // memcpy()
#include "queue.h"

void initQueue(Queue* pq, int size, int eleSize)
{
	pq->pArr = malloc(eleSize * size);
	pq->eleSize = eleSize;
	pq->size = size;
	pq->front = 0;
	pq->rear = 0;
}

void cleanupQueue(Queue* pq)
{
	free(pq->pArr);
}

void push(Queue* pq, const void* pData)
{
	memcpy(pq->pArr + pq->eleSize * pq->rear, pData, pq->eleSize);

	if (pq->rear == pq->size - 1) {
		pq->rear = 0;
	} else {
		++pq->rear;
	}

	assert(pq->front != pq->rear);
}

void pop(Queue* pq, void* pData)
{
	assert(pq->front != pq->rear);

	int index = pq->front;

	if (pq->front == pq->size - 1) {
		pq->front = 0;
	} else {
		++pq->front;
	}

	memcpy(pData, pq->pArr + pq->eleSize * index, pq->eleSize);
}