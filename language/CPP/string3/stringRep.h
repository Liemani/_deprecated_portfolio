#ifndef STRINGREP_H
#define STRINGREP_H

class StringRep {	// Rep: representation
friend class String;	// handle-body class
private:
	char *str_;
	int len_;
	int rc_;
	
	
	StringRep();
	StringRep(const char* s, bool);
	
	StringRep(const StringRep& rhs);			// not use
	StringRep& operator=(const StringRep& rhs);	// not use
public:
	StringRep(const char* s);
	~StringRep();
};

#include <cstring>
#include <cassert>

inline StringRep::StringRep()
: str_(new char[1]), len_(1)
{
	assert(str_);
	str_[0] = '\0';
}

inline StringRep::StringRep(const char* s)
: str_(new char[strlen(s) + 1]), len_(strlen(s))
{
	assert(str_);
	strcpy(str_, s);
}

inline StringRep::StringRep(const char* s, bool)
: str_(const_cast<char*>(s)), len_(strlen(s))
{

}

inline StringRep::~StringRep()
{
	delete [] str_;
}

#endif
