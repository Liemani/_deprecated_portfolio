//********************************************
// char* title = "View.c"
// made by Lieman at 2020.07.10
//
// description:
//	View implementation
//********************************************





// preprocessor
#include <stdio.h>
#include "View.h"





// method
void View__print__SimpleString(SimpleString* simpleString) {
	for (int i = 0; i < simpleString->count; ++i)
		putchar(simpleString->string[i]);

	putchar('\n');
}





// View factory method
