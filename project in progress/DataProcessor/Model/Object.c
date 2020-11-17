//********************************************
// char* title = "Object.c"
// made by Lieman at 2020.07.10
//
// description:
//	Object implementation
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include "Object.h"





// method





// Object factory method
Object* allocObject() {
	Object* object = (Object*)malloc(sizeof(Object));

	return object;
}

Object* newObject__memberwise() {
	Object* object = allocObject();

	// initialize memberwise here...

	return object;
}

Object* newObject__designated() {
	Object* object = allocObject();

	// initialize designated here...

	return object;
}

Object* newObject() {
	Object* object = allocObject();

	// default initialize here...

	return object;
}

void deallocObject(Object* object) {

	// dealloc here...

	free(object);
}