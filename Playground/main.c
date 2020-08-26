#include <stdio.h>

int add_int(int x1, int x2) {
	return x1 + x2;
}

int sub_int(int x1, int x2) {
	return x1 - x2;
}

int mul_int(int x1, int x2) {
	return x1 * x2;
}

int div_int(int x1, int x2) {
	return x1 / x2;
}

int rem_int(int x1, int x2) {
	return x1 % x2;
}

int shi_int(int x1) {
	return x1 >> 1;
}

int shi2_int(int x1) {
	return x1 >> 2;
}



double add_double(double x1, double x2) {
	return x1 + x2;
}

double sub_double(double x1, double x2) {
	return x1 - x2;
}

double mul_double(double x1, double x2) {
	return x1 * x2;
}

double div_double(double x1, double x2) {
	return x1 / x2;
}

int main(void) {
	int a_int = 10;
	int b_int = 3;
	
	double a_double = 10.0;
	double b_double = 3.0;
	
	add_int(a_int, b_int);
	sub_int(a_int, b_int);
	mul_int(a_int, b_int);
	div_int(a_int, b_int);
	rem_int(a_int, b_int);
	
	shi_int(a_int);
	shi2_int(a_int);
	
	add_double(a_double, b_double);
	sub_double(a_double, b_double);
	mul_double(a_double, b_double);
	div_double(a_double, b_double);

	return 0;
}
