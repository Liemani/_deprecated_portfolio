#include <cassert>
#include "queue.h"

const int Queue::QUEUESIZE = 100;

Queue::Queue(int size)
: pArr_(new int[size]), size_(size), front_(0), rear_(0)
{
	assert(pArr_);
}

Queue::Queue(const Queue& rhs)
: pArr_(new int[rhs.size_]), size_(rhs.size_), front_(rhs.front_), rear_(rhs.rear_)
{
	assert(pArr_);
	
	for (int i = front_; i < rear_; ++i)
		pArr_[i] = rhs.pArr_[i];
}

Queue::~Queue()
{
	delete [] pArr_;
}

Queue& Queue::operator=(const Queue& rhs)
{
	if (this == &rhs) return *this;
	
	delete [] pArr_;
	
	pArr_ = new int[rhs.size_];
	assert(pArr_);
	size_ = rhs.size_;
	front_ = rhs.front_;
	rear_ = rhs.rear_;
	
	for (int i = front_; i < rear_; ++i)
		pArr_[i] = rhs.pArr_[i];
	
	return *this;
}

bool Queue::operator==(const Queue& rhs) const
{
	if (size_ != rhs.size_ || front_ != rhs.front_ || rear_ != rhs.rear_) return false;
	
	int i;
	for (i = 0; i < size_; ++i)
		if (pArr_[i] != rhs.pArr_[i])
			break;
	
	return i == size_;
}

void Queue::push(int data)
{
	assert(rear_ != size_);
	
	pArr_[rear_] = data;
	++rear_;
}

int Queue::pop()
{
	assert(front_ != rear_);
	
	int index = front_;
	++front_;
	return pArr_[index];
}

int Queue::size() const {
	return size_;
}

