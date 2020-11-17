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
using std::max;
using std::sort;
using std::streamsize;
using std::domain_error;

struct Student_info {
	string name;
	double midterm;
	double final;
	vector<double> homework;
};

double median(vector<double> vect) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vect.size();
	
	if (size == 0)
		throw domain_error("median of an empty vector");
		
	sort(vect.begin(), vect.end());
	
	vec_sz mid = size / 2;
	
	return (size % 2) ? vect[mid] : (vect[mid - 1] + vect[mid]) / 2;
}

double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& homework) {
	if (homework.size() == 0) {
		throw domain_error("student has done no homework");
	}
	
	return grade(midterm, final, median(homework));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
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

istream& read(istream& in, Student_info& s) {
	in >> s.name >> s.midterm >> s.final;
	read_hw(in, s.homework);

	return in;
}

bool compare(const Student_info& lhs, const Student_info& rhs) {
	return lhs.name < rhs.name;
}

int main()
{
	vector<Student_info> studentVector;

	string::size_type maxLen = 0;
	Student_info student;
	while (read(cin, student)) {
		maxLen = max(maxLen, student.name.size());
		
		studentVector.push_back(student);
	}
	
	sort(studentVector.begin(), studentVector.end(), compare);
	
	for (int i = 0; i < studentVector.size(); ++i) {
		cout << studentVector[i].name << string((maxLen - studentVector[i].name.size() + 1), ' ');
		
		try {
			double final_grade = grade(studentVector[i]);
			
			streamsize prec = cout.precision();
			cout << setprecision(3)
				<< final_grade
				<< setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what();
				
			return 1;
		}
	}
	
	return 0;
}
