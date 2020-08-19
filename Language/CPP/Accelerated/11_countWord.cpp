#include <iostream>    // cout, cin
#include <string>    // string, getline()
#include <vector>    // vector
#include <iterator>    // istream_iterator
#include <sstream>    // istringstream

using namespace std;

struct WordCounter {
	string word;
	int count;
	
	WordCounter(string word) { this->word = word; this->count = 1; }
};

int main() {
	string sentence;
	cout << "Please enter your sentence: ";
	getline(cin, sentence);
	
	istringstream iss(sentence);
	vector<string> wordVector((istream_iterator<string>(iss)), istream_iterator<string>());
	
	vector<WordCounter*> wordCounterVector;
	
	vector<string>::size_type wordVectorSize = wordVector.size();
	
	string word;
	vector<WordCounter*>::size_type wordCounterVectorIndex;
		
	for (vector<string>::size_type wordVectorIndex = 0; wordVectorIndex < wordVectorSize; ++wordVectorIndex) {
		word = wordVector[wordVectorIndex];
		
		for (wordCounterVectorIndex = 0; wordCounterVectorIndex < wordCounterVector.size(); ++wordCounterVectorIndex) {
			if (word == wordCounterVector[wordCounterVectorIndex]->word) {
				++wordCounterVector[wordCounterVectorIndex]->count;
				
				break;
			}
		}
		
		if (wordCounterVectorIndex == wordCounterVector.size()) {
			WordCounter* wordCounter = new WordCounter(word);
			wordCounterVector.push_back(wordCounter);
		}
	}
	
	for (wordCounterVectorIndex = 0; wordCounterVectorIndex < wordCounterVector.size(); ++wordCounterVectorIndex) {
		cout << "Word: " << wordCounterVector[wordCounterVectorIndex]->word << ", Count: " << wordCounterVector[wordCounterVectorIndex]->count << endl;
	}

	return 0;
}
