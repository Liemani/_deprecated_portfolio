#include <iostream>
#include "array.h"
#include "safeArray.h"

int main()
{
	int nums1[] = {1, 2, 3, 4, 5};
	SafeArray<int> arr1(nums1, 5);
	
	double nums2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	SafeArray<double> arr2(nums2, 5);
	
	Array<int>* pArr = new SafeArray<int>(nums1, 5);
	
	delete pArr;
	
	return 0;
}
