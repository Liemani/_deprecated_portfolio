#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
friend std::istream& operator>>(std::istream& in, Rational& rhs);
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	static int numberOfRational;

	mutable int num_;
	mutable int den_;
public:
	const Rational& reduce() const;		//helper func, tool func
	
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
