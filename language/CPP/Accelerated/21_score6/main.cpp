#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

#ifdef _LIST_
#include <list>
#else
#include <vector>
#endif

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

#ifdef _LIST_
using std::list;
#else
using std::vector;
#endif

using std::max;
using std::sort;
using std::streamsize;
using std::domain_error;

#ifdef _LIST_
typedef list<Student_info> StudentsData;
#else
typedef vector<Student_info> StudentsData;
#endif





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

StudentsData extract_fails(StudentsData& students) {
	StudentsData fail;
	
	StudentsData::iterator iter = students.begin();
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

int main()
{
	StudentsData studentsData;

	string::size_type maxLen = 0;
	Student_info student;
	
	try {
		while (read(cin, student)) {
			maxLen = max(maxLen, student.name.size());
			
			studentsData.push_back(student);
		}
	} catch (domain_error e) {
		cout << e.what() << endl;
		
		return 1;
	}
	
#ifdef _LIST_
	studentsData.sort(compare);
#else
	sort(studentsData.begin(), studentsData.end(), compare);
#endif
	
	StudentsData::size_type studentsDataSize = studentsData.size();
	
	StudentsData::const_iterator endOfStudentsData = studentsData.end();
	for (StudentsData::const_iterator iterator = studentsData.begin(); iterator != endOfStudentsData; ++iterator) {
		cout << iterator->name << string((maxLen - iterator->name.size() + 1), ' ');
		
		streamsize prec = cout.precision();
		cout << setprecision(3)
			<< iterator->score
			<< setprecision(prec) << endl;
	}
	
	StudentsData pass(studentsData.begin(), studentsData.end());
	StudentsData fail = extract_fails(pass);
	
	cout << "pass list: " << endl;
	
//	for (StudentsData::size_type i = 0; i != pass.size(); ++i) {
//		cout << pass[i].name << endl;
//	}
	for (StudentsData::const_iterator iterator = pass.begin(); iterator != pass.end(); ++iterator) {
		cout << iterator->name << endl;
	}
	
	cout << "fail list: " << endl;
	
//	for (vector<Student_info>::size_type i = 0; i != pass.size(); ++i) {
//		cout << fail[i].name << endl;
//	}
	for (StudentsData::const_iterator iterator = fail.begin(); iterator != fail.end(); ++iterator) {
		cout << iterator->name << endl;
	}
		
	return 0;
}

