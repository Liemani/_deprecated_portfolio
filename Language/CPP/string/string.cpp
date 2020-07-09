#include <cstring>
#include <cassert>
#include "string.h"

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	return out << rhs.str;
}

String::String(const char *str, bool)
{
	this->str = (char *)str;
	this->len = strlen(str);
}

void String::set_str(const char *str)
{
	if (str) {
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		assert(this->str);
		strcpy(this->str, str);
	} else {
		this->len = 0;
		this->str = new char[1];
		assert(this->str);
		this->str[0] = '\0';
	}
}

String::String(const char *str)
{
	this->set_str(str);
}

String::String(const String& rhs)
{
	this->set_str(rhs.str);
}

String::~String()
{
	delete [] this->str;
}

String& String::operator=(const String& rhs)
{
	if (this != &rhs) {
		delete [] this->str;
		this->set_str(rhs.str);
	}
	
	return *this;
}

String& String::operator=(const char* str)
{
	if (this->str != str) {
		delete [] this->str;
		this->set_str(str);	
	}
	
	return *this;
}

bool String::operator==(const String& rhs)
{
	return !strcmp(this->str, rhs.str);
}
/*
const String String::operator+(const String& rhs)
{
	char *buf = new char[this->len + rhs.len + 1];
	strcpy(buf, this->str);
	strcat(buf, rhs.str);
	
	String result(buf);
	delete [] buf;
	
	return result;
}
*/
const String String::operator+(const String& rhs)
{
	char *buf = new char[this->len + rhs.len + 1];
	strcpy(buf, this->str);
	strcat(buf, rhs.str);
	
	String result(buf, true);
	// delete [] buf;
	
	return result;
}

const char* String::c_str()
{
	return this->str;
}

int String::length()
{
	return this->len;
}

