#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue q1, q2;

	initQueue(&q1, 10, sizeof(int));
	initQueue(&q2, 100, sizeof(double));

	int i = 100;	push(&q1, &i);
	i = 200;		push(&q1, &i);

	pop(&q1, &i);	printf("1st pop(): %d \n", i);

	i = 300;		push(&q1, &i);
	pop(&q1, &i);	printf("2nd pop(): %d \n", i);
	pop(&q1, &i);	printf("3rd pop(): %d \n", i);

	double d = 1.1;	push(&q2, &d);
	d = 2.2;		push(&q2, &d);

	pop(&q2, &d);	printf("1st pop(): %f \n", d);

	d = 3.3;		push(&q2, &d);
	pop(&q2, &d);	printf("2nd pop(): %f \n", d);
	pop(&q2, &d);	printf("3rd pop(): %f \n", d);

	return 0;
}