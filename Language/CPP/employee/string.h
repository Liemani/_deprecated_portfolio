#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
	char *str;
	int len;
	
	void set_str(const char *str);		// helper func, tool func.
	String(const char *str, bool);
public:
	String(const char *str = NULL);
	String(const String& rhs);
	~String();
	
	const char* c_str();
	int length();
	
	String& operator=(const String& rhs);
	String& operator=(const char* str);
	
	bool operator==(const String& rhs);
	const String operator+(const String& rhs);
};

#endif
