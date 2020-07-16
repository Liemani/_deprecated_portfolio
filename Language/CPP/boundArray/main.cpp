#include <iostream>
#include "boundArray.h"

int main()
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	BoundArray arr1(10, 20);
	// BoundArray arr2;			//SafeArray arr2(100);
	BoundArray arr3(2, 7, nums);
	BoundArray arr4(arr3);
	
	arr1 = arr3;
	if (arr1 == arr3)
		std::cout << "arr1 is equal to arr3" << std::endl;
	else
		std::cout << "arr1 is not equal to qrr3" << std::endl;
	
	for (int i = arr1.lower(); i <= arr1.upper(); ++i)
		std::cout << arr1[i] << std::endl;
	
	return 0;
}
