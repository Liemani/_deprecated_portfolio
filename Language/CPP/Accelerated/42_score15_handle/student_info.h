#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
 #include <string>    // string
// #include <vector>    // vector
// #include <iostream>    // istream

#include "core.h"

class Student_info {
public:
	static bool compare(const Student_info& lhs, const Student_info& rhs);
	
	Student_info();
	Student_info(std::istream& in);
	Student_info(const Student_info& rhs);
	~Student_info();
	
	Student_info& operator=(const Student_info& rhs);
	
	std::istream& read(std::istream& in);
	
	double grade() const;
//	double grade_aux();
//	double grade_average() const;
//	double grade_optimistic_median();
	
//	char getDegree();
	
	std::string name() const;
	
//	bool valid() const {    // inline function
//		return !this->homework.empty();
//	}
	
private:
	Core *cp;
//	std::string n;
	
//	double score;
	
//	double midterm;
//	double final;
//	std::vector<double> homework;
	
//	char degree;
	
//	std::istream& read_hw(std::istream& in);
};

// std::istream& read(std::istream& in, Student_info& student);

bool compare(const Student_info& lhs, const Student_info& rhs);

#endif

