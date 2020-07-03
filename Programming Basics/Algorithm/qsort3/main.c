#include <stdio.h>
#include "qsort.h"

int increaseingOrder_equalIncluded_int(const void *lhs, const void *rhs)
{
	return *(int *)lhs <= *(int *)rhs;
}

int main(void)
{
	int nums[] = {3, 4, 6, 1, 2, 7, 9, 10, 8, 5};
	qsort(nums, sizeof(nums) / sizeof(int), sizeof(int), increaseingOrder_equalIncluded_int);
	
	for (int i = 0; i < 10; ++i)
		printf("%d ", nums[i]);
	printf("\n");
	
	return 0;
}
