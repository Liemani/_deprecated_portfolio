#include "queue.h"

int queue[100];
int front;
int rear;

void push(int data)
{
	queue[rear] = data;
	++rear;
}

int pop()
{
	//int index = front;
	//++front;
	//return queue[index];
	return queue[front++];
}