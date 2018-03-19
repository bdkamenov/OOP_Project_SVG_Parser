#include "Line.h"
#include "Point.h"

Line::Line(double x1, double y1, double x2, double y2)
	: Shape(x1, y1)
	, end(x2, y2)
{
}

Line::Line(const Point & basePoint, const Point & endPoint)
	: Shape(basePoint)
	, end(endPoint)
{
}

Line & Line::operator=(const Line & other)
{
	if (this != &other)
	{
		base = other.base;
		end = other.end;
		return *this;
	}

	return *this;
}

Line::~Line()
{
}

void Line::setEnd(double X, double Y)
{
	end.setX(abs(X));
	end.setY(abs(Y));
}

const Point& Line::getEnd() const
{
	return end;
}

bool Line::withinCircle(Point center, double radius) const
{
	return getDistSqrt(base, center) <= radius*radius &&
		   getDistSqrt(end,center) <= radius*radius;
}

// checks if the points of the line
// are within the points of the rectangle
// Ra > La > Ra && Rb > Lb > Ra

bool Line::withinRect(Point rectBase, double wid, double high) const
{
	Point upper(rectBase.getX() + wid, rectBase.getY() + high);

	return rectBase <= base &&
		   base <= upper &&
		   rectBase <= end &&
		   end <= upper;
}

// translates the line points with given vector

void Line::translate(double horizont, double vertical)
{
	base.setX(base.getX() + horizont);
	base.setY(base.getY() + vertical);

	end.setX(base.getX() + horizont);
	end.setY(base.getY() + vertical);
}

void Line::print(std::ostream& out) const
{
	out << "Line" << " " << base << " " << end << std::endl;
}

Shape * Line::clone() const
{
	return new Line(*this);
}

// outputs the line points in SVG format

void Line::saveAsSVG(std::ofstream & out) const
{
	out << "  <line x1=\"" << base.getX() << "\" y1=\"" << base.getY() << "\" x2=\"" << end.getX() << "\" y2=\"" << end.getY() << "\" />\n";
}

const char * Line::getName() const
{
	return "Line";
}
