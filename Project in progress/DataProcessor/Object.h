#pragma once
//********************************************
// char* title = "Object"
// made by Lieman at 2020.07.06
//
// description:
//	Object
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()





// structure
typedef struct Object {
} Object;





// method
void method() {

}





// Object factory
Object* _Object_alloc() {
	Object* object = (Object*)malloc(sizeof(Object));

	// allocate here...

	return object;
}

Object* newObject() {
	Object* object = _Object_alloc();

	// initialize here...

	return object;
}

Object* freeObject(Object* object) {
	free(object);
}