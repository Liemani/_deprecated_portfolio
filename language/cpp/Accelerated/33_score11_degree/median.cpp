#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;





double median(vector<double> vect) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vect.size();
	
	if (size == 0)
		throw domain_error("median of an empty vector");
		
	sort(vect.begin(), vect.end());
	
	vec_sz mid = size / 2;
	
	return (size % 2) ? vect[mid] : (vect[mid - 1] + vect[mid]) / 2;
}

