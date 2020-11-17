#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "student_info.h"
#include "grade.h"

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::vector;
using std::max;
using std::sort;
using std::streamsize;
using std::domain_error;





int main()
{
	vector<Student_info> studentVector;

	string::size_type maxLen = 0;
	Student_info student;
	while (read(cin, student)) {
		maxLen = max(maxLen, student.name.size());
		
		studentVector.push_back(student);
	}
	
	sort(studentVector.begin(), studentVector.end(), compare);
	
	for (int i = 0; i < studentVector.size(); ++i) {
		cout << studentVector[i].name << string((maxLen - studentVector[i].name.size() + 1), ' ');
		
		try {
			double final_grade = grade(studentVector[i]);
			
			streamsize prec = cout.precision();
			cout << setprecision(3)
				<< final_grade
				<< setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what();
				
			return 1;
		}
	}
	
	return 0;
}

