#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>    // string
#include <vector>    // vector
#include <iostream>    // istream





class Student_info {
private:
	std::string n;
	
	double score;
	
	double midterm;
	double final;
	std::vector<double> homework;
	
	char degree;
	
	std::istream& read_hw(std::istream& in);

public:
	Student_info();
	Student_info(std::istream& in);
	
	std::istream& read(std::istream& in);
	
	double grade() const;
	double grade_aux();
	double grade_average() const;
	double grade_optimistic_median();
	
	char getDegree();
	
	std::string name() const;
	
	bool valid() const {    // inline function
		return !this->homework.empty();
	}
};

// std::istream& read(std::istream& in, Student_info& student);

bool compare(const Student_info& lhs, const Student_info& rhs);

#endif

