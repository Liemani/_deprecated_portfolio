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





int add_Byte(unsigned char lhs, unsigned char rhs, unsigned char carry, unsigned char* result) {
	unsigned short carry = (unsigned short)lhs + (unsigned short)rhs + carry;
	*result = (unsigned char)carry;

	return (int)(carry >> 8);
}