#include <iostream>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"

void printArea(Shape* ps)
{
	if (typeid(*ps) == typeid(Rectangle)) {		// runtime type indentification (RTTI)
		std::cout << "rectangle ";
		
	} else if (typeid(*ps) == typeid(Circle)) {
		std::cout << "circle ";
		
	}
		
	std::cout << "area: " << ps->area() << std::endl;
}

void printAreaOfShapeArray(Shape** pps, int size)
{
	Shape* ps;
	for (int i = 0; i < size; ++i) {
		ps = *(pps + i);
		
		if (typeid(*ps) == typeid(Rectangle))		// runtime type indentification (RTTI)
			std::cout << "rectangle ";
		else if (typeid(*ps) == typeid(Circle))
			std::cout << "circle ";
			
		std::cout << "area: " << ps->area() << std::endl;
	}
}

int main()
{
	// Shape s(100, 200); X
	Shape* ps = new Rectangle(100, 200, 10, 50);
	
	Circle c(200, 200, 10);
	Shape& r = c;
	
	Shape* shapes[5];
	shapes[0] = new Rectangle(100, 200, 10, 50);
	shapes[1] = new Circle(200, 100, 5);
	shapes[2] = new Rectangle(50, 50, 100, 10);
	shapes[3] = new Rectangle(200, 50, 5, 5);
	shapes[4] = new Circle(200, 200, 10);
	
	for (int i = 0; i < 5; ++i) {
		if (typeid(*shapes[i]) == typeid(Rectangle)) {
			Rectangle* pr = (Rectangle*)shapes[i];
			std::cout << "perimeter: " << pr->perimeter() << std::endl;
		} else if (typeid(*shapes[i]) == typeid(Circle)) {
			Circle* pc = (Circle*)shapes[i];
			std::cout << "circumference: " << pc->circumference() << std::endl;
		}
	}
	
	for (int i = 0; i < 5; ++i)
		printArea(shapes[i]);
	
	printAreaOfShapeArray(shapes, 5);
	
	delete ps;
	
	for (int i = 0; i < 5; ++i)
		delete shapes[i];
	
	return 0;
}
