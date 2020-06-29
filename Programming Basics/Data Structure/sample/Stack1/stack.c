#include <stdio.h>

int stack[100];
int tos = -1;	// global variable initialized to 0

void push(int data)
{
	++tos;
	stack[tos] = data;
}

int pop(void)
{
	//int index = tos;
	//--tos;
	//return stack[index];
	return stack[tos--];
}

int main(void)
{
	push(100);
	push(200);
	push(300);

	printf("1st pop() : %d \n", pop());
	printf("2nd pop() : %d \n", pop());
	printf("3rd pop() : %d \n", pop());

	return 0;
}