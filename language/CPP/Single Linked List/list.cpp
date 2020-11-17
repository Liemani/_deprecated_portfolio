#include <iostream>
#include "list.h"

Node::Node(int data, Node* next)
{
	this->data = data;
	this->next = next;
}

List::List()
: ptr(new Node)
{

}

List::~List()
{
	Node* frontPtr = ptr;
	Node* rearPtr = frontPtr->next;
	
	while(rearPtr) {
		delete frontPtr;
		frontPtr = rearPtr;
		rearPtr = frontPtr->next;
	}
	
	delete frontPtr;
}

void List::printList() const
{
	Node* ptr = this->ptr->next;
	while (ptr) {
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
	
	std::cout << std::endl;
}

void List::insertFirstNode(const int data)
{
	Node* tmp = new Node(data, this->ptr->next);
	this->ptr->next = tmp;
}

void List::insertNode(const int prevData, const int data)
{
	Node* ptr = this->ptr->next;
	
	while(ptr)
		if (ptr->data != prevData)
			ptr = ptr->next;
		else
			break;
	
	if (ptr) {
		Node* tmp = new Node(data, ptr->next);
		ptr->next = tmp;
	}
}

void List::deleteNode(const int data)
{
	Node* frontPtr = this->ptr->next;
	Node* rearPtr = frontPtr->next;
	
	while(rearPtr)
		if (rearPtr->data != data) {
			frontPtr = rearPtr;
			rearPtr = frontPtr->next;
		} else {
			break;
		}
	
	if (rearPtr) {
		frontPtr->next = rearPtr->next;
		delete rearPtr;
	}
}

