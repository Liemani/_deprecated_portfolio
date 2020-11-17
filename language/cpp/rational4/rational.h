#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
friend std::istream& operator>>(std::istream& in, Rational& rhs);
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	static const int BLOCK_SIZE;
	static Rational* headOfFreeList;

	static int numberOfRational;
	
	union {
		struct {
			mutable int num_;
			mutable int den_;
		};
		Rational* next;
	};
public:
	static void* operator new(size_t size);
	static void operator delete(void* ptr, size_t size);

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
