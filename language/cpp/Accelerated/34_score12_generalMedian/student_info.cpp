#include <iostream>
#include <vector>

#include "student_info.h"
#include "grade.h"

using std::istream;
using std::vector;
using std::cerr;
using std::endl;





istream& read_hw(istream& in, vector<double>& homework) {
	if (in ) {
		homework.clear();
		
		double d;
		while (in >> d)
			homework.push_back(d);
		
		in.clear();
	}
	
	return in;
}

istream& read(istream& in, Student_info& student) {
	in >> student.name >> student.midterm >> student.final;
	read_hw(in, student.homework);
	
	if (in) {
		student.score = grade(student);
		student.degree = degree(student);
	}
	
	return in;
}

bool compare(const Student_info& lhs, const Student_info& rhs) {
	return lhs.name < rhs.name;
}

