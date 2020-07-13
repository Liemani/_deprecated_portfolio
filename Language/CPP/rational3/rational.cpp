#include <iostream>
#include <cassert>
#include "rational.h"

int Rational::numberOfRational;

std::istream& operator>>(std::istream& in, Rational& rhs)
{
	int num = 0;
	int den = 1;
	
	in >> num;
	if (in.peek() == '/') {
		in.ignore();
		in >> den;
	}
	
	if (in)
		rhs = Rational(num, den);
	
	return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
	out << rhs.num_ << "/" << rhs.den_;
	return out;
}

int Rational::getNumberOfRational()
{
	return Rational::numberOfRational;
}

Rational::Rational(int num, int den)
{
	assert(den != 0);
	
	num_ = num;
	den_ = den;
	
	this->reduce();
	
	++Rational::numberOfRational;
}

Rational::Rational(const Rational& rhs)
: num_(rhs.num_), den_(rhs.den_)
{
	++Rational::numberOfRational;
}

Rational::~Rational()
{
	--Rational::numberOfRational;
}

bool Rational::operator==(const Rational& rhs)
{
	return num_ == num_ && den_ == den_;
}

Rational& Rational::reduce()
{
	if (num_ == 0) {
		den_ = 1;
		return *this;
	}

	int bigNumber;
	int smallNumber;
	
	if (num_ > den_) {
		bigNumber = num_;
		smallNumber = den_;
	} else {
		bigNumber = den_;
		smallNumber = num_;
	}

	int temp = bigNumber % smallNumber;
	
	while (temp) {
		bigNumber = smallNumber;
		smallNumber = temp;
		temp = bigNumber % smallNumber;
	}
	
	num_ /= smallNumber;
	den_ /= smallNumber;
	
	return *this;
}

const Rational Rational::operator+(const Rational& rhs)
{
	int num = num_ * den_ + den_ * num_;
	int den = den_ * den_;
	
	return Rational(num, den);
}

const Rational Rational::operator-(const Rational& rhs)
{
	int num = num_ * den_ - den_ * num_;
	int den = den_ * den_;
	
	return Rational(num, den);
}

const Rational Rational::operator*(const Rational& rhs)
{
	int num = num_ * num_;
	int den = den_ * den_;

	return Rational(num, den);
}

const Rational Rational::operator/(const Rational& rhs)
{
	assert(num_);
	
	int num = num_ * den_;
	int den = den_ * num_;

	return Rational(num, den);
}

int Rational::getNum()
{
	return num_;
}

int Rational::getDen()
{
	return den_;
}

void Rational::setNum(int num)
{
	num_ = num;
}

void Rational::setDen(int den)
{
	den_ = den;
}

