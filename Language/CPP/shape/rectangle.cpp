#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h)
: Shape(x, y), width_(w), height_(h)
{

}

double Rectangle::area() const
{
	return width_ * height_;
}

int Rectangle::perimeter() const
{
	return (width_ + height_) * 2;
}
