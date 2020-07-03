#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "qsort.h"

static void swap(void *pa, void *pb, size_t size)
{
	void *tmp = malloc(size);
	
	memcpy(tmp, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, tmp, size);
	
	free(tmp);
}

void qsort(void *pArr, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	push(size * (nmemb - 1));
	push(size * 0);
	
	while( !isEmpty()) {
		int start = pop();
		int end = pop();
		
		printf("start: %d\t end: %d\n", start, end);
		
		int last = start;
		for (int i = start + size; i <= end; i += size)
			if (!compar(pArr + start, pArr + i)) {
				last += size;
				swap(pArr + last, pArr + i, size);
			}
		
		swap(pArr + start, pArr + last, size);

		if (start < end) {
			push(end);
			push(last + size);
			push(last - size);
			push(start);
		}
	}
}
