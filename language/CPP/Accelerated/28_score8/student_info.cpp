#include <iostream>
#include <vector>

#include "student_info.h"
#include "grade.h"

using std::istream;
using std::vector;





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
	double midterm;
	double final;
	vector<double> homework;
	
	in >> student.name >> midterm >> final;
	read_hw(in, homework);
	
	if (in ) {
		student.score = grade(midterm, final, homework);
	}
	
	return in;
}

bool compare(const Student_info& lhs, const Student_info& rhs) {
	return lhs.name < rhs.name;
}

