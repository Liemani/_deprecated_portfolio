#ifndef LIST_H
#define LIST_H
#include <iostream>

class Node {
friend class List;
private:
	int data;
	Node* next;
	
	Node(int data, const Node *next);
	
	Node(const Node& rhs);				// not use
	Node& operator=(const Node& rhs);	// not use
	
public:
	//~Node();
	//Node* operator&();
	//const Node* operator&() const;
};

class List {
friend std::ostream& operator<<(std::ostream& out, const List& rhs);

private:
	Node *ptr;
	
	void print(std::ostream& out) const;
	
	List(const List& rhs);
	List& operator=(const List& rhs);
	
public:
	List();
	~List();

	void insertFirstNode(int data);
	void insertNode(int prevData, int data);
	void deleteNode(int data);
};

#endif
