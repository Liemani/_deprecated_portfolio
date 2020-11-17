#include <cassert>
#include "queue.h"

const int Queue::QUEUESIZE = 100;

Queue::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}

bool Queue::operator==(const Queue& rhs) const
{
	if (front_ != rhs.front_ || rear_ != rhs.rear_) return false;
	
	return arr_ == rhs.arr_;
}

void Queue::push(int data)
{
	assert(rear_ != size());
	arr_[rear_] = data;
	++rear_;
}

int Queue::pop()
{
	assert(front_ != rear_);
	int index = front_;
	++front_;
	return arr_[index];
}

int Queue::size() const
{
	return arr_.size();
}

