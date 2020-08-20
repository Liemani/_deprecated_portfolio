#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include <vector>

#include "pair.h"





struct WordCounter {
	std::vector<Pair<std::string, int>*> pairVector;
	
	void addWord(std::string word);
	void addSentence(std::string sentence);
	std::vector<Pair<std::string, int>*>::size_type size();
	Pair<std::string, int>* operator[](int index);
};

#endif

