#ifndef SHAPE_INCLUDED
#define SHAPE_INCLUDED

#include <cmath>
#include <iostream>
#include <fstream>
#include "Point.h"

// abstract class Shape base of the polymorphism

class Shape
{
public:
	Shape(double = 0, double = 0);
	Shape(const Point&);
	virtual ~Shape();

	void setBase(double, double);
	const Point getBase() const;

	virtual bool withinCircle(Point, double) const = 0;
	virtual bool withinRect(Point, double, double) const = 0;
	virtual void translate(double, double) = 0;

	virtual void print(std::ostream&) const = 0;
	virtual const char* getName() const = 0;
	virtual Shape* clone() const = 0;
	virtual void saveAsSVG(std::ofstream&) const = 0;

protected:
	Point base;
};

#endif // !SHAPE_INCLUDED
