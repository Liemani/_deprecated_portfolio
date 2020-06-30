#include <stdio.h>

void test01() {
	printf("__LINE__: %d \n", __LINE__);
	printf("__LINE__: %d \n", __LINE__);
	printf("__LINE__: %d \n", __LINE__);
	printf("__LINE__: %d \n", __LINE__);
	printf("__LINE__: %d \n", __LINE__);
}

int main(void) {
	test01();

	return 0;
}