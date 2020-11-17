#ifndef PAIR_H
#define PAIR_H

template<typename T, typename U>
struct Pair {
	T key;
	U value;
	
	Pair(T key, U value) { this->key = key; this->value = value; }
};

#endif
