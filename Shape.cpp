#include "Shape.h"

Shape::Shape(double x, double y)
	:base(abs(x), abs(y))
{
}

Shape::Shape(const Point & basePoint)
	:base(basePoint)
{
}


Shape::~Shape()
{
}

void Shape::setBase(double X, double Y)
{
	base.setX(abs(X));
	base.setY(abs(Y));
}


const Point Shape::getBase() const
{
	return base;
}
