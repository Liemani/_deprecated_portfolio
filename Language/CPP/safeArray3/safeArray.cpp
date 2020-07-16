#include <cassert>
#include "safeArray.h"

const int SafeArray::SAFEARRAY_SIZE = 100;

SafeArray::SafeArray(int size)
: Array(size)
{

}

SafeArray::SafeArray(const int *pArr, int size)
: Array((int*)pArr, size)
{

}

SafeArray::SafeArray(const SafeArray& rhs)
: Array((Array)rhs)
{

}

SafeArray::~SafeArray()
{

}

SafeArray& SafeArray::operator=(const SafeArray& rhs)
{
	this->Array::operator=((Array)rhs);
	
	return *this;
}

bool SafeArray::operator==(const SafeArray& rhs) const
{
	return this->Array::operator==((Array)rhs);
}

int& SafeArray::operator[](int index)
{
	assert(0 <= index && index < this->Array::size_);
	
	return this->Array::operator[](index);
}

const int& SafeArray::operator[](int index) const
{
	assert(0 <= index && index < this->Array::size_);
	
	return this->Array::operator[](index);
}
