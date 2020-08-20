#include <iostream>    // cout, cin
#include <string>    // string
#include <vector>    // vector

#include "wordCounter.h"

using std::string;
using std::cout;
using std::vector;
using std::endl;
using std::cin;





int main() {
	WordCounter wordCounter;

	string sentence;
	cout << "Please enter your sentence: ";
	getline(cin, sentence);
	
	wordCounter.addSentence(sentence);
	
	vector<Pair<std::string, int>*>::size_type wordCounterIndex;
	vector<Pair<std::string, int>*>::size_type wordCounterSize = wordCounter.size();
	
	for (wordCounterIndex = 0; wordCounterIndex < wordCounterSize; ++wordCounterIndex) {
		cout << "Word: " << wordCounter[wordCounterIndex]->key << ", Count: " << wordCounter[wordCounterIndex]->value << endl;
	}

	return 0;
}
