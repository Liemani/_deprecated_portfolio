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
	
	try {
		while (read(cin, student)) {
			maxLen = max(maxLen, student.name.size());
			
			studentVector.push_back(student);
		}
	} catch (domain_error e) {
		cout << e.what() << endl;
		
		return 1;
	}
	
	sort(studentVector.begin(), studentVector.end(), compare);
	
	vector<Student_info>::size_type studentVectorSize = studentVector.size();
	
	for (int i = 0; i < studentVectorSize; ++i) {
		cout << studentVector[i].name << string((maxLen - studentVector[i].name.size() + 1), ' ');
		
		streamsize prec = cout.precision();
		cout << setprecision(3)
			<< studentVector[i].score
			<< setprecision(prec) << endl;
	}
	
	return 0;
}

