#include <iostream>

#include "graduate.h"

using std::istream;
using std::min;

Graduate::Graduate()
: /*Core(static_cast<Core>(*this)), */ thesis(0.0)
{

}

Graduate::Graduate(istream& in) {
	this->read(in);
}

istream& Graduate::read(istream& in) {
	this->Core::read_common(in);
	in >> thesis;
	this->Core::read_hw(in);
	
	return in;
}

double Graduate::grade() const {
	return min(this->Core::grade(), this->thesis);
}

