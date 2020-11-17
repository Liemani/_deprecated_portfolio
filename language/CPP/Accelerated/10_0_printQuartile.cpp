// Advanced challenge: add detail quartile

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

#define VECTOR_SIZE 100

using std::vector;
using std::cin;
using std::cout;
using std::sort;
using std::endl;

int main() {
	vector<int> intVector;
	vector<int>::size_type size = VECTOR_SIZE;
	
	std::random_device rd;
	std::mt19937 mersenne(rd());
	
	std::uniform_int_distribution<> number(1, 100);
	
	for (int i = 0; i < size; ++i) {
		intVector.push_back(number(mersenne));
	}
	
	sort(intVector.begin(), intVector.end());
	
/*	for (int i = 0; i < size; ++i) {
		intVector.push_back(rand() % 100);    // 0 ~ 99
	}
	
	sort(intVector.begin(), intVector.end());
*/

	if (size < 3) {
		cout << "Too small size!" << endl;
		return 1;
	}

	cout << "Lower quartile: " << intVector[size / 4] << endl;
	cout << "Middle quartile: " << intVector[size / 2] << endl;
	cout << "Upper quartile: " << intVector[size * 3 / 4] << endl;
	return 0;
}

