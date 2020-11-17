#ifndef STRING_H
#define STRING_H
#include <iostream>

#include "stringRep.h"

class String {
friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
	// char *str;
	// int len;
	StringRep* ptr_;
	
	String(const char* str, bool);
public:
	String(const char *str = NULL);
	String(const String& rhs);
	~String();
	
	String& operator=(const String& rhs);
	String& operator=(const char* str);
	
	bool operator==(const String& rhs) const;
	const String operator+(const String& rhs) const;
	
	const char* c_str() const { return ptr_->str_; }
	int length() const { return ptr_->len_; }
};

inline std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	return out << rhs.c_str();
}

inline String::String(const char* str, bool)
{
	ptr_ = new StringRep(str, true);
	++ptr_->rc_;
	std::cout << "test";
}

inline String::String(const char *str)
{
	if (str) {
		ptr_ = new StringRep(str);
	} else {
		ptr_ = new StringRep();
	}
	
	ptr_->rc_ = 1;
}

inline String::String(const String& rhs)
{
	ptr_ = rhs.ptr_;
	++ptr_->rc_;
}

inline String::~String()
{
	--ptr_->rc_;
	
	if (ptr_->rc_ == 0)
		delete ptr_;
}

#endif
