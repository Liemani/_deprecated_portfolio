#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::copy;

/*
template <typename T, typename U>
bool my_equal(const T b, const T e, const U d) {
	T iter1 = b;
	U iter2 = d;
	
	while (iter1 != e) {
		if (*iter1 != *iter2) {
			break;
		}
		
		++iter1;
		++iter2;
	}
	
	return iter1 == e;
}
*/

template <typename T>
bool my_equal(T b, T e, T d) {
	while (b != e) {
		if (*b != *d)
			break;
			
		++b;
		++d;
	}
	
	return b == e;
}


template <typename T, typename U>
T my_search(const T b, const T e, const U b2, const U e2) {
	T iter1 = b;
	T iter2;
	T iter3;
	
	while (iter1 != e) {
		if (*iter1 == *b2) {
			iter2 = iter1;
			iter3 = b2;
			
			while (iter3 != e2) {
				if (*iter1 != *iter3) {
					break;
				}
				
				++iter2;
				++iter3;
			}
			
			if (iter3 == e2) {
				break;
			}
		}
		
		++iter1;
	}
	
	return iter1;
}

/*
template <typename T, typename U>
T my_find(const T b, const T e, const U& t) {
	T iter = b;

	while (iter != e) {
		if (*iter == t) {
 			break;
		}
		
		++iter;		
	}
	
	return iter;
}
*/

template <typename In, typename T>
In my_find(In begin, In end, const T& value) {
	while(begin != end) {
		if (*begin == value)
			break;
		++begin;		
	}
			
	return begin;
}

/*
template <typename T, typename U>
T my_find_if(const T b, const T e, const U p) {
	T iter = b;

	while (iter != e) {
		if (p(*iter)) {
 			break;
		}
		
		++iter;		
	}
	
	return iter;
}
*/

template <typename In, typename Pred>
In my_find_if(In begin, In end, Pred predict) {
	while (begin != end) {
		if (predict(*begin))
			break;
			
		++begin;
	}
			
			
	return begin;
}

/*
template <typename T, typename U>
U my_copy(T b, T e, U d) {
	U re = d;

	for (T iter = b; iter != e; ++iter) {
		re.push_back(*iter);
	}
	
	return re;
}
*/

template <typename T, typename U, typename V>
U my_remove_copy(const T b, const T e, const U d, const V& t) {
	U re = d;

	for (T iter = b; iter != e; ++iter) {
		if (*iter != t) {
			re.push_back(*iter);
		}
	}
	
	return re;
}

template <typename T, typename U, typename V>
U my_remove_copy_if(const T b, const T e, const U d, const V p) {
	U re = d;

	for (T iter = b; iter != e; ++iter) {
		if (p(*iter)) {
			re.push_back(*iter);
		}
	}
	
	return re;
}

template <typename T, typename U>
T my_remove(const T b, const T e, const U& t) {
	T iter = b;
	
	while (iter != e) {
		if (*(iter + 1) == t) {
			(iter + 1).my_remove();
		}
		
		++iter;
	}
	
	return iter;
}

/*
template <typename T, typename U, typename V>
U my_transform(const T b, const T e, const U d, const V f) {
	U re = d;
	
	for (T iter = b; iter != e; ++iter) {
		re.push_back(f(*iter));
	}
	
	return re;
}
*/

template <typename In, typename Out, typename Op>
Out my_transform(In begin, In end, Out des, Op func) {
	while (begin != end)
		*des++ = func(*begin++);
	
	return des;
}

template <typename T, typename U>
T my_partition(const T b, const T e, const U p) {
	T iter1 = b;
	T iter2 = e - 1;
	
	while (iter1 != iter2) {
		if (iter1 != iter2 && p(*iter1)) {
			++iter1;
		}
		
		if (iter1 != iter2 && p(*iter2)) {
			--iter2;
		}
		
		if (iter1 != iter2) {
			swap(iter1, iter2);
		}
	}
	
	return iter1;
}

template <typename T, typename U >
U my_accumulate(const T b, const T e, const U& t) {
	U re = t;
	
	for (T iter = b; iter != e; ++iter) {
		re += *iter;
	}
	
	return re;
}

bool greaterThenFour(int value) {
	return value > 4;
}

int square(int value) {
	return value * value;
}

int main() {
	int nums[] = {1, 2, 3, 4, 5};
	vector<int> vec(nums, nums + 5);
	vector<int> vec2 = vec;
	
	if (my_equal(vec.begin(), vec.end(), vec2.begin())) {
		cout << "vec and vec2 are my_equal" << endl;
	} else {
		cout << "vec and vec2 are not my_equal" << endl;
	}
	
	if (my_find(vec.begin(), vec.end(), 3) != vec.end())
		cout << "3 is found" << endl;
	else
		cout << "3 is not found" << endl;

	if (my_find_if(vec.begin(), vec.end(), greaterThenFour) != vec.end())
		cout << "The element is exist greater then 4" << endl;
	else
		cout << "The element is not exist greater then 4" << endl;

	my_transform(vec.begin(), vec.end(), vec2.begin(), square);
	
//	for (vector<int>::const_iterator iter = vec2.begin(); iter != vec2.end(); ++iter)
//		cout << *iter << endl;
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, endl));


	return 0;
}

