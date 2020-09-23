#include <stdio.h>

typedef void FunctionType();

FunctionType funnyFunction = {
	printf("This is funny!");
}

int main() {
	funnyFunction();

	return 0;
}

