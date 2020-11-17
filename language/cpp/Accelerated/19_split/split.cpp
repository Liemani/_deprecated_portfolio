#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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
