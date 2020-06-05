#pragma once
//********************************************
// char* title = "add_Byte"
// made by Lieman at 2020.06.05
//
// description:
//	add_Byte example
//********************************************





// preprocessor
#include <stdio.h>





unsigned char add_Byte(unsigned char* lhs, unsigned char* rhs, unsigned char* result) {
	unsigned short carry = (unsigned short)*lhs + (unsigned short)*rhs;

	return (unsigned char)(carry >> 8);
}