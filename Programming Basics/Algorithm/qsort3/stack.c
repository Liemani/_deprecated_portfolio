static int stack[100];
static int tos = 0;	// global variable initialized to 0

void push(int data)
{
	stack[tos] = data;
	++tos;
}

int pop(void)
{
	--tos;
	return stack[tos];
}

int isEmpty()
{
	return tos == 0;
}
