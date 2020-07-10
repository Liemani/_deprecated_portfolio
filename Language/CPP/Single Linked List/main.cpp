#include <iostream>
#include "list.h"

int main()
{
	List list;

	list.insertFirstNode(4);	// [4]
	list.printList();
	
	list.insertFirstNode(3);	// [3, 4]
	list.printList();
	
	list.insertFirstNode(1);	// [1, 3, 4]
	list.printList();
	
	list.insertNode(1, 2);	// [1, 2, 3, 4]
	list.printList();
	
	list.deleteNode(3);		// [1, 2, 4]
	list.printList();
	
	return 0;
}
