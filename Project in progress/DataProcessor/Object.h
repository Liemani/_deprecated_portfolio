#pragma once
//********************************************
// char* title = "Object.h"
// made by Lieman at 2020.07.07
//
// description:
//	Object interface
//********************************************





// preprocessor





// structure
typedef struct Object {
	void *nothing;
} Object;





// method





// Object factory method
Object* allocObject();
Object* newObject();
Object* freeObject(Object* object);
