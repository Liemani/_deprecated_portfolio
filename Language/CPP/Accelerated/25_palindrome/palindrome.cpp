#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::equal;

/*
template <typename T, typename U>
bool equal(T begin, T end, U begin2) {
	T iter = begin;
	U iter2 = begin2;
	while (iter != end) {
		if (*iter != *iter2) {
			break;
		}
		
		++iter;
		++iter2;
	}
	
	return iter == end;
}
*/

int main() {
	string s = "madam"; // eye level civic
/*
	vector<string> wordVector;
	wordVector.push_back("aaa");
	wordVector.push_back("bbb");
	wordVector.push_back("ccc");
	wordVector.push_back("ddd");
	
	for (vector<string>::const_iterator iter = wordVector.begin(); iter != wordVector.end(); ++iter) {
		cout << *iter << endl;
	}
	
	cout << endl;
	
	for (vector<string>::const_reverse_iterator iter = wordVector.rbegin(); iter != wordVector.rend(); ++iter) {
		cout << *iter << endl;
	}
*/
	
	if (equal(s.begin(), s.end(), s.rbegin())) {
		cout << "This a is palindrome". << endl;
	} else {
		cout << "This is not a palindrome." << endl;
	}
	

	return 0;
}

