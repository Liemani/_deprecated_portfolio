#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
	map<string, int> wordCounts;
	
	string s;
	while (cin >> s) {
		++wordCounts[s];
	}
	
	for (map<string, int>::const_iterator iter = wordCounts.begin(); iter != wordCounts.end(); ++ iter)
		cout << iter->first << ": " << iter->second << endl;
	
	return 0;
}
