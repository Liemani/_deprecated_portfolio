#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "student_info.h"
#include "grade.h"
#include "median.h"
#include "average.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
using std::back_inserter;
using std::find;
using std::transform;







// function
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
	return !fgrade(s);
}

/*
vector<Student_info> extract_fails(vector<Student_info>& pass) {
	vector<Student_info> fail;
	
	remove_copy_if(pass.begin(), pass.end(), back_inserter(fail), pgrade);
	pass.erase(remove_if(pass.begin(), pass.end(), fgrade), pass.end());
	
	return fail;
}
*/

vector<Student_info> extract_fails(vector<Student_info>& pass) {
	vector<Student_info>::iterator iter = stable_partition(pass.begin(), pass.end(), pgrade);
	
	vector<Student_info> fail(iter, pass.end());
	pass.erase(iter, pass.end());
	
	return fail;
}


int main() {
	vector<Student_info> students;
	
	Student_info s;
	while (read(cin, s)) {
		cout << __LINE__ << endl;
		students.push_back(s);
	}
	
	vector<Student_info> pass = students;
	vector<Student_info> fail = extract_fails(pass);
	
	cout << "** pass: " << endl;
	for (vector<Student_info>::const_iterator iter = pass.begin(); iter != pass.end(); ++iter) {
		cout << iter->name << endl;
	}
	
	cout << "** fail: " << endl;
	for (vector<Student_info>::const_iterator iter = fail.begin(); iter != fail.end(); ++iter) {
		cout << iter->name << endl;
	}
	
	return 0;
}
