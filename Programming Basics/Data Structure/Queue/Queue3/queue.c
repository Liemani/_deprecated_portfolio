#include <stdio.h>	// fprintf()
#include <stdlib.h>	// exit()
#include "queue.h"

void initQueue(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

void push(Queue* pq, int data)
{
	pq->arr[pq->rear] = data;

	if (pq->rear == QUEUESIZE - 1) {
		pq->rear = 0;
	} else {
		++pq->rear;
	}

	if (pq->front == pq->rear) {
		fprintf(stderr, "queue is full \n");
		exit(1);
	}
}

int pop(Queue* pq)
{
	if (pq->front == pq->rear) {
		fprintf(stderr, "queue is empty \n");
		exit(2);
	}

	int index = pq->front;

	if (pq->front == QUEUESIZE - 1) {
		pq->front = 0;
	} else {
		++pq->front;
	}

	return pq->arr[index];
}