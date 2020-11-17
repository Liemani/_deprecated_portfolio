#include <iostream>
#include "rational.h"

int main() {
	Rational rational1 = Rational();
	
	
	
	Rational rational2(1, 2);
	
	std::cout << rational1 << std::endl;
		
	std::cout << "rational1.numerator(): " << rational1.numerator() << std::endl;
	std::cout << "rational1.denominator(): " << rational1.denominator() << std::endl;
	
	std::cout << rational2 << std::endl;
	
	return 0;
}
