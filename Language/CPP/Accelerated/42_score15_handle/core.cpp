#include <iostream>

#include "grade.h"
#include "core.h"

using std::istream;

bool compare(const Core& lhs, const Core& rhs) {
	return lhs.name() < rhs.name();
}

Core::Core()
: midterm(0.0), final(0.0)
{

}

Core::Core(std::istream& in) {
	this->read(in);
}

Core* Core::clone() const {
	return new Core(*this);
}

istream& Core::read_common(istream& in) {
	in >> this->Core::n >> this->Core::midterm >> this->Core::final;
	
	return in;
}

istream& Core::read_hw(istream& in) {
	if (in ) {
		this->homework.clear();
		
		double d;
		while (in >> d)
			this->homework.push_back(d);
		
		in.clear();
	}
	
	return in;
}

std::istream& Core::read(istream& in) {
	this->read_common(in);
	this->read_hw(in);
	
//	if (in) {
//		this->score = this->grade();
//		this->degree = this->getDegree();
//	}
	
	return in;
}

double Core::grade() const {
	return ::grade(this->midterm, this->final, this->homework);
}

std::string Core::name() const {
	return this->n;
}

