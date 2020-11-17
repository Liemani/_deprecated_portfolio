#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <vector>

class Core;

bool compare(const Core& lhs, const Core& rhs);

class Core {
public:
	Core();
	Core(std::istream& in);
	virtual ~Core() { }
	
	virtual std::istream& read(std::istream&);
	
	virtual double grade() const;
	std::string name() const;

protected:
	double midterm;
	double final;
	std::vector<double> homework;
	
	std::istream& read_common(std::istream& in);
	std::istream& read_hw(std::istream& in);

private:
	std::string n;
};

#endif
