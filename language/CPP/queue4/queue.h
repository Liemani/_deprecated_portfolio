#ifndef QUEUE_H
#define QUEUE_H
#include <cassert>
#include "array.h"

template<typename T>
class Queue {
private:
	static const int QUEUESIZE;
	
	Array<T> arr_;
	int front_;
	int rear_;
public:
	explicit Queue(int size = Queue<T>::QUEUESIZE);
	
	bool operator==(const Queue<T>& rhs) const;
	
	void push(const T& data);
	const T pop();
	
	int size() const;
};

template<typename T>
const int Queue<T>::QUEUESIZE = 100;

template<typename T>
Queue<T>::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}

template<typename T>
bool Queue<T>::operator==(const Queue<T>& rhs) const
{
	if (front_ != rhs.front_ || rear_ != rhs.rear_) return false;
	
	return arr_ == rhs.arr_;
}

template<typename T>
void Queue<T>::push(const T& data)
{
	assert(rear_ != size());
	arr_[rear_] = data;
	++rear_;
}

template<typename T>
const T Queue<T>::pop()
{
	assert(front_ != rear_);
	int index = front_;
	++front_;
	return arr_[index];
}

template<typename T>
int Queue<T>::size() const
{
	return arr_.size();
}

#endif
