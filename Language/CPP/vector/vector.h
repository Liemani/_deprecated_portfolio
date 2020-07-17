#ifndef VECTOR_H
#define VECTOR_H
#include <cassert>
#include "safeArray.h"

template<typename T>
class Vector: public SafeArray<T> {
private:
	static const int VECTOR_SIZE;
public:
	Vector(int size = VECTOR_SIZE): SafeArray<T>(size) {}
	Vector(const SafeArray<T>& rhs): SafeArray<T>(rhs) {}
	Vector(const T* pArr, int size): SafeArray<T>(pArr, size) {}
	
	Vector<T>& operator+=(const Vector<T>& rhs) {
		assert(SafeArray<T>::size_ == rhs.size_);
		
		for (int i = 0; i < SafeArray<T>::size_; ++i)
 			SafeArray<T>::pArr_[i] += rhs.pArr_[i];
 		
 		return *this;
	}
	
	Vector<T>& operator+=(const T& rhs) {
		for (int i = 0; i < SafeArray<T>::size_; ++i)
			SafeArray<T>::pArr_[i] += rhs;
		
		return *this;
	}
	
	Vector<T> operator+(const Vector& rhs);
	Vector<T> operator+(const T& rhs);
	
};

template<typename T>
const int Vector<T>::VECTOR_SIZE = 100;

template<typename T>
Vector<T> Vector<T>::operator+(const Vector& rhs)
{
	return Vector<T>(*this) += rhs;
}

template<typename T>
Vector<T> Vector<T>::operator+(const T& rhs)
{
	return Vector<T>(*this) += rhs;
}

#endif
