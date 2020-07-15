#include <cstdlib>	// labs()
#include "rational.h"

long Rational::gcd(long u, long v) {
	long a = labs(u), b = labs(v);
	long tmp;
	
	if (b > a) {
		tmp = a;
		a = b;
		b = tmp;
	}
	
	for (;;) {
		if (b == 0L)
			return a;
		else if (b == 1L)
			return b;
		else {
			tmp = b;
			b = a % b;
			a = tmp;
		}
	}

}

Rational::Rational(long n, long d) { // default values in header!
	if (d == 0L) {
		cerr << "Division by Zero" << endl;;
		exit(1);
	}
	// always keep sign in numerator
	if (d < 0L) {
		n = -n;
		d = -d;
	}
	
	if (n == 0L) {
		num = 0L;
		den = 1L;
	} else {
		// always keep normalized form
		long g = gcd(n, d);
		num = n/g;
		den = d/g;
	}
}

const Rational& Rational::operator+=(const Rational& rhs) {
	long g1 = gcd(den, rhs.den);
	
	if (g1 == 1L) {		// 61% probability!
		num = num * rhs.den + den * rhs.num;
		den = den * rhs.den;
	} else {
		long t = num * (rhs.den / g1) + (den / g1) * rhs.num;
		long g2 = gcd(t, g1);
		num = t / g2;
		den = (den / g1) * (rhs.den / g2);
	}
	
	return *this;
}

const Rational& Rational::operator+=(long rhs) {
	num = num + den * rhs;
	return *this;
}

const Rational operator+(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs) += rhs;
}

const Rational& Rational::operator-=(const Rational& rhs) {
	long g1 = gcd(den, rhs.den);
	
	if (g1 == 1L) {		// 61% probability!
		num = num * rhs.den - den * rhs.num;
		den = den * rhs.den;
	} else {
		long t = num * (rhs.den / g1) - (den / g1) * rhs.num;
		long g2 = gcd(t, g1);
		num = t / g2;
		den = (den / g1) * (rhs.den / g2);
	}
	
	return *this;
}

const Rational& Rational::operator-=(long rhs) {
	num = num - den * rhs;
	return *this;
}

const Rational operator-(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs) -= rhs;
}

const Rational& Rational::operator*=(const Rational& rhs) {
	long g1 = gcd(num, rhs.den);
	long g2 = gcd(den, rhs.num);
	num = (num / g1) * (rhs.num / g2);
	den = (den / g2) * (rhs.den / g1);

	return *this;
}

const Rational& Rational::operator*=(long rhs) {
	long g = gcd(den, rhs);
	num *= rhs / g;
	den /= g;
	return *this;
}

const Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs) *= rhs;
}

const Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs == 0) {
		cerr << "Division by Zero" << endl;
		exit(1);
	}

	long g1 = gcd(num, rhs.num);
	long g2 = gcd(den, rhs.den);
	num = (num / g1) * (rhs.den / g2);
	den = (den / g2) * (rhs.num / g1);
	
	if (den < 0L) {
		num = -num;
		den = -den;
	}

	return *this;
}

const Rational& Rational::operator/=(long rhs) {
	if (rhs == 0L) {
		cerr << "Division by Zero" << endl;
		exit(1);
	}
	
	long g = gcd(num, rhs);
	num /= g;
	den *= den / g;
	
	if (den < 0L) {
		num = -num;
		den = -den;
	}
	
	return *this;
}

const Rational operator/(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs) /= rhs;
}

const Rational& Rational::operator++() {
	return (*this += 1);
}

const Rational& Rational::operator--() {
	return (*this -= 1);
}

const Rational Rational::operator++(int) {
	Rational oldVal = *this;
	++(*this);
	return oldVal;
}

const Rational Rational::operator--(int) {
	Rational oldVal = *this;
	--(*this);
	return oldVal;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	return (lhs.numerator() == rhs.numerator() &&
		lhs.denominator() == rhs.denominator());
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
	return (lhs.numerator() != rhs.numerator() ||
		lhs.denominator() != rhs.denominator());
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return (toDouble(lhs) < toDouble(rhs));
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	return (toDouble(lhs) > toDouble(rhs));
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	return ((lhs < rhs) || (lhs == rhs));
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
	return ((lhs > rhs) || (lhs == rhs));
}

Rational rabs(const Rational& rhs) {
	if (rhs.numerator() < 0) return -rhs;
	else return rhs;
}

ostream& operator<<(ostream& out, const Rational& rhs) {
	if (rhs.denominator() == 1L)
		out << rhs.numerator();
	else {
		out << rhs.numerator() << "/" << rhs.denominator() << endl;
	}
	return out;
}

Rational toRational(double d) {
	int integerPart[4];
	
	for (int i = 0; i < 4; ++i) {
		integerPart[i] = (int)d;
		d = 1 / (d - integerPart[i]);
	}
	
	Rational rational(1, integerPart[3]);
	
	for (int i = 2; i >= 0; --i) {
		rational = Rational(1) / rational;
		rational += integerPart[i];
	}
	
	return rational;
}

