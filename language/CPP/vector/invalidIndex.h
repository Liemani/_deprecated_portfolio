#ifndef INVALIDINDEX_H
#define INVALIDINDEX_H

class InvalidIndex {
private:
	int index_;
public:
	InvalidIndex(int index): index_(index) { }
	
	int getInvalidIndex() const { return index_; }
};

#endif
