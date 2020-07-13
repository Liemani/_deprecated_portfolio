#include <iostream>
#include <cstring>
#include <cassert>
#include "string.h"

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	return out << rhs.c_str();
}

String::String(const char* str, bool)
{
	ptr_ = new StringRep(str, true);
	++ptr_->rc_;
	std::cout << "test";
}

String::String(const char *str)
{
	if (str) {
		ptr_ = new StringRep(str);
	} else {
		ptr_ = new StringRep();
	}
	
	ptr_->rc_ = 1;
}

String::String(const String& rhs)
{
	ptr_ = rhs.ptr_;
	++ptr_->rc_;
}

String::~String()
{
	--ptr_->rc_;
	
	if (ptr_->rc_ == 0)
		delete ptr_;
}

String& String::operator=(const String& rhs)
{
	if (ptr_ == rhs.ptr_) return *this;
	
	if (--ptr_->rc_ == 0) delete ptr_;
	
	ptr_ = rhs.ptr_;
	++ptr_->rc_;
	
	return *this;
}

String& String::operator=(const char* str)
{
	if (ptr_->str_ == str) return *this;
	
	--ptr_->rc_;
	
	if (ptr_->rc_ == 0) delete ptr_;
	
	ptr_ = new StringRep(str);
	
	return *this;
}

bool String::operator==(const String& rhs) const
{
	if (ptr_ == rhs.ptr_) return true;
	
	return strcmp(ptr_->str_, rhs.ptr_->str_) == 0;
}

const String String::operator+(const String& rhs) const
{
	char* buf = new char[ptr_->len_ + rhs.ptr_->len_ + 1];
	assert(buf);
	
	strcpy(buf, ptr_->str_);
	strcat(buf, rhs.ptr_->str_);
	
	return String(buf, true);
}

const char* String::c_str() const
{
	return ptr_->str_;
}

int String::length() const
{
	return ptr_->len_;
}

