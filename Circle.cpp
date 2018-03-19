#include "Circle.h"


Circle::Circle(double x, double y, double rad, const char* colour)
	: Shape(x, y)
	, radius(rad)
{
	if (rad < 0)
		setRadius(rad);

	setColour(colour);
}

Circle::Circle(const Point & center, double rad, const char * colour)
	: Shape(center)
	, radius(rad)
{
	if (rad < 0)
		setRadius(rad);

	setColour(colour);
}

Circle & Circle::operator=(const Circle & other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);
		return *this;
	}

	return *this;
}

Circle::Circle(const Circle & other)
{
	copyFrom(other);
}

Circle::~Circle()
{
	clear();
}

void Circle::setRadius(double newRad)
{
	if (newRad < 0)
		std::cerr << "Can't set negative numbers as radius!\nThe value will be made positive!\n";

	radius = abs(newRad);
}

void Circle::setColour(const char * newColour)
{
	if (newColour)
	{
		size_t len = strlen(newColour) + 1;
		char * buff = new char[len];
		strcpy_s(buff, len, newColour);

		delete[] colour;

		colour = buff;

		return;
	}
	else
		setColour("White");
}

double Circle::getRadius() const
{
	return radius;
}

const char * Circle::getColour() const
{
	return colour;
}

const char * Circle::getName() const
{
	return "Circle";
}

void Circle::print(std::ostream & out) const
{
	out << "Circle" << " " << base << " " << radius << " " << colour << std::endl;
}

void Circle::translate(double horizont, double vertical)
{
	base.setX(base.getX() + horizont);
	base.setY(base.getY() + vertical);
}

// checks if the distance between 
// the centers is smaller than 
// r1 - r2

bool Circle::withinCircle(Point center, double radius) const
{
	return getDistSqrt(base, center) <= (radius - this->radius)*(radius - this->radius);
}

// checks if the circle ends are 
// within the points of the rect

bool Circle::withinRect(Point rectBase, double wid, double high) const
{
	return Point(base.getX() - radius, base.getY() - radius) > rectBase &&
		   Point(base.getX() - radius, base.getY() - radius) < Point(rectBase.getX() + wid, rectBase.getY() + high);
}

void Circle::saveAsSVG(std::ofstream & out) const
{
	out << "  <circle cx=\"" << base.getX() << "\" cy=\"" << base.getY() << "\" r=\"" << radius << "\" fill=\"" << colour << "\" />\n";
}

Shape * Circle::clone() const
{
	return new Circle(*this);
}

void Circle::copyFrom(const Circle & other)
{
	base = other.base;
	radius = other.radius;

	setColour(other.colour);
}

void Circle::clear()
{
	delete[] colour;
	colour = nullptr;
}

