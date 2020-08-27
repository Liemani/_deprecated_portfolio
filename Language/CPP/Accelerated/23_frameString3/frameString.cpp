#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
using std::copy;
using std::back_inserter;

string::size_type width(const vector<string>& lines) {
	string::size_type maxLen = 0;

	for (vector<string>::const_iterator iter = lines.begin(); iter != lines.end(); ++iter) {
		maxLen = max(maxLen, iter->size());
	}
	
	return maxLen;
}

vector<string> frame(const vector<string>& lines) {
	vector<string> re;
	
	string::size_type maxLen = width(lines);
	
	string border = string(maxLen + 4, '*');
	
	re.push_back(border);
	
	for (vector<string>::const_iterator iter = lines.begin(); iter != lines.end(); ++iter) {
		re.push_back("* " + *iter + string(maxLen - iter->size(), ' ') + " *");
	}
	
	re.push_back(border);
	
	return re;
}

vector<string> verticallyConcaternate(const vector<string>& top, const vector<string>& bottom) {
	vector<string> re;
	
	re = top;
	
//	re.insert(re.end(), bottom.begin(), bottom.end());
	copy(bottom.begin(), bottom.end(), back_inserter(re));
	
	return re;
}

vector<string> horizontallyConcaternate(const vector<string>& left, const vector<string>& right) {
	vector<string> re;
	
	string::size_type leftWidth = width(left);
	
	const vector<string>::size_type leftRow = left.size();
	const vector<string>::size_type rightRow = right.size();
	
	const vector<string>::size_type totalRow = max(leftRow, rightRow);

	for (vector<string>::size_type row = 0; row < totalRow; ++row) {
		string leftString;
		string rightString;
	
		if (leftRow > row ) {
			leftString = left[row] + string(leftWidth - left[row].size(), ' ');
		} else {
			leftString = string(leftWidth, ' ');
		}
		
		if (rightRow > row) {
			rightString = right[row];
		} else {
			rightString = "";
		}
	
		re.push_back(leftString + " " + rightString);
	}
	
	return re;
}

vector<string> center(const vector<string>& stringVector, string::size_type width) {
	vector<string> centeredStringVector;
	
	vector<string>::size_type stringVectorSize = stringVector.size();
	for (vector<string>::size_type row = 0; row < stringVectorSize; ++row) {
		vector<string>::size_type spaceSize = (width - stringVector[row].size()) / 2;
		
		centeredStringVector.push_back(string(spaceSize, ' ') + stringVector[row] + string(spaceSize, ' '));
	}
	
	return centeredStringVector;
}

int main() {
	vector<string> lines;
	
	string s;
	while (getline(cin, s)) {
		lines.push_back(s);
		
	}
	
	vector<string> frameLines;
	frameLines = frame(lines);
	
	for (vector<string>::const_iterator iter = frameLines.begin(); iter != frameLines.end(); ++iter) {
		cout << *iter << endl;
	}
	
	vector<string> result;
	result = horizontallyConcaternate(lines, frameLines);
	for (vector<string>::const_iterator iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter << endl;
	}
	
	vector<string> centeredFrameLines = center(frameLines, 100);
	vector<string>::size_type sizeOfCenteredFrameLines = centeredFrameLines.size();
	for (vector<string>::size_type i = 0; i < sizeOfCenteredFrameLines; ++i) {
		cout << centeredFrameLines[i] << endl;
	}
	
	vector<string> centeredResult = center(result, 100);
	vector<string>::size_type sizeOfResult = centeredResult.size();
	for (vector<string>::size_type i = 0; i < sizeOfResult; ++i) {
		cout << centeredResult[i] << endl;
	}
	
	return 0;
}
