#include <stdio.h>

int gcd(int a, int b)
{
	int bigNumber;
	int smallNumber;
	int temp;
	
	if (a > b) {
		bigNumber = a;
		smallNumber = b;
	} else {
		bigNumber = b;
		smallNumber = a;
	}
	
	while (smallNumber) {
		temp = bigNumber % smallNumber;
		bigNumber = smallNumber;
		smallNumber = temp;
	}
	
	return bigNumber;
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("gcd: %d \n", gcd(a, b));

	return 0;
}
