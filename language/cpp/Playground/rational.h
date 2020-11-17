#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational {
private:
	long num;
	long den;	// keep > 0
	
	long gcd(long, long);	// helper function for normalization
public:
	Rational() : num(0), den(1) { }
	Rational(long n, long d = 1);
	// Rational(const Rational& rhs) : num(rhs.num), den(rhs.den) { }
	// ~Rational() { }
	// Rational& operator=(const Rational& rhs);	// compiler generatred
	Rational& operator=(long rhs);
	
	long numerator(void) const { return num; }
	long denominator(void) const { return den; }
	
	Rational operator+(void) const { return *this; }
	Rational operator-(void) const { return Rational(-num, den); }
	
	const Rational& operator+=(const Rational& rhs);
	const Rational& operator-=(const Rational& rhs);
	const Rational& operator*=(const Rational& rhs);
	const Rational& operator/=(const Rational& rhs);
	
	const Rational& operator+=(long rhs);
	const Rational& operator-=(long rhs);
	const Rational& operator*=(long rhs);
	const Rational& operator/=(long rhs);
	
	const Rational& operator++();
	const Rational  operator++(int);
	const Rational& operator--();
	const Rational  operator--(int);
	
	void testFunction() {
		std::cout << "num: " << num << ", den: " << den << std::endl;
	}
	
	// operator double(void) const { return double (num)/den; }
};

const Rational operator+(const Rational& lhs, const Rational& rhs);
const Rational operator-(const Rational& lhs, const Rational& rhs);
const Rational operator*(const Rational& lhs, const Rational& rhs);
const Rational operator/(const Rational& lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);

ostream& operator<<(ostream& out, const Rational& rhs);

Rational rabs(const Rational& rhs);

/*
compiler generated:
inline Rational& Rational::operator=(const Rational& rhs) {
	num = rhs.num;
	den = rhs.den;
	return *this;
}
*/

inline Rational& Rational::operator=(long rhs) {
	num = rhs;
	den = 1;
	return *this;
}

inline double toDouble(const Rational& rhs) {
	return double(rhs.numerator()) / rhs.denominator();
}

inline long trunc(const Rational& rhs) {
	return rhs.numerator() / rhs.denominator();
}

inline long floor(const Rational& rhs) {
	long q = rhs.numerator() / rhs.denominator();
	return (rhs.numerator() < 0 && rhs.denominator() != 1) ? --q : q;
}

inline long ceil(const Rational& rhs) {
	long q = rhs.numerator() / rhs.denominator();
	return (rhs.numerator() > 0 && rhs.denominator() != 1) ? ++q : q;
}

Rational toRational(double x, int iterations = 5);

#endif
