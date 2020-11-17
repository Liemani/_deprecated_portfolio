#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::vector;
using std::sort;
using std::streamsize;
using std::domain_error;

double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vect) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vect.size();
	
	if (size == 0)
		throw domain_error("median of an empty vector");
		
	sort(vect.begin(), vect.end());
	
	vec_sz mid = size / 2;
	
	return (size % 2) ? vect[mid] : (vect[mid - 1] + vect[mid]) / 2;
}

double grade(double midterm, double final, const vector<double>& homework) {
	if (homework.size() == 0) {
		throw domain_error("student has done no homework");
	}
	
	return grade(midterm, final, median(homework));
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in ) {
		hw.clear();
		
		double d;
		while (in >> d)
			hw.push_back(d);
		
		in.clear();
	}
	
	return in;
}

int main()
{
	cout << "Please enter your first name: ";

	string name;

	cin >> name;
	cout << "Hello, " << name <<"!" << endl;
	
	cout << "Please enter your midterm and final exam grades: ";

	double midterm;
	double final;

	cin >> midterm >> final;
	
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";
	try {
		vector<double> homework;
		read_hw(cin, homework);
		
		double final_grade = grade(midterm, final, homework);
		
		streamsize prec = cout.precision();
		
		cout << "Your final grade is " << setprecision(3)
			<< final_grade
			<< setprecision(prec) << endl;
	} catch (domain_error) {
		cout << endl << "You must enter your grades. "
			"Please try again" << endl;

		return 1;
	}
	
	return 0;
}
