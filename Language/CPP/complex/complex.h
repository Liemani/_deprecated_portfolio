#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
	double re;
	double im;
	
public:
	Complex();						// default constructor
	Complex(double re);				// convert constructor
	Complex(double re, double im);	// 
	~Complex();
	
	double real();
	double imag();
	
	void real(double re);
	void imag(double im);
};

#endif
