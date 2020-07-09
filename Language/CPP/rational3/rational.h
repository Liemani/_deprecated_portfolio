#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	static int numberOfRational;

	int num_;
	int den_;
	
	Rational& reduce();		//helper func, tool func
public:
	static int getNumberOfRational();

	Rational(int num = 0, int den = 1);
	Rational(const Rational& rhs);
	~Rational();
	
	bool operator==(const Rational& rhs);
	
	const Rational operator+(const Rational& rhs);
	const Rational operator-(const Rational& rhs);
	const Rational operator*(const Rational& rhs);
	const Rational operator/(const Rational& rhs);
	
	int getNum();
	int getDen();
	
	void setNum(int num);
	void setDen(int den);
};

#endif
