#pragma once
//********************************************
// char* title = "Object"
// made by Lieman at 2020.05.28
//
// description:
//	Object Structure
//********************************************





// preprocessor
#include <stdlib.h>





// global variable
typedef struct Object {
	void (*dealloc)(struct Object* object);
} Object;





// function
void _Object_dealloc(struct Object* object) {
	// deallocate properties

	free(object);
}





// allocation
Object* _Object_alloc() {
	Object* object = (Object*)malloc(sizeof(Object));

	// allocate properties

	return object;
}

// initialization
Object* newObject() {
	Object* object = _Object_alloc();

	// initialize properties

	// initialize methods
	object->dealloc = _Object_dealloc;

	return object;
}