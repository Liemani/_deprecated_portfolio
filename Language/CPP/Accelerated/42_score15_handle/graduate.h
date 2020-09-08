#ifndef GRADUATE_H
#define GRADUATE_H

#include <iostream>

#include "core.h"

class Graduate : public Core {
friend class Student_info;

public:
	Graduate();
	Graduate(std::istream& in);
	
	virtual std::istream& read(std::istream& in);    // actually don't need to write virtual at child class
	
	virtual double grade() const;    // actually don't need to write virtual at child class

protected:
	virtual Graduate* clone() const;

private:
	double thesis;
};

#endif
