#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>    // setprecision

#include "graduate.h"

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::string;
using std::vector;
using std::sort;
using std::domain_error;
using std::max;
using std::setprecision;

int main() {
	vector<Graduate> students;
	
	Graduate s;
	string::size_type maxLen = 0;
	while (s.read(cin)) {    // read(cin, s)
		maxLen = max(maxLen, s.name().size());
		students.push_back(s);
	}
	
	sort(students.begin(), students.end(), compare);
	
	for (vector<Graduate>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name() << string(maxLen - students[i].name().size() + 2, ' ');
		
		try {
			double final_grade = students[i].grade();    // grade(students[i])
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	
	return 0;
}

