#include "Point.h"

Point::Point(double X, double Y)
	: x(abs(X))
	, y(abs(Y))
{
}

Point::Point(const Point & other)
{
	copy(other);
}

Point::~Point()
{
}

Point & Point::operator=(const Point & other)
{
	if (this != &other)
	{
		copy(other);
		return *this;
	}
	return *this;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

void Point::setX(double X)
{
	x = abs(X);
}

void Point::setY(double Y)
{
	y = abs(Y);
}

void Point::copy(const Point & other)
{
	x = other.x;
	y = other.y;
}

std::ostream & operator<<(std::ostream & output, const Point & obj)
{
	output << obj.x << " " << obj.y;
	return output;
}

bool operator<(const Point & left, const Point & right)
{
	return left.x < right.x && left.y < right.y;
}

bool operator>(const Point & left, const Point & right)
{
	return !(left < right || left == right);
}

bool operator==(const Point & left, const Point & right)
{
	return abs(left.x - right.x) < EPSILONE && (left.y - right.y) < EPSILONE;
}

bool operator!=(const Point & left, const Point & right)
{
	return !(left == right);
}

bool operator<=(const Point & left, const Point & right)
{
	return left.x <= right.x && left.y <= right.y;
}

bool operator>=(const Point & left, const Point & right)
{
	return left.x >= right.x && left.y >= right.y;
}

double getDistSqrt(const Point & p1, const Point & p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
