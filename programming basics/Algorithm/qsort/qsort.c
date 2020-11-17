#include <stdio.h>
#include "qsort.h"

static void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void qsort(int *pArr, int left, int right)
{
	printf("qsort(pArr, %d, %d) \n", left, right);
	if (left >= right)
		return;
	
	int last = left;
	
	for (int i = left + 1; i <= right; ++i)
		if (pArr[left] > pArr[i]) {
			++last;
			swap(&pArr[last], &pArr[i]);	// swap(pArr +last, pArr + i)
		}
	
	swap(pArr + left, pArr + last);
	
	qsort(pArr, left, last - 1);
	qsort(pArr, last + 1, right);
}
