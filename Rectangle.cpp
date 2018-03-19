#include "Rectangle.h"


Rectangle::Rectangle(double x, double y, double wid, double high, const char* colour)
	: Shape(x, y)
	, colour(nullptr)
	, width(wid)
	, height(high)
{
	if (wid < 0 || high < 0)
	{
		setWidth(wid);
		setHeight(high);
	}
		setColour(colour);
}

Rectangle::Rectangle(Point & basePoint, double wid, double high, const char* colour)
	: Shape(basePoint)
	, colour(nullptr)
	, width(wid)
	, height(high)
{
	if (wid < 0 || high < 0)
	{
		setWidth(wid);
		setHeight(high);
	}

	setColour(colour);
}

Rectangle::Rectangle(const Rectangle & other)
{
	copyFrom(other);
}

Rectangle & Rectangle::operator=(const Rectangle & other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);

		return *this;
	}
	return *this;
}

Rectangle::~Rectangle()
{
	clear();
}

void Rectangle::setWidth(double newWid)
{
	if (newWid < 0)
		std::cerr << "Can't set negative numbers as width!\nThe value will be made positive!\n";

	width = abs(newWid);
}

void Rectangle::setHeight(double newHigh)
{
	if (newHigh < 0)
		std::cerr << "Can't set negative numbers as heigh!\nThe value will be made positive!\n";

	height = abs(newHigh);
}

void Rectangle::setColour(const char * newColour)
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
	{
		setColour("White");
	}
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getHeight() const
{
	return height;
}

const char * Rectangle::getColour() const
{
	return colour;
}

void Rectangle::translate(double horizont, double vertical)
{
	base.setX(base.getX() + horizont);
	base.setY(base.getY() + vertical);
}

// checks if the distance between 
// the center and the two points 
// of the rectangle is smaller than 
// the radius of the circle

bool Rectangle::withinCircle(Point center, double radius) const
{
	Point secondPoint(base.getX() + width, base.getY() + height);

	return getDistSqrt(base, center) < radius * radius &&
		getDistSqrt(secondPoint, center) < radius * radius;
}

// checks if the points of the
// rectangle are within the
// points of the given rectangle

bool Rectangle::withinRect(Point othBase, double othWid, double othHigh) const
{
	Point othSecondPoint(othBase.getX() + othWid, othBase.getY() + othHigh);

	Point secondPoint(base.getX() + width, base.getY() + height);

	return othBase <= base &&
		base <= othSecondPoint &&
		othBase <= secondPoint &&
		secondPoint <= othSecondPoint;
}

// outputs the line points in SVG format

void Rectangle::saveAsSVG(std::ofstream & out) const
{
	out << "  <rect x=\"" << base.getX() << "\" y=\"" << base.getY() << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << colour << "\" />\n";
}

Shape * Rectangle::clone() const
{
	return new Rectangle(*this);
}

void Rectangle::print(std::ostream& out) const
{
	out << "Rectangle" << " " << base << " " << width << " " << height << " " << colour << std::endl;
}

const char * Rectangle::getName() const
{
	return "Rectangle";
}

void Rectangle::copyFrom(const Rectangle & other)
{
	base = other.base;

	width = other.width;
	height = other.height;

	setColour(other.colour);
}

void Rectangle::clear()
{
	delete[] colour;
	colour = nullptr;
}
