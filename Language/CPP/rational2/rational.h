#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int num;
	int den;
public:
	Rational(int num = 0, int den = 1);
	Rational(const Rational& rhs);
	~Rational();
	
	Rational& operator=(const Rational& rhs);
	
	bool operator==(const Rational& rhs);
	
	Rational& reduce();
	
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
