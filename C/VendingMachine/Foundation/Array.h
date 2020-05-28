#pragma once
//********************************************
// char* title = "Array"
// made by Lieman at 2020.05.28
//
// description:
//	Array Structure
//********************************************





// preprocessor
#include <stdlib.h>
#include "Bool.h"





// global variable
typedef struct Array {
	void** _array;
	int count;

	void* (*subscript)(struct Array* array, int index);
	void (*append)(struct Array* array, void* element);
	void (*insert)(struct Array* array, void* element, int index);
	void* (*remove)(struct Array* array, int index);
	int (*firstIndex)(struct Array* array, void* element);
	void (*swapAt)(struct Array* array, int lhsIndex, int rhsIndex);

	void (*dealloc)(struct Array* array);
} Array;





// function
/// private function
int _Array_isIndexIn(struct Array* array, int index) {
	return array->count <= index ? FALSE : TRUE;
}

void* _Array_subscript(struct Array* array, int index) {
	if (!_Array_isIndexIn(array, index)) return NULL;

	return array->_array[index];
}

void _Array_append(struct Array* array, void* element) {
	array->_array = (void**)realloc(array->_array, sizeof(void*) * (array->count + 1)); // overflow problem
	array->_array[array->count] = element;
	array->count++;
}

void _Array_insert(struct Array* array, void* element, int index) {
	if (!_Array_isIndexIn(array, index)) return;

	array->_array[index] = element;
}

void* _Array_remove(struct Array* array, int index) {
	if (!_Array_isIndexIn(array, index)) return NULL;

	array->count--;

	void* removedElement = array->_array[index];

	for (int secondIndex = index; secondIndex < array->count; secondIndex++) {
		array->_array[secondIndex] = array->_array[secondIndex + 1];
	}

	array->_array = (void**)realloc(array->_array, sizeof(void*) * array->count); // if return value is NULL, array->_array will be leak

	return removedElement;
}

int _Array_firstIndex(struct Array* array, void* element) {

}

void _Array_swapAt(struct Array* array, int lhsIndex, int rhsIndex) {

}

void _Array_dealloc(struct Array* array) {
	// deallocate properties
	for (int index = 0; index < array->count; index++) {
		void* element = array->_array[index];
		if (element != NULL) {
			free(element);
		}
	}

	free(array->_array);
	free(array);
}





// allocation
Array* _Array_alloc() {
	Array* array = (Array*)malloc(sizeof(Array));

	// allocate properties
	array->_array = (void**)malloc(sizeof(void*));

	return array;
}

// initialization
Array* newArray() {
	Array* array = _Array_alloc();

	// initialize properties
	array->count = 0;

	// initialize methods
	array->dealloc = _Array_dealloc;

	return array;
}