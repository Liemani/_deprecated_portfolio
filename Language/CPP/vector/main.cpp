#include <iostream>
#include "array.h"
#include "safeArray.h"
#include "invalidIndex.h"
#include "vector.h"
template<typename T>
void printVector(const Vector<T>& vector) {
	for (int i = 0; i < vector.size(); ++i)
		std::cout << vector[i] << " ";
	
	std::cout << std::endl;
}

int main()
{
	Vector<int> vector1;
	
	printVector(vector1);

	vector1 += 1;
	
	printVector(vector1);

	/*
	int nums[] = {1, 2, 3, 4, 5};
	Array<int> arr1(nums, 5);
	
	for (int i = 0; i < arr1.size(); ++i)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;
	
	SafeArray<float> arr3;		// SafeArray arr3(100);
	SafeArray<double> arr4(10);	// SafeArray arr4 = 10; X
	SafeArray<double> arr5(arr4);
	
	SafeArray<int> arr2(nums, 5);
	
	for (int i = 0; i < arr2.size(); ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	
	try {
		Array<int>* pArr = new SafeArray<int>(arr2);
		(*pArr)[5] = 10;// pArr->operator[](5) = 10;
		
		delete pArr;
	} catch (const InvalidIndex& e) {
		std::cerr << "boundary exception is occured at: " << e.getInvalidIndex() << std::endl;
		
		return 1;
	} 
	*/
	return 0;
}

