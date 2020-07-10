#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
	static const int QUEUESIZE;

	int* pArr_;
	int size_;
	int front_;
	int rear_;
public:
	explicit Queue(int size = Queue::QUEUESIZE);
	Queue(const Queue& rhs);
	~Queue();
	
	Queue& operator=(const Queue& rhs);
	
	bool operator==(const Queue& rhs) const;
	
	void push(int data);
	int pop();
	
	int size() const;
};

#endif
