#include "boundArray.h"

BoundArray::BoundArray(int lower, int upper)
: SafeArray(upper - lower + 1), lower_(lower)
{

}

BoundArray::BoundArray(int lower, int upper, int* pArr)
: SafeArray(pArr + lower, upper - lower + 1), lower_(lower)
{

}

bool BoundArray::operator==(const BoundArray& rhs) const
{
	if (lower_ != rhs.lower_) return false;
	if (this == &rhs) return true;
	
	return this->SafeArray::operator==(static_cast<SafeArray>(rhs));
}
	
int& BoundArray::operator[](int index)
{
	return this->SafeArray::operator[](index - lower_);
}

const int& BoundArray::operator[](int index) const
{
	return this->SafeArray::operator[](index - lower_);
}

int BoundArray::lower() const
{
	return lower_;
}

int BoundArray::upper() const
{
	return lower_ + size_ - 1;
}

