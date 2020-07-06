#include <stdlib.h>	// exit()
#include <cassert>
#include "queue.h"

Queue::Queue(int size)
{
	//this->pArr = malloc(sizeof(int) * size);
	this->pArr = new int[size];
	this->size = size;
	this->front = 0;
	this->rear = 0;
}

Queue::~Queue()
{
	// free(this->pArr);
	delete [] this->pArr;
}

void Queue::push(int data)
{
	this->pArr[this->rear] = data;

	if (this->rear == this->size - 1) {
		this->rear = 0;
	} else {
		++this->rear;
	}

	assert(this->front != this->rear);
}

int Queue::pop()
{
	assert(this->front != this->rear);

	int index = this->front;

	if (this->front == this->size - 1) {
		this->front = 0;
	} else {
		++this->front;
	}

	return this->pArr[index];
}
