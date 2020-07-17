#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include <cassert>
#include "array.h"

template<typename T>
class SafeArray : public Array<T> {
private:
	static const int SAFEARRAY_SIZE;
public:
	explicit SafeArray(int size = SafeArray<T>::SAFEARRAY_SIZE);
	SafeArray(const T *pArr, int size);
	SafeArray(const SafeArray<T>& rhs);
	virtual ~SafeArray();
	
	SafeArray<T>& operator=(const SafeArray<T>& rhs);
	
	bool operator==(const SafeArray<T>& rhs) const;
	
	virtual T& operator[](int index);
	virtual const T& operator[](int index) const;
};

template<typename T>
const int SafeArray<T>::SAFEARRAY_SIZE = 100;

template<typename T>
SafeArray<T>::SafeArray(int size)
: Array<T>(size)
{

}

template<typename T>
SafeArray<T>::SafeArray(const T *pArr, int size)
: Array<T>((T*)pArr, size)
{

}

template<typename T>
SafeArray<T>::SafeArray(const SafeArray<T>& rhs)
: Array<T>(static_cast<Array<T>>(rhs))
{

}

template<typename T>
SafeArray<T>::~SafeArray()
{

}

template<typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& rhs)
{
	this->Array<T>::operator=(static_cast<Array<T>>(rhs));
	
	return *this;
}

template<typename T>
bool SafeArray<T>::operator==(const SafeArray<T>& rhs) const
{
	return this->Array<T>::operator==(static_cast<Array<T>>(rhs));
}

template<typename T>
T& SafeArray<T>::operator[](int index)
{
	assert(0 <= index && index < this->Array<T>::size_);
	
	return this->Array<T>::operator[](index);
}

template<typename T>
const T& SafeArray<T>::operator[](int index) const
{
	assert(0 <= index && index < this->Array<T>::size_);
	
	return this->Array<T>::operator[](index);
}

#endif
