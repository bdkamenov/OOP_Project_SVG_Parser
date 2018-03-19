#ifndef POINT_INCLUDED
#define POINT_INCLUDED

#include <iostream>
#define EPSILONE 0.00001

class Point
{
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend bool operator<(const Point&, const Point&);
	friend bool operator==(const Point&, const Point&);
	friend bool operator<=(const Point&, const Point&);
	friend bool operator>=(const Point&, const Point&);
	friend double getDistSqrt(const Point&, const Point&);

public:
	Point(double = 0, double = 0);
	Point(const Point&);
	~Point();
	Point& operator=(const Point&);

	double getX() const;
	double getY() const;

	void setX(double);
	void setY(double);


private:
	void copy(const Point&);

private:
	double x, y;

};

bool operator>(const Point&, const Point&);
bool operator!=(const Point&, const Point&);

#endif // !POINT_INCLUDED
