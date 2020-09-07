#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::allocator;

int main() {
/*
	string *pArr = new string[5];
	pArr[0] = string("AAA");
	pArr[1] = string("BBB");
	pArr[2] = string("CCC");
	pArr[3] = string("DDD");
	pArr[4] = string("EEE");
	
	for (int i = 0; i != 5; ++i) {
		cout << pArr[i] << endl;
	}
	
	delete [] pArr;
*/
	
	allocator<string> alloc;
	string *pArr = alloc.allocate(5);
	
	// uninitialized_fill(pArr, pArr + 5, string("hello"));
	
	alloc.construct(pArr, string("AAA"));
	alloc.construct(pArr + 1, string("BBB"));
	alloc.construct(pArr + 2, string("CCC"));
	alloc.construct(pArr + 3, string("DDD"));
	alloc.construct(pArr + 4, string("EEE"));

	// string *pArr2 = alloc.allocate(5);
	// uninitialized_copy(pArr, pArr + 5, pArr2);
	
	for (int i = 0; i != 5; ++i) {
		cout << pArr[i] << endl;
	}
	
	for (int i = 0; i != 5; ++i) {
		alloc.destroy(pArr + i);
		// alloc.destroy(pArr2 + i);
	}
	
	// alloc.deallocate(pArr2, 5);
	alloc.deallocate(pArr, 5);

	return 0;
}

