#include <stdio.h>

void swap(int& lhs, int& rhs) {
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int main(void) {
	int a = 10;
	int b= 20;
	
	swap(a, b);

	return 0;
}
