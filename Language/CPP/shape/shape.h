#ifndef SHAPE_H
#define SHAPE_H

class Shape {		// Abstract Base Class(ABC)
protected:
	int x_;
	int y_;
	
private:

public:
	Shape(int x, int y);
	//Shape(const Shape& rhs);
	virtual ~Shape() { }					// become inline function
	//operator=(const Shape& rhs);
	//operator&()
	//operator&();
	
	void move(int offsetX, int offsetY);
	virtual double area() const = 0;		// pure virtual function
};

#endif
