#ifndef LIST_H
#define LIST_H

class Node {
private:
	Node& operator=(const Node& rhs);
public:
	int data;
	Node* next;
	
	Node(int data = -1, Node* next = NULL);
};

class List {
private:
	Node* ptr;
	
	List(const List& rhs);
	List& operator=(const List& rhs);
public:
	List();
	~List();

	void printList() const;

	void insertFirstNode(const int data);
	void insertNode(const int prevData, const int data);
	void deleteNode(const int data);
};

#endif
