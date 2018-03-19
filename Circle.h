#ifndef CIRCLE_INCLUDED
#define CIRCLE_INCLUDED

#include "Rectangle.h"
#include "Shape.h"

class Circle :
	public Shape
{

public:
	Circle(double = 0, double = 0, double = 0, const char* = nullptr);
	Circle(const Point&, double, const char*);
	Circle& operator=(const Circle&);
	Circle(const Circle&);
	virtual ~Circle();


//	base тук е центърът на окръжността

//	void setBase(double, double); имаме я от Shape; 
//	void setBase(const Point&); имаме я от Shape

	void setRadius(double);
	void setColour(const char*);

//	void getBase() const; имаме я от Shape
	double getRadius() const;
	const char* getColour() const;
	const char* getName() const override;
	void print(std::ostream&) const override;

	void translate(double, double) override;
	bool withinCircle(Point, double) const override; /// ne sa razpisani !!!!
	bool withinRect(Point, double, double) const override;
	void saveAsSVG(std::ofstream&) const override;
	Shape* clone() const override;


private:
	void copyFrom(const Circle&);
	void clear();


private:
	double radius;
	char* colour;
};

#endif // !CIRCLE_INCLUDED
