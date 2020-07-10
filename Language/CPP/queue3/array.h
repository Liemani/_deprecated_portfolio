#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
	static const int ARRAYSIZE;
	
	int *pArr_;
	int size_;
	
	void set_arr(const int* pArr, int size);
public:
	explicit Array(int size = Array::ARRAYSIZE);
	Array(int* pArr, int size);
	Array(const Array& rhs);
	~Array();
	
	Array& operator=(const Array& rhs);
	bool operator==(const Array& rhs) const;
	
	int& operator[](int index);
	const int& operator[](int index) const;
	
	int size() const;
};

#endif
