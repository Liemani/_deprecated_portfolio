#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::vector;
using std::sort;
using std::streamsize;

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
	
	double x;
	vector<double> homework;
	
	while (cin >> x) {
		homework.push_back(x);
	}
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	
	if (size == 0) {
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
			
		return 1;
	}
	
	sort(homework.begin(), homework.end());
	
	double median;
	
	vec_sz mid = size / 2;
	
	if (size % 2 /* != 0 */) {
		median = homework[mid];
	} else {
		median = (homework[mid - 1] + homework[mid]) / 2;
	}
	
	
	streamsize prec = cout.precision();
	
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
}
