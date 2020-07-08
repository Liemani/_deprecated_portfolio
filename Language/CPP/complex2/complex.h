#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
	double re;
	double im;
	
public:
	//Complex();						// default constructor
	//Complex(double re);				// convert constructor
	Complex(double re = 0.0, double im = 0.0);
	//Complex(Complex c);				// Complex c = c;
	Complex(const Complex& rhs);		// right hand side // copy constructor
	//Complex(Complex *c);				// Complex c = &c;
	~Complex();							// destructor
	
	//void operator=(Complex c);
	//void operator=(const Complex* pc);
	void operator=(const Complex& rhs);
	
	bool operator==(const Complex& rhs);
	
	const Complex operator+(const Complex& rhs);
	const Complex operator-(const Complex& rhs);
	
	double real();
	double imag();
	
	void real(double re);
	void imag(double im);
};

#endif
