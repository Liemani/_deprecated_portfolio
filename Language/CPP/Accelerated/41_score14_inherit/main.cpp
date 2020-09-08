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

bool compare_ptr(const Core *pLhs, const Core *pRhs) {
	return ::compare(*pLhs, *pRhs);
}

int main() {
	vector<Core*> students;
	
	Core *pCore;
	string::size_type maxLen = 0;
	
	char ch;
	while (cin >> ch) {
		if (ch == 'U') {
			pCore = new Core;
		} else {
			pCore = new Graduate;
		}
	
		pCore->read(cin);    // virtual
		maxLen = max(maxLen, pCore->name().size());
		students.push_back(pCore);
	}
	
	sort(students.begin(), students.end(), compare_ptr);
	
	for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i]->name() << string(maxLen - students[i]->name().size() + 2, ' ');
		
		try {
			double final_grade = students[i]->grade();    // virtual
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	
	for (vector<Core*>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
		delete *iter;
	}
	
	return 0;
}

