#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>    // string
#include <vector>    // vector
#include <iostream>    // istream





struct Student_info {
	int id;
	std::string name;
	
	double score;
	
	double midterm;
	double final;
	std::vector<double> homework;
};

std::istream& read_hw(std::istream& in, std::vector<double>& homework);
std::istream& read(std::istream& in, Student_info& student);

bool compare(const Student_info& lhs, const Student_info& rhs);

#endif

