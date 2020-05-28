#pragma once
//********************************************
// char* title = "Set"
// made by Lieman at 2020.05.28
//
// description:
//	Set Structure
//********************************************





// preprocessor
#include <stdlib.h>





// global variable
typedef struct Set {
	void** _set;
	int _count; // calculated time to time

	int (*count)(struct Set* set);

	void (*add)(struct Set* set, void* element);
	void (*remove)(struct Set* set, void* element);

	void (*dealloc)(struct Set* set);
} Set;





// function
int _Set_count(struct Set* set) {

}

void _Set_add(struct Set* set, void* element) {

}

void _Set_remove(struct Set* set, void* element) {

}

void _Set_dealloc(struct Set* set) {
	// deallocate properties
	for (int index = 0; index < set->_count; index++) {

	}

	free(set);
}





// allocation
Set* _Set_alloc() {
	Set* set = (Set*)malloc(sizeof(Set));

	// allocate properties
	set->_set = (void**)malloc(sizeof(void*));

	return set;
}

// initialization
Set* newSet() {
	Set* set = _Set_alloc();

	// initialize properties
	set->_count = 0;

	// initialize methods
	set->count = _Set_count;

	set->add = _Set_add;
	set->remove = _Set_remove;

	set->dealloc = _Set_dealloc;

	return set;
}