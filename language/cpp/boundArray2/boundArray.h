#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
#include "safeArray.h"

template<typename T>
class BoundArray : public SafeArray<T> {
private:
	int lower_;

public:
	BoundArray(int lower, int upper);
	BoundArray(int lower, int upper, const T* pArr);
	//BoundArray(const BoundArray& rhs);		// why?
	//~BoundArray();	// why?
	//operator=();		// why?
	
	bool operator==(const BoundArray<T>& rhs) const;
	
	T& operator[](int index);
	const T& operator[](int index) const;
	
	int lower() const;
	int upper() const;
};

template<typename T>
BoundArray<T>::BoundArray(int lower, int upper)
: SafeArray<T>(upper - lower + 1), lower_(lower)
{

}

template<typename T>
BoundArray<T>::BoundArray(int lower, int upper, const T* pArr)
: SafeArray<T>(pArr + lower, upper - lower + 1), lower_(lower)
{

}

template<typename T>
bool BoundArray<T>::operator==(const BoundArray<T>& rhs) const
{
	if (lower_ != rhs.lower_) return false;
	if (this == &rhs) return true;
	
	return this->SafeArray<T>::operator==(static_cast<SafeArray<T>>(rhs));
}

template<typename T>
T& BoundArray<T>::operator[](int index)
{
	return this->SafeArray<T>::operator[](index - lower_);
}

template<typename T>
const T& BoundArray<T>::operator[](int index) const
{
	return this->SafeArray<T>::operator[](index - lower_);
}

template<typename T>
int BoundArray<T>::lower() const
{
	return lower_;
}

template<typename T>
int BoundArray<T>::upper() const
{
	return lower_ + BoundArray<T>::size_ - 1;
}

#endif
