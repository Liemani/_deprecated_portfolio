#include <iostream>
#include <string>
#include <vector>
#include <map>
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
using std::map;
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

vector<Student_info> extract_fails(vector<Student_info>& pass) {
	vector<Student_info>::iterator iter = stable_partition(pass.begin(), pass.end(), pgrade);
	
	vector<Student_info> fail(iter, pass.end());
	pass.erase(iter, pass.end());
	
	return fail;
}


int main() {
	map<char, vector<string> > degreeMap;
	vector<Student_info> students;
	
	Student_info s;
	while (read(cin, s)) {
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
	
	for (vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
		degreeMap[iter->degree].push_back(iter->name);
	}
	
	for (map<char, vector<string> >::const_iterator iter = degreeMap.begin(); iter != degreeMap.end(); ++iter) {
		cout << iter->first << ": ";
		
		for (vector<string>::const_iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2) {
			cout << *iter2 << (iter2 + 1 != iter->second.end() ? ", ": "");
		}
		
		cout << endl;
	}
	
	
	
	return 0;
}
