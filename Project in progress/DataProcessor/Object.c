//********************************************
// char* title = "Object.c"
// made by Lieman at 2020.07.07
//
// description:
//	Object implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include "Object.h"





// method





// Object factory method
Object* Object_alloc() {
	Object* object = (Object*)malloc(sizeof(Object));

	// allocate here...

	return object;
}

Object* newObject() {
	Object* object = Object_alloc();

	// initialize here...

	return object;
}

Object* freeObject(Object* object) {

	// free here...

	free(object);
}