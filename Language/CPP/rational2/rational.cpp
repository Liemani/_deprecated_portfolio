#include <cassert>
#include "rational.h"

Rational::Rational(int num, int den)
{
	assert(den != 0);
	
	this->num = num;
	this->den = den;
}

Rational::Rational(const Rational& rhs)
{
	this->num = rhs.num;
	this->den = rhs.den;
}
	
Rational::~Rational()
{

}

Rational& Rational::operator=(const Rational& rhs)
{
	this->num = rhs.num;
	this->den = rhs.den;
	
	return *this;
}

bool Rational::operator==(const Rational& rhs)
{
	return this->num * rhs.den == this->den * rhs.num;
}

Rational& Rational::reduce()
{
	if (this->num == 0) {
		this->den = 1;
		return *this;
	}

	int bigNumber;
	int smallNumber;
	
	if (this->num > this->den) {
		bigNumber = this->num;
		smallNumber = this->den;
	} else {
		bigNumber = this->den;
		smallNumber = this->num;
	}

	int temp = bigNumber % smallNumber;
	
	while (temp) {
		bigNumber = smallNumber;
		smallNumber = temp;
		temp = bigNumber % smallNumber;
	}
	
	this->num /= smallNumber;
	this->den /= smallNumber;
	
	return *this;
}

const Rational Rational::operator+(const Rational& rhs)
{
	int num = this->num * rhs.den + this->den * rhs.num;
	int den = this->den * rhs.den;
	
	return Rational(num, den).reduce();
}

const Rational Rational::operator-(const Rational& rhs)
{
	int num = this->num * rhs.den - this->den * rhs.num;
	int den = this->den * rhs.den;
	
	return Rational(num, den).reduce();
}

const Rational Rational::operator*(const Rational& rhs)
{
	int num = this->num * rhs.num;
	int den = this->den * rhs.den;

	return Rational(num, den).reduce();
}

const Rational Rational::operator/(const Rational& rhs)
{
	assert(rhs.num);
	
	int num = this->num * rhs.den;
	int den = this->den * rhs.num;

	return Rational(num, den).reduce();
}

int Rational::getNum()
{
	return this->num;
}

int Rational::getDen()
{
	return this->den;
}

void Rational::setNum(int num)
{
	this->num = num;
}

void Rational::setDen(int den)
{
	this->den = den;
}

