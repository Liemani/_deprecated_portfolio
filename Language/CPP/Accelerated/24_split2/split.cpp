#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;

/*
vector<string> split(const string& sentence) {
	vector<string> wordVector;
	
	string::size_type i = 0;
	string::size_type j;
	while (i != sentence.size()) {
		while (i != sentence.size() && isspace(sentence[i])) ++i;
		
		j = i;
		
		while (j != sentence.size() && !isspace(sentence[j])) ++j;
		
		if (i != j) {
			wordVector.push_back(sentence.substr(i, j - i));
			i = j;
		}
	}
	
	return wordVector;
}
8
*/

bool space(char ch) {
	return isspace(ch);
}

bool not_space(char ch) {
	return !isspace(ch);
}

/*
string::const_iterator find_if(string::const_iterator begin, string::const_iterator end, bool *(f)(char ch)) {
	string::const_iterator it;
	for (it = begin; it != end; ++it)
		if (not_space(*it))
			break;
	
	return it
}
*/

vector<string> split(const string& s) {
	vector<string> re;
	
	string::const_iterator iter = s.begin();
	while (iter != s.end()) {
//		while (iter != s.end() && isspace(*iter)) {
//			++iter;
//		}

		iter = find_if(iter, s.end(), not_space);
				
		string::const_iterator iter2 = iter;
//		while (iter2 != s.end() && !isspace(*iter2)) {
//			++iter2;
//		}
		
		iter2 = find_if(iter2, s.end(), space);
		
		if (iter != iter2) {
			re.push_back(string(iter, iter2));
			iter = iter2;
		}
	}

	return re;
}

int main() {
	string sentence;
	
	while (getline(cin, sentence)) {
		vector<string> wordVector = split(sentence);
		
		for (vector<string>::const_iterator iterator = wordVector.begin(); iterator != wordVector.end(); ++iterator) {
			cout << *iterator << endl;
		}
	}

	return 0;
}
