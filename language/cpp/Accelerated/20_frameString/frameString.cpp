#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& lines) {
	string::size_type maxLen = 0;

	for (vector<string>::const_iterator iter = lines.begin(); iter != lines.end(); ++iter) {
//		if (iter->size() > maxLen) {
//			maxLen = iter->size();
//		}
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
	
//	for (vector<string>::const_iterator iter = bottom.begin(); iter != bottom.end(); ++iter) {
//		re.push_back(*iter);
//	}
	re.insert(re.end(), bottom.begin(), bottom.end());
	
	
	return re;
}

vector<string> horizontallyConcaternate(const vector<string>& left, const vector<string>& right) {
	vector<string> re;
	
	string::size_type leftWidth = width(left);
	
	const vector<string>::size_type leftRow = left.size();
	const vector<string>::size_type rightRow = right.size();
	
	const vector<string>::size_type totalRow = max(leftRow, rightRow);

/*
	vector<string>::size_type i = 0;
	vector<string>::size_type j = 0;

	while(i != left.size() || j != right.size()) {
		string s;
		
		if (i != left.size()) {
			s = left[i];
			++i;
		}
		
		if (i != left.size()) {
			s += " ";
		} else {
			s += string(width(left) + 1, ' ');
		}
		
		if (j != right.size()) {
			s += right[j];
			++j;
		}
		
		re.push_back(s);
	}
*/

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
	// result = verticallyConcaternate(lines, frameLines);
	result = horizontallyConcaternate(lines, frameLines);
	for (vector<string>::const_iterator iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter << endl;
	}
	
	return 0;
}
