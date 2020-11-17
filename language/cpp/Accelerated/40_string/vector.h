#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <algorithm>

using std::allocator;
using std::max;
using std::uninitialized_fill;
using std::uninitialized_copy;

template <typename T>
class Vector {
public:
typedef T value_type;
typedef T& reference_type;
typedef const T& const_reference_type;
typedef unsigned int size_type;
typedef T* iterator;
typedef const T* const_iterator;

	Vector();
	explicit Vector(size_type size, const T& val = T());    // explicit:     Vector<int> v2 = 10; X
	Vector(const Vector<T>& rhs);
	Vector(const_iterator begin, const_iterator end);
	~Vector();
	
	Vector<T> operator=(const Vector<T>& rhs);

	T& operator[](int index);
	const T& operator[](int index) const;
	
	void push_back(const T& val);

	size_type size() const;

	iterator begin();
	const_iterator begin() const;
	
	iterator end();
	const_iterator end() const;
	
	void clear();
	
private:
	iterator data;
	iterator avail;
	iterator limit;
	
	allocator<T> alloc;
	
	void grow();
	void unchecked_append(const T& val);
	
	void create();
	void create(size_type size, const T& val);
	void create(const_iterator begin, const_iterator end);
	
	void uncreate();
};

template <typename T>	
void Vector<T>::grow() {
	size_type new_size = max(2 * (this->limit - this->data), long(1));
	// iterator new_data = new T[new_size];
	// iterator new_data = this->alloc(new_size);
	iterator new_data = alloc.allocate(new_size);
	
//	for (size_type i = 0; i < this->avail - this->data; ++i) {
//		new_data[i] = this->data[i];
//	}
	
	iterator new_avail = uninitialized_copy(this->data, this->avail, new_data);
//	uninitialized_copy(new_data, new_data + new_size, this->data);
	
	this->uncreate();
	
//	this->avail = new_data + (this->limit - this->data);
	this->data = new_data;
	this->avail = new_avail;
	this->limit = new_data + new_size;
}

template <typename T>
void Vector<T>::unchecked_append(const T& val) {
	*this->avail = val;
	++this->avail;
}

template <typename T>
void Vector<T>::create() {
	this->data = 0;
	this->avail = 0;
	this->limit = 0;
}

template <typename T>
void Vector<T>::create(size_type size, const T& val) {
	// this->data = new T[size];
	//this->data = this->alloc(size);
	this->data = alloc.allocate(size);
	
//	for (size_type i = 0; i != size; ++i) {
//		//this->data[i] = val;
//		alloc.construct(this->data + i, val);
//	}
	uninitialized_fill(this->data, this->data + size, val);
	
	this->avail = this->data + size;
	this->limit = this->avail;
}

template <typename T>
void Vector<T>::create(const_iterator begin, const_iterator end) {
	size_type size = end - begin;
	// this->data = new T[size];
	// this->data = this->alloc(size);
	this->data = alloc.allocate(size);
	
//	for (size_type i = 0; i != size; ++i) {
//		this->data[i] = begin[i];
//	}
	
	uninitialized_copy(begin, end, this->data);
	
	this->avail = this->data + size;
	this->limit = this->avail;
}

template <typename T>
void Vector<T>::uncreate() {
//	if (this->data) {
//		delete [] this->data;
//	}
	
//	alloc.deallocate(this->data, size)

	if (this->data) {
		iterator iter = this->avail;
		while (iter != this->data) {
			alloc.destroy(--iter);
		}
	}
	
	alloc.deallocate(this->data, this->limit - this->data);
	
	this->data = this->avail = this->limit = 0;
}

template <typename T>
Vector<T>::Vector() {
	this->create();
}

template <typename T>
Vector<T>::Vector(size_type size, const T& val) {
	this->create(size, val);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& rhs) {
	this->create(rhs.begin(), rhs.end());
}

template <typename T>
Vector<T>::Vector(typename Vector<T>::const_iterator begin, typename Vector<T>::const_iterator end) {
	this->create(begin, end);
}

template <typename T>
Vector<T>::~Vector() {
	this->uncreate();
}

template <typename T>
Vector<T> Vector<T>::operator=(const Vector<T>& rhs) {
	if (this != &rhs) {
		this->uncreate();
		
		this->create(rhs.begin(), rhs.end());
	}
	
	return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) {
	return this->data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
	return this->data[index];
}

template <typename T>
void Vector<T>::push_back(const T& val) {
	if (this->avail == this->limit) {
		this->grow();
	}
	
	this->unchecked_append(val);
}

template <typename T>
typename Vector<T>::size_type Vector<T>::size() const {
	return this->avail - this->data;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
	return this->data;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
	return this->data;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
	return this->avail;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const {
	return this->avail;
}

template <typename T>
void Vector<T>::clear() {
	this->uncreate();
}

#endif
