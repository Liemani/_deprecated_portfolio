#include <iostream>
#include <cassert>
#include "rational.h"

const int Rational::BLOCK_SIZE = 256;
Rational* Rational::headOfFreeList = NULL;

int Rational::numberOfRational;

void* Rational::operator new(size_t size)
{
	if (size != sizeof(Rational))
		return ::operator new(size);


	Rational* ptr = headOfFreeList;
	
	if (ptr) {
		headOfFreeList = ptr->next;
	} else {
		Rational* rationalArray = static_cast<Rational*>(::operator new(BLOCK_SIZE * sizeof(Rational)));
		assert(rationalArray);
		
		for (int i = 1; i < BLOCK_SIZE - 1; ++i)
			rationalArray[i].next = &rationalArray[i + 1];
		
		rationalArray[BLOCK_SIZE - 1].next = NULL;
		
		ptr = rationalArray;
		headOfFreeList = &rationalArray[1];
	}
	
	return ptr;
}

void Rational::operator delete(void* ptr, size_t size)
{
	if (ptr == NULL) return;

	if (size != sizeof(Rational)) {
		::operator delete(ptr);
		return;
	}
	
	Rational* deleteNode = static_cast<Rational*>(ptr);
	
	deleteNode->next = headOfFreeList;
	headOfFreeList = deleteNode;
	
}

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

const Rational& Rational::reduce() const
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
	int num = num_ * rhs.num_;
	int den = den_ * rhs.den_;

	return Rational(num, den);
}

const Rational Rational::operator/(const Rational& rhs)
{
	assert(num_);
	
	int num = num_ * rhs.den_;
	int den = den_ * rhs.num_;

	Rational result(num_ * rhs.den_, den_ * rhs.num_);

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

