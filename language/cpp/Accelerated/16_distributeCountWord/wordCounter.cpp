#include <string>
#include <iterator>    // istream_iterator
#include <sstream>    // istringstream

#include "wordCounter.h"
#include "pair.h"

using std::string;
using std::vector;
using std::istringstream;
using std::istream_iterator;

void WordCounter::addWord(string word) {
	vector<Pair<std::string, int>*>::size_type i;
	vector<Pair<std::string, int>*>::size_type pairVectorSize = pairVector.size();
	for (i = 0; i < pairVectorSize; ++i) {
		if (word == pairVector[i]->key) {
			break;
		}
	}
	
	if (i == pairVectorSize) {
		pairVector.push_back(new Pair<std::string, int>(word, 1));
	} else {
		++pairVector[i]->value;
	}
}

void WordCounter::addSentence(string sentence) {
	istringstream iss(sentence);
	vector<string> wordVector(istream_iterator<string>{iss}, istream_iterator<string>());
	
	vector<string>::size_type wordVectorSize = wordVector.size();
	
	for (int i = 0; i < wordVectorSize; ++i) {
		addWord(wordVector[i]);
	}
}

vector<Pair<std::string, int>*>::size_type WordCounter::size() {
	return pairVector.size();
}	

Pair<std::string, int>* WordCounter::operator[](int index) {
	return pairVector[index];
}	

