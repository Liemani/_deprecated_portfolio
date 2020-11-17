#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "student_info.h"
#include "grade.h"
#include "median.h"
#include "average.h"

using std::cerr;
using std::endl;
using std::istream;
using std::string;
using std::vector;
using std::remove_copy;
using std::back_inserter;
using std::domain_error;





istream& Student_info::read_hw(istream& in) {
	if (in ) {
		this->homework.clear();
		
		double d;
		while (in >> d)
			this->homework.push_back(d);
		
		in.clear();
	}
	
	return in;
}

bool compare(const Student_info& lhs, const Student_info& rhs) {
	return lhs.name() < rhs.name();
}

Student_info::Student_info()
: midterm(0.0), final(0.0)
{

}

Student_info::Student_info(std::istream& in) {
	this->read(in);
}

istream& Student_info::read(istream& in) {
	in >> this->n >> this->midterm >> this->final;
	this->read_hw(in);
	
	if (in) {
		this->score = this->grade();
		this->degree = this->getDegree();
	}
	
	return in;
}

string Student_info::name() const {
	return this->n;
}


/*
istream& read(istream& in, Student_info& student) {
	in >> student.name >> student.midterm >> student.final;
	read_hw(in, student.homework);
	
	if (in) {
		student.score = grade(student);
		student.degree = degree(student);
	}
	
	return in;
}
*/

double Student_info::grade() const {
	return ::grade(this->midterm, this->final, median(this->homework));
}

// double grade() {
// 	return ::grade(this->midterm, this->final, this->homework);
// }

double Student_info::grade_aux() {
	try {
		return grade();
	} catch (domain_error) {
		return ::grade(this->midterm, this->final, 0);
	}
}

double Student_info::grade_average() const {
	return ::grade(this->midterm, this->final, ::average(this->homework));
}

double Student_info::grade_optimistic_median() {
	vector<double> nonzero;
	remove_copy(this->homework.begin(), this->homework.end(), back_inserter(nonzero), 0);
	
	if (nonzero.empty()) {
		return ::grade(this->midterm, this->final, 0);
	} else {
		return ::grade(this->midterm, this->final, ::median(nonzero));
	}
}

char Student_info::getDegree() {
	if (this->score >= 90) {
		return 'A';
	} else if (this->score >= 80) {
		return 'B';
	} else if (this->score >= 70) {
		return 'C';
	} else if (this->score >= 60) {
		return 'D';
	} else {
		return 'F';
	}
}






























