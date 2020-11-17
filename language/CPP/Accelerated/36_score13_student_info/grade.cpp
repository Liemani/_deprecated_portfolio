#include <vector>
#include <stdexcept>
// #include <algorithm>

// #include "grade.h"
// #include "student_info.h"
#include "median.h"

using std::vector;
// using std::remove_copy;
using std::domain_error;
// using std::back_inserter;






double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& homework) {
	if (homework.size() == 0) {
		throw domain_error("student has done no homework");
	}
	
	return grade(midterm, final, median(homework));
}

