#ifndef RECTANGLE_INCLUDED
#define RECTANGLE_INCLUDED

#include "Shape.h"

class Rectangle :
	public Shape
{
public:
	Rectangle(double = 0, double = 0, double = 0, double = 0, const char* = nullptr);
	Rectangle(Point&, double, double, const char* = nullptr);
	Rectangle(const Rectangle&);
	Rectangle& operator=(const Rectangle&);
	~Rectangle();

//	void setBase(double, double); имаме я от Shape
//	void setBase(const Point&); имаме я от Shape

	void setWidth(double);
	void setHeight(double);
	void setColour(const char*);

//	const Point getBase() const; имаме я от Shape
	double getWidth() const;
	double getHeight() const;
	const char* getColour() const;
	const char* getName() const override;
	void print(std::ostream&) const override;

	void translate(double, double) override;
	bool withinCircle(Point, double) const override;
	bool withinRect(Point, double, double) const override;
	void saveAsSVG(std::ofstream&) const override;
	Shape* clone() const override;

private:
	void copyFrom(const Rectangle&);
	void clear();

private:
	double width;
	double height;
	char* colour;
};

#endif // !RECTANGLE_INCLUDED