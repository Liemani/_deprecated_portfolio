#include <iostream>
#include "boundArray.h"

int main()
{
	int nums1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double nums2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 11.0};
	
	BoundArray<int> arr1(2, 7, nums1);
	BoundArray<double> arr2(2, 7, nums2);
	
	for (int i = arr1.lower(); i <= arr1.upper(); ++i)
		std::cout << arr1[i] << std::endl;
		
	for (int i = arr2.lower(); i <= arr2.upper(); ++i)
		std::cout << arr2[i] << std::endl;
	
	Array<int>* pArr = new BoundArray<int>(2, 7, nums1);
	
	return 0;
}
