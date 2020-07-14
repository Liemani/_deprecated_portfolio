#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void swap(T& lhs, T& rhs) {
	T tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
/*
void swap(int& lhs, int& rhs) {
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

void swap(double& lhs, double& rhs) {
	double tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
*/
int main()
{
	int a = 100;
	int b = 200;
	
	cout << "a: " << a << ", b: " << b << endl;
	swap(a, b);
	cout << "a: " << a << ", b: " << b << endl;
	
	double x = 1.1;
	double y = 2.2;
	
	cout << "x: " << x << ", y: " << y << endl;
	swap(x, y);
	cout << "x: " << x << ", y: " << y << endl;
	
	return 0;
}
