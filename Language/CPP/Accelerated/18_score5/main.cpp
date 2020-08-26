#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

#include "student_info.h"
#include "grade.h"

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::vector;
using std::list;
using std::max;
using std::sort;
using std::streamsize;
using std::domain_error;

// 2020.08.26 start
bool fgrade(const Student_info& student) {
	return student.score < 60;
}

/*
vector<Student_info> extract_fails(vector<Student_info>& studentVector) {
	vector<Student_info> fail;

	vector<Student_info>::size_type i = 0;
	while (i != studentVector.size()) {
		if (fgrade(studentVector[i])) {
			fail.push_back(studentVector[i]);
			studentVector.erase(studentVector.begin() + i);
		} else {
			++i;
		}
	}
	
	return fail;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	
	vector<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	
	return fail;
}
*/

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	
	return fail;
}


// 2020.08.26 end

int main()
{
	vector<Student_info> studentVector;

	string::size_type maxLen = 0;
	Student_info student;
	
	try {
		while (read(cin, student)) {
			maxLen = max(maxLen, student.name.size());
			
			studentVector.push_back(student);
		}
	} catch (domain_error e) {
		cout << e.what() << endl;
		
		return 1;
	}
	
	sort(studentVector.begin(), studentVector.end(), compare);
	
	vector<Student_info>::size_type studentVectorSize = studentVector.size();
	
	for (int i = 0; i < studentVectorSize; ++i) {
		cout << studentVector[i].name << string((maxLen - studentVector[i].name.size() + 1), ' ');
		
		streamsize prec = cout.precision();
		cout << setprecision(3)
			<< studentVector[i].score
			<< setprecision(prec) << endl;
	}
	
	// 2020.08.26
//	vector<Student_info> pass = studentVector;
//	vector<Student_info> fail;
	list<Student_info> pass(studentVector.begin(), studentVector.end());
	list<Student_info> fail = extract_fails(pass);
	
	cout << "pass list: " << endl;
	
//	for (vector<Student_info>::size_type i = 0; i != pass.size(); ++i) {
//		cout << pass[i].name << endl;
//	}
	for (list<Student_info>::const_iterator iterator = pass.begin(); iterator != pass.end(); ++iterator) {
		cout << iterator->name << endl;
	}
	
	cout << "fail list: " << endl;
	
//	for (vector<Student_info>::size_type i = 0; i != pass.size(); ++i) {
//		cout << fail[i].name << endl;
//	}
	for (list<Student_info>::const_iterator iterator = fail.begin(); iterator != fail.end(); ++iterator) {
		cout << iterator->name << endl;
	}
	
	
	return 0;
}

