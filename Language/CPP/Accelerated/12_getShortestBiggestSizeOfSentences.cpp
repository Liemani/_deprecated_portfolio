#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

int main() {
	vector<string> stringVector;
	string inputString;
	
	
	cout << "Please enter your sentences." << endl;
	
	while (getline(cin, inputString)) {
		stringVector.push_back(inputString);
	}
	
	const vector<string>::size_type stringVectorSize = stringVector.size();
	
	if (stringVectorSize == 0) {
		cout << endl << "You must enter even a sentence. "
			"Please try again." << endl;
		
		return 1;
	}
	
	int longestSize = stringVector[0].size();
	int shortestSize = longestSize;
	
	for (int i = 1; i < stringVectorSize; ++i) {
		int stringSize = stringVector[i].size();
		
		// compare and if need assign stringSize to longestSize or shortestSize
		if (stringSize < shortestSize) {
			shortestSize = stringSize;
		} else if (stringSize > longestSize) {
			longestSize = stringSize;
		}
	}
	
	cout << endl;
	cout << "Longest sentence has " << longestSize << " character!" << endl;
	cout << "Shortest sentence has " << shortestSize << " character!" << endl;

	return 0;
}
